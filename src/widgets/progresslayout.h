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
#ifndef PROGRESSLAYOUT_H
#define PROGRESSLAYOUT_H

#include <QHBoxLayout>
#include <DProgressBar>
#include <DBlurEffectWidget>
#include <DLabel>
#include <DWidget>

DWIDGET_USE_NAMESPACE

class ProgressLayout: public DBlurEffectWidget
{

    Q_OBJECT
public:
    explicit ProgressLayout(/*DBlurEffectWidget*/QWidget *parent = nullptr);
    ~ProgressLayout();
    void setRange(int start, int end);
    void setProgressValue(int value);
    void showInCenter(DWidget *w);
    void setText(const QString &str);
    void delayClose();

    void reset();

    void setAutoFillSubText(bool b);
    //bool isAutoFillSubText() const;
    void setSubText(const QString &str);


    QVBoxLayout *m_progressVBoxLayout;
    DLabel *m_label;
    DLabel *m_progressLabel;
    DProgressBar *m_progressbar;
    int m_start;
    int m_end;
    QString     m_subText;
    bool        m_autoFillSubText = true;

};

#endif // PROGRESSLAYOUT_H
