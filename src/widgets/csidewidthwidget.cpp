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

#include "csidewidthwidget.h"
#include "drawshape/cdrawparamsigleton.h"
#include "frame/cviewmanagement.h"
#include "frame/cgraphicsview.h"
#include "application.h"
//#include "widgets/dmenucombobox.h"

#include <DGuiApplicationHelper>
#include <DComboBox>

#include <QDebug>

DGUI_USE_NAMESPACE

CSideWidthWidget::CSideWidthWidget(DWidget *parent)
    : DWidget(parent)
    , m_comboxHeight(28)
{
    initUI();
    initConnection();
}

void CSideWidthWidget::setText(const QString &text)
{
    _textLabel->setVisible(!text.isEmpty());
    _textLabel->setText(text);
}

void CSideWidthWidget::setSpace(int space)
{
    m_layout->setSpacing(space);
}

void CSideWidthWidget::setWidth(int width)
{
    if (width >= 0) {
        QString current_px = QString::number(width) + "px";
        m_menuComboBox->setCurrentText(current_px);
        m_maskLable->setVisible(false);
    } else {
        setVaild(false);
    }
}

QComboBox *CSideWidthWidget::menuComboBox()
{
    return m_menuComboBox;
}

QSize CSideWidthWidget::sizeHint() const
{
    return DWidget::sizeHint();
}

void CSideWidthWidget::setVaild(bool vaild)
{
    if (!vaild) {
        m_menuComboBox->setCurrentIndex(-1);
    }
    m_maskLable->setVisible(!vaild);
}

void CSideWidthWidget::initUI()
{
    setWgtAccesibleName(this, "CSideWidthWidget");
    m_layout = new QHBoxLayout(this);
    _textLabel = new DLabel(this);
    m_menuComboBox = new QComboBox(this);
    m_menuComboBox->setFocusPolicy(Qt::NoFocus);
    m_maskLable = new DLabel(m_menuComboBox);
    m_maskLable->setText("— —");
    m_maskLable->move(6, 6);
    m_maskLable->setFixedSize(35, 20);
    m_maskLable->setVisible(true);
    m_maskLable->setFont(m_menuComboBox->font());

    m_menuComboBox->/*setMaximumWidth*/setMinimumWidth(/*100*/90);

    initLineWidthToCombox();
    m_layout->addWidget(_textLabel);
    m_layout->addWidget(m_menuComboBox);
    m_layout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(m_layout);

    _textLabel->hide();
}

void CSideWidthWidget::initConnection()
{
    connect(m_menuComboBox, &QComboBox::currentTextChanged, [ = ](const QString & text) {
        if (text.contains("px")) {
            // 判断并且获取当前线宽度
            bool flag = false;
            int lineWidth = text.trimmed().toLower().replace("px", "").toInt(&flag);

            if (flag) {
                emit widthChanged(lineWidth);
            }
            this->setVaild(true);
        }
    });

    // 设置默认2px的线宽度
    m_menuComboBox->setCurrentIndex(1);
}

void CSideWidthWidget::initLineWidthToCombox()
{
    m_menuComboBox->addItem("0px");
    m_menuComboBox->addItem("1px");
    m_menuComboBox->addItem("2px");
    m_menuComboBox->addItem("4px");
    m_menuComboBox->addItem("8px");
    m_menuComboBox->addItem("10px");
}


