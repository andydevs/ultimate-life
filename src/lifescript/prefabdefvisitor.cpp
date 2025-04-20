#include <lifescript/prefabdefvisitor.h>

using namespace ul::ls;
using namespace std;

vector<LSElem>& PrefabdefVisitor::elems() { return m_elems; }

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
