/*
 * Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co.,Ltd.
 *
 * Author:     Ji XiangLong <jixianglong@uniontech.com>
 *
 * Maintainer: WangYu <wangyu@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "cshapemimedata.h"
#include "cgraphicsitem.h"
#include "cgraphicsrectitem.h"
#include "cgraphicsellipseitem.h"
#include "cgraphicslineitem.h"
#include "cgraphicstriangleitem.h"
#include "cgraphicspolygonitem.h"
#include "cgraphicspolygonalstaritem.h"
#include "cgraphicstextitem.h"
#include "cgraphicspenitem.h"
#include "cpictureitem.h"
#include "cdrawscene.h"

//CShapeMimeData::CShapeMimeData(QList<QGraphicsItem *> items)
//{
//    m_itemList.clear();
//    foreach (QGraphicsItem *item, items) {
//        CGraphicsItem *pBzItem = dynamic_cast<CGraphicsItem *>(item);
//        if (pBzItem != nullptr && pBzItem->isBzItem()) {
//            CGraphicsItem *pNew = pBzItem->creatSameItem();
//            if (pNew != nullptr) {
//                m_itemList.append(pNew);
//            }
//        }
//    }
//}

CShapeMimeData::CShapeMimeData(const CGroupBzItemsTreeInfo &itemsTreeInfo):
    QMimeData(), treeInfo(itemsTreeInfo)
{
}
CShapeMimeData::~CShapeMimeData()
{
    PageScene::releaseBzItemsTreeInfo(treeInfo);
}

bool CShapeMimeData::hasFormat(const QString &mimetype) const
{
    if (mimetype == "drawItems") {
        return true;
    }
    return false;
}

//QList<CGraphicsItem *> CShapeMimeData::itemList() const
//{
//    return m_itemList;
//}

//QList<CGraphicsItem *> CShapeMimeData::creatCopyItems() const
//{
//    QList<CGraphicsItem *> retList;
//    foreach (QGraphicsItem *item, m_itemList) {
//        CGraphicsItem *pBzItem = dynamic_cast<CGraphicsItem *>(item);
//        if (pBzItem != nullptr && pBzItem->isBzItem()) {
//            CGraphicsItem *pNew = pBzItem->creatSameItem();
//            if (pNew != nullptr) {
//                retList.append(pNew);
//            }
//        }
//    }
//    return retList;
//}

CGroupBzItemsTreeInfo CShapeMimeData::itemsTreeInfo()
{
    return treeInfo;
}
