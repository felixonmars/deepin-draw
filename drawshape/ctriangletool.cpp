#include "ctriangletool.h"
#include "cdrawscene.h"
#include "cgraphicstriangleitem.h"
#include "cdrawparamsigleton.h"
#include "cdrawtoolmanagersigleton.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QtMath>

CTriangleTool::CTriangleTool ()
    : IDrawTool (ellipse)
    , m_pTriangleItem(nullptr)
{

}

CTriangleTool::~CTriangleTool()
{

}

void CTriangleTool::mousePressEvent(QGraphicsSceneMouseEvent *event, CDrawScene *scene)
{
    scene->clearSelection();

    m_sPointPress = event->scenePos();
    m_pTriangleItem = new CGraphicsTriangleItem(m_sPointPress.x(), m_sPointPress.y(), 0, 0);
    m_pTriangleItem->setPen(CDrawParamSigleton::GetInstance()->getPen());
    m_pTriangleItem->setBrush(CDrawParamSigleton::GetInstance()->getBrush());
    scene->addItem(m_pTriangleItem);
    m_pTriangleItem->setSelected(true);

    m_bMousePress = true;
}

void CTriangleTool::mouseMoveEvent(QGraphicsSceneMouseEvent *event, CDrawScene *scene)
{
    Q_UNUSED(scene)
    if (m_bMousePress) {
        QPointF pointMouse = event->scenePos();
        QRectF resultRect;
        //按下SHIFT键
        if (m_bShiftKeyPress && !m_bAltKeyPress) {
            QPointF resultPoint = pointMouse;
            qreal w = resultPoint.x() - m_sPointPress.x();
            qreal h = resultPoint.y() - m_sPointPress.y();
            qreal abslength = abs(w) - abs(h);
            if (abslength >= 0.1) {
                if (h >= 0) {
                    resultPoint.setY(m_sPointPress.y() + abs(w));
                } else {
                    resultPoint.setY(m_sPointPress.y() - abs(w));
                }

            } else {
                if (w >= 0) {
                    resultPoint.setX(m_sPointPress.x() + abs(h));
                } else {
                    resultPoint.setX(m_sPointPress.x() - abs(h));
                }
            }
            QRectF rectF(m_sPointPress, resultPoint);
            resultRect = rectF.normalized();

        }
        //按下ALT键
        else if (!m_bShiftKeyPress && m_bAltKeyPress) {

            QPointF point1 = pointMouse;
            QPointF centerPoint = m_sPointPress;
            QPointF point2 = 2 * centerPoint - point1;
            QRectF rectF(point1, point2);
            resultRect = rectF.normalized();
        }
        //ALT SHIFT都按下
        else if (m_bShiftKeyPress && m_bAltKeyPress) {
            QPointF resultPoint = pointMouse;
            qreal w = resultPoint.x() - m_sPointPress.x();
            qreal h = resultPoint.y() - m_sPointPress.y();
            qreal abslength = abs(w) - abs(h);
            if (abslength >= 0.1) {
                if (h >= 0) {
                    resultPoint.setY(m_sPointPress.y() + abs(w));
                } else {
                    resultPoint.setY(m_sPointPress.y() - abs(w));
                }

            } else {
                if (w >= 0) {
                    resultPoint.setX(m_sPointPress.x() + abs(h));
                } else {
                    resultPoint.setX(m_sPointPress.x() - abs(h));
                }
            }

            QPointF point1 = resultPoint;
            QPointF centerPoint = m_sPointPress;
            QPointF point2 = 2 * centerPoint - point1;
            QRectF rectF(point1, point2);
            resultRect = rectF.normalized();

        }
        //都没按下
        else {
            QPointF resultPoint = pointMouse;
            QRectF rectF(m_sPointPress, resultPoint);
            resultRect = rectF.normalized();
        }
        m_pTriangleItem->setRect(resultRect);
    }
}

void CTriangleTool::mouseReleaseEvent(QGraphicsSceneMouseEvent *event, CDrawScene *scene)
{
    Q_UNUSED(scene)
    m_sPointRelease = event->scenePos();
    m_pTriangleItem = nullptr;
    m_bMousePress = false;
}