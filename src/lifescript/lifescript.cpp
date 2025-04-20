#include <lifescript/lifescript.h>
#include <lifescript/lifescriptvisitor.h>
#include <LifeScriptLexer.h>
#include <LifeScriptParser.h>
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