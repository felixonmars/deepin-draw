#include "cdrawtoolfactory.h"
#include "cselecttool.h"
#include "crecttool.h"
#include "cellipsetool.h"
#include "clinetool.h"
#include "ctriangletool.h"
#include "ctexttool.h"
IDrawTool *CDrawToolFactory::Create(EDrawToolMode mode)
{
    IDrawTool *pTool = nullptr;

    switch (mode) {
    case selection:
        pTool = new CSelectTool();
        break;
    case line:
        pTool = new CLineTool();
        break;
    case rectangle:
        pTool = new CRectTool();
        break;
    case ellipse:
        pTool = new CEllipseTool();
        break;
    case triangle:
        pTool = new CTriangleTool ();
        break;
    case text:
        pTool = new CTextTool();
        break;
    default:
        break;

    }

    return pTool;
}