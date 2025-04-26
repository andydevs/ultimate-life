#include <lifescript/lifescriptvisitor.h>
#include <lifescript/prefabdefvisitor.h>

using namespace ul::script;
using namespace std;

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
