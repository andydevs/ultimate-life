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
    int x = elem.cell.first;
    int y = elem.cell.second;
    for (LCElem sube : subelems)
    {
        if (sube.prefabbed)
        {
            LCElem ne(sube);
            ne.cell.first += x;
            ne.cell.second += y;
            __instantiatePrefab(grid, ne);
        }
        else
        {
            grid.aliven(x + sube.cell.first, y + sube.cell.second);
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
            g.aliven(elem.cell.first, elem.cell.second);
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

// ----------------------------------------------- OPERATION DEF -----------------------------------------------

const int LC_OP_GRIDSTMT = 1;
const int LC_OP_PREFABDEF = 2;
const int LC_OP_ELEM = 4;

void LCOp::apply(LifeConfig& cfg)
{
    switch (lcoptype)
    {
    case LC_OP_GRIDSTMT:
        cfg.set_grid_property(property_name, property_value);
        break;
    case LC_OP_PREFABDEF:
        cfg.add_prefab(prefab_name, prefab_elems);
        break;
    case LC_OP_ELEM:
        cfg.add_elem(elem);
        break;
    default:
        break;
    }
}

// ------------------------------------------------ VISITOR DEF ------------------------------------------------

any LifeConfigVisitor::visitScript(lifescriptParser::ScriptContext *context)
{
    LifeConfig lc;
    for (int i = 0; i < context->children.size(); ++i) {
        LCOp p = any_cast<LCOp>(context->children[i]->accept(this));
        p.apply(lc);
    }
    return lc;
}

any LifeConfigVisitor::visitGridstmt(lifescriptParser::GridstmtContext *context)
{
    LCOp p;
    p.lcoptype = LC_OP_GRIDSTMT;
    p.property_name = context->IDENTIFIER()->getText();
    p.property_value = stoi(context->ABSNUM()->getText());
    return p;
}

any LifeConfigVisitor::visitPrefdef(lifescriptParser::PrefdefContext *context)
{
    LCOp p;
    p.lcoptype = LC_OP_PREFABDEF;
    p.prefab_name = context->IDENTIFIER()->getText();
    p.prefab_elems = any_cast<vector<LCElem>>(visitPrefelems(context->prefelems()));
    return p;
};

any LifeConfigVisitor::visitAbsprefab(lifescriptParser::AbsprefabContext *context)
{
    LCOp p;
    p.lcoptype = LC_OP_ELEM;
    p.elem.prefabbed = true;
    p.elem.prefab_name = context->IDENTIFIER()->getText();
    p.elem.cell = any_cast<LCOp>(visitAbscell(context->abscell())).elem.cell;
    return p;
}

any LifeConfigVisitor::visitAbscell(lifescriptParser::AbscellContext *context)
{
    LCOp p;
    p.lcoptype = LC_OP_ELEM;
    p.elem.prefabbed = false;
    p.elem.cell = cell(
        stoi(context->ABSNUM(0)->getText()),
        stoi(context->ABSNUM(1)->getText())
    );
    return p;
}

any LifeConfigVisitor::visitPrefelems(lifescriptParser::PrefelemsContext *context)
{
    vector<LCElem> elems;
    LCElem elem;
    for (antlr4::tree::ParseTree *e : context->children)
    {
        elems.push_back(any_cast<LCElem>(e->accept(this)));
    }
    return elems;
}

any LifeConfigVisitor::visitRelprefab(lifescriptParser::RelprefabContext *context)
{
    LCElem elem;
    elem.prefabbed = true;
    elem.prefab_name = context->IDENTIFIER()->getText();
    LCElem cellem = any_cast<LCElem>(visitRelcell(context->relcell()));
    elem.cell = cellem.cell;
    return elem;
}

any LifeConfigVisitor::visitRelcell(lifescriptParser::RelcellContext *context)
{
    LCElem elem;
    elem.prefabbed = false;
    elem.cell = cell(
        stoi(context->RELNUM(0)->getText()),
        stoi(context->RELNUM(1)->getText())
    );
    return elem;
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
    LifeConfigVisitor visitor;
    LifeConfig config = any_cast<LifeConfig>(visitor.visitScript(parser.script()));

    // Return LifeConfig
    return config;
}