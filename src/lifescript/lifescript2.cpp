#include <lifescript/lifescript2.h>
#include <fstream>

using namespace ul::ls;
using namespace std;


void LifeScript2::foreach_cell(CellFunctional& f)
{
    for (LSElem elem : m_elems) 
    {
        if (elem.prefabbed)
        {
            __foreach_prefab(elem, f);
        }
        else
        {
            f.receive(elem.elem_cell);
        }
    }
}


void LifeScript2::__foreach_prefab(LSElem& elem, CellFunctional& f)
{
    // Lookup prefab
    if (!m_prefabs.count(elem.prefab_name))
    {
        std::stringstream s;
        s << "Unrecognized prefab: " << elem.prefab_name << " out of defs";
        for (auto &&e : m_prefabs)
        {
            s << " " << e.first;
        }
        throw s;
    }
    vector<LSElem> sub_elems = m_prefabs.at(elem.prefab_name);

    // Iterate through each element
    int x = elem.elem_cell.first;
    int y = elem.elem_cell.second;
    for (LSElem sub_elem : sub_elems) 
    {
        LSElem offsetted_elem(sub_elem);
        offsetted_elem.elem_cell.first += x;
        offsetted_elem.elem_cell.second += y;
        if (sub_elem.prefabbed)
        {
            __foreach_prefab(offsetted_elem, f);
        }
        else
        {
            f.receive(offsetted_elem.elem_cell);
        }
    }
}

int LifeScript2::grid_property(const string& name, int default_value) 
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

void LifeScript2::set_grid_property(const string& name, int value) 
{
    m_grid_config.insert_or_assign(name, value);
};

void LifeScript2::add_prefab(const string& name, vector<LSElem>& elems) 
{
    m_prefabs.insert_or_assign(name, elems);
};

void LifeScript2::add_elem(LSElem elem) 
{
    m_elems.push_back(elem);
};