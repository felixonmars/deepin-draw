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
#ifndef CPICTURETOOL_H
#define CPICTURETOOL_H

#include "idrawtool.h"
#include "cpictureitem.h"
#include "cdrawscene.h"
#include"widgets/progresslayout.h"
#include "frame/ccentralwidget.h"

#include <DFileDialog>


#include <DWidget>

DWIDGET_USE_NAMESPACE

class CPictureTool: public IDrawTool
{
    Q_OBJECT
public:
    explicit CPictureTool();
    ~CPictureTool();

    QAbstractButton *initToolButton() override;

    DrawAttribution::SAttrisList attributions() override;

    void  registerAttributionWidgets() override;

    void onStatusChanged(EStatus oldStatus, EStatus nowStatus) override;

    DECLAREPRIVATECLASS(CPictureTool)
};


#endif // CPICTURETOOL_H
