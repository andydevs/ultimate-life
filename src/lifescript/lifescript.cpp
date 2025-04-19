#include <lifescript/lifescript.h>
#include <LifeScriptLexer.h>
#include <LifeScriptParser.h>
#include <antlr4-runtime.h>
#include <fstream>

using namespace ul::ls;
using namespace std;

void LifeScript::__instantiatePrefab(ul::Grid& grid, LSElem& elem)
{
    if (!m_prefabs.count(elem.prefab_name))
    {
        std::stringstream s;
        s << "Unrecognized prefab type: " << elem.prefab_name << " out of types";
        for (auto &&e : m_prefabs)
        {
            s << " " << e.first;
        }
        throw s;
    }
    vector<LSElem> subelems = m_prefabs.at(elem.prefab_name);
    int x = elem.elem_cell.first;
    int y = elem.elem_cell.second;
    for (LSElem sube : subelems)
    {
        if (sube.prefabbed)
        {
            LSElem ne(sube);
            ne.elem_cell.first += x;
            ne.elem_cell.second += y;
            __instantiatePrefab(grid, ne);
        }
        else
        {
            grid.aliven(x + sube.elem_cell.first, y + sube.elem_cell.second);
        }
    }
}

void LifeScript::instantiate(ul::Grid& g) 
{
    for (LSElem elem: m_elems)
    {        
        if (elem.prefabbed)
        {
            __instantiatePrefab(g, elem);
        }
        else
        {
            g.aliven(elem.elem_cell.first, elem.elem_cell.second);
        }
    }
}

int LifeScript::grid_property(const string& name, int default_value) 
{ 
    if (m_grid_config.count(name)) 
    {
        return m_grid_config.at(name);
    }
    else 
    {
        return default_value;
    }
};

void LifeScript::set_grid_property(const string& name, int value) 
{
    m_grid_config.insert_or_assign(name, value);
};

void LifeScript::add_prefab(const string& name, vector<LSElem>& elems) 
{
    m_prefabs.insert_or_assign(name, elems);
};

void LifeScript::add_elem(LSElem elem) 
{
    m_elems.push_back(elem);
};

// ------------------------------------------------ Prefabdef Visitor DEF -------------------------------------------------

std::vector<LSElem>& PrefabdefVisitor::elems() { return m_elems; }

any PrefabdefVisitor::visitPrefelems(LifeScriptParser::PrefelemsContext *context)
{
    for (antlr4::tree::ParseTree *elem : context->children) 
    {
        LSElem lcelem = any_cast<LSElem>(elem->accept(this));
        m_elems.push_back(lcelem);
    }
    return nullopt;
}

any PrefabdefVisitor::visitRelprefab(LifeScriptParser::RelprefabContext *context)
{
    LSElem elem;
    elem.prefabbed = true;
    elem.prefab_name = context->IDENTIFIER()->getText();
    LSElem cellem = any_cast<LSElem>(visitRelcell(context->relcell()));
    elem.elem_cell = cellem.elem_cell;
    return elem;
}

any PrefabdefVisitor::visitRelcell(LifeScriptParser::RelcellContext *context)
{
    LSElem elem;
    elem.prefabbed = false;
    elem.elem_cell = cell(
        stoi(context->RELNUM(0)->getText()),
        stoi(context->RELNUM(1)->getText())
    );
    return elem;
}


// ------------------------------------------------ LifeScript Visitor DEF ------------------------------------------------

LifeScriptConverterVisitor::LifeScriptConverterVisitor(LifeScript& ls): m_ls(ls) {}

any LifeScriptConverterVisitor::visitGridstmt(LifeScriptParser::GridstmtContext *context)
{
    std::string property_name = context->IDENTIFIER()->getText();
    int property_value = stoi(context->ABSNUM()->getText());
    m_ls.set_grid_property(property_name, property_value);
    return nullopt;
}

any LifeScriptConverterVisitor::visitPrefdef(LifeScriptParser::PrefdefContext *context)
{
    std::string prefab_name = context->IDENTIFIER()->getText();
    PrefabdefVisitor prefab_visitor;
    context->prefelems()->accept(&prefab_visitor);
    m_ls.add_prefab(prefab_name, prefab_visitor.elems());
    return nullopt;
};

any LifeScriptConverterVisitor::visitAbsprefab(LifeScriptParser::AbsprefabContext *context)
{
    LSElem elem;
    elem.prefabbed = true;
    elem.prefab_name = context->IDENTIFIER()->getText();
    elem.elem_cell = cell(
        stoi(context->abscell()->ABSNUM(0)->getText()),
        stoi(context->abscell()->ABSNUM(1)->getText())
    );
    m_ls.add_elem(elem);
    return nullopt;
}

any LifeScriptConverterVisitor::visitAbscell(LifeScriptParser::AbscellContext *context)
{
    LSElem elem;
    elem.prefabbed = false;
    elem.elem_cell = cell(
        stoi(context->ABSNUM(0)->getText()),
        stoi(context->ABSNUM(1)->getText())
    );
    m_ls.add_elem(elem);
    return nullopt;
}

// ----------------------------------------------- READSCRIPT DEF ----------------------------------------------

LifeScript ul::ls::readScript(string& filename)
{
    // Open script file
    ifstream script(filename);
    if (!script.is_open()) {
        stringstream s;
        s << "ERROR Cannot open file " << filename;
        throw s;
    };

    // Parse using ANTLR
    antlr4::ANTLRInputStream input(script);
    LifeScriptLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    LifeScriptParser parser(&tokens);

    // Convert to LifeConfig
    LifeScript config;
    LifeScriptConverterVisitor visitor(config);
    parser.script()->accept(&visitor);

    // Return LifeConfig
    return config;
}