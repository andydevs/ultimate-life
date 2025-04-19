#include <ultimate_life/lifeconfig.h>
#include <lifescriptLexer.h>
#include <lifescriptParser.h>
#include <antlr4-runtime.h>
#include <fstream>

using namespace ul::lc;
using namespace std;

void LifeConfig::__instantiatePrefab(ul::Grid& grid, LCElem& elem)
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
    vector<LCElem> subelems = m_prefabs.at(elem.prefab_name);
    int x = elem.elem_cell.first;
    int y = elem.elem_cell.second;
    for (LCElem sube : subelems)
    {
        if (sube.prefabbed)
        {
            LCElem ne(sube);
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

void LifeConfig::instantiate(ul::Grid& g) 
{
    for (LCElem elem: m_elems)
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

int LifeConfig::grid_property(const string& name, int default_value) 
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

void LifeConfig::set_grid_property(const string& name, int value) 
{
    m_grid_config.insert_or_assign(name, value);
};

void LifeConfig::add_prefab(const string& name, vector<LCElem>& elems) 
{
    m_prefabs.insert_or_assign(name, elems);
};

void LifeConfig::add_elem(LCElem elem) 
{
    m_elems.push_back(elem);
};

// ------------------------------------------------ Prefabdef Visitor DEF -------------------------------------------------

std::vector<LCElem>& PrefabdefVisitor::elems() { return m_elems; }

any PrefabdefVisitor::visitPrefelems(lifescriptParser::PrefelemsContext *context)
{
    for (antlr4::tree::ParseTree *elem : context->children) 
    {
        LCElem lcelem = any_cast<LCElem>(elem->accept(this));
        m_elems.push_back(lcelem);
    }
    return nullopt;
}

any PrefabdefVisitor::visitRelprefab(lifescriptParser::RelprefabContext *context)
{
    LCElem elem;
    elem.prefabbed = true;
    elem.prefab_name = context->IDENTIFIER()->getText();
    LCElem cellem = any_cast<LCElem>(visitRelcell(context->relcell()));
    elem.elem_cell = cellem.elem_cell;
    return elem;
}

any PrefabdefVisitor::visitRelcell(lifescriptParser::RelcellContext *context)
{
    LCElem elem;
    elem.prefabbed = false;
    elem.elem_cell = cell(
        stoi(context->RELNUM(0)->getText()),
        stoi(context->RELNUM(1)->getText())
    );
    return elem;
}


// ------------------------------------------------ LifeScript Visitor DEF ------------------------------------------------

LifeConfigVisitor::LifeConfigVisitor(LifeConfig& lc): lifescriptBaseVisitor(), m_lc(lc) {}

any LifeConfigVisitor::visitGridstmt(lifescriptParser::GridstmtContext *context)
{
    std::string property_name = context->IDENTIFIER()->getText();
    int property_value = stoi(context->ABSNUM()->getText());
    m_lc.set_grid_property(property_name, property_value);
    return nullopt;
}

any LifeConfigVisitor::visitPrefdef(lifescriptParser::PrefdefContext *context)
{
    std::string prefab_name = context->IDENTIFIER()->getText();
    PrefabdefVisitor prefab_visitor;
    context->prefelems()->accept(&prefab_visitor);
    m_lc.add_prefab(prefab_name, prefab_visitor.elems());
    return nullopt;
};

any LifeConfigVisitor::visitAbsprefab(lifescriptParser::AbsprefabContext *context)
{
    LCElem elem;
    elem.prefabbed = true;
    elem.prefab_name = context->IDENTIFIER()->getText();
    elem.elem_cell = cell(
        stoi(context->abscell()->ABSNUM(0)->getText()),
        stoi(context->abscell()->ABSNUM(1)->getText())
    );
    m_lc.add_elem(elem);
    return nullopt;
}

any LifeConfigVisitor::visitAbscell(lifescriptParser::AbscellContext *context)
{
    LCElem elem;
    elem.prefabbed = false;
    elem.elem_cell = cell(
        stoi(context->ABSNUM(0)->getText()),
        stoi(context->ABSNUM(1)->getText())
    );
    m_lc.add_elem(elem);
    return nullopt;
}

// ----------------------------------------------- READSCRIPT DEF ----------------------------------------------

LifeConfig ul::lc::readScript(string& filename)
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
    lifescriptLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    lifescriptParser parser(&tokens);

    // Convert to LifeConfig
    LifeConfig config;
    LifeConfigVisitor visitor(config);
    parser.script()->accept(&visitor);

    // Return LifeConfig
    return config;
}