#include "cpenwidget.h"

#include <QHBoxLayout>
#include <QDebug>


#include "widgets/bordercolorbutton.h"
#include "widgets/seperatorline.h"
#include "widgets/toolbutton.h"
#include "widgets/csidewidthwidget.h"
#include "widgets/cpushbutton.h"
#include "utils/configsettings.h"
#include "utils/global.h"

const int BTN_SPACNT = 10;

CPenWidget::CPenWidget(QWidget *parent)
    : DWidget(parent)
{
    initUI();
    initConnection();
}

CPenWidget::~CPenWidget()
{

}

void CPenWidget::initUI()
{
    QLabel *strokeLabel = new QLabel(this);
    strokeLabel->setObjectName("StrokeLabel");
    strokeLabel->setText(tr("颜色"));

    m_strokeButton = new BorderColorButton(this);

    SeperatorLine *sep1Line = new SeperatorLine(this);

    QLabel *lineTypeLabel = new QLabel(this);
    lineTypeLabel->setObjectName("LineType");
    lineTypeLabel->setText(tr("类型"));

    QMap<CPushButton::CButtonSattus, QString> pictureMap;

    pictureMap[CPushButton::Normal] = QString(":/theme/light/images/attribute/line tool_normal.svg");
    pictureMap[CPushButton::Hover] = QString(":/theme/light/images/attribute/line tool_hover.svg");
    pictureMap[CPushButton::Press] = QString(":/theme/light/images/attribute/line tool_press.svg");
    pictureMap[CPushButton::Active] = QString(":/theme/light/images/attribute/line tool_checked.svg");
    m_straightline = new CPushButton(pictureMap, this);
    m_actionButtons.append(m_straightline);


    pictureMap[CPushButton::Normal] = QString(":/theme/light/images/attribute/arrow tool_normal.svg");
    pictureMap[CPushButton::Hover] = QString(":/theme/light/images/attribute/arrow tool_hover.svg");
    pictureMap[CPushButton::Press] = QString(":/theme/light/images/attribute/arrow tool_press.svg");
    pictureMap[CPushButton::Active] = QString(":/theme/light/images/attribute/arrow tool_checked.svg");
    m_arrowline = new CPushButton(pictureMap, this);
    m_actionButtons.append(m_arrowline);

    QLabel *lwLabel = new QLabel(this);
    lwLabel->setObjectName("BorderLabel");
    lwLabel->setText(tr("描边粗细"));

    m_sideWidthWidget = new CSideWidthWidget(this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->addStretch();
    layout->addWidget(lineTypeLabel);
    layout->addWidget(m_straightline);
    layout->addWidget(m_arrowline);
    layout->setSpacing(BTN_SPACNT);
    layout->addWidget(m_strokeButton);
    layout->addWidget(strokeLabel);

    layout->addWidget(sep1Line, 0, Qt::AlignCenter);

    layout->addWidget(lwLabel);
    layout->addWidget(m_sideWidthWidget);
    layout->addStretch();
    setLayout(layout);
}

void CPenWidget::initConnection()
{
    connect(m_strokeButton, &BorderColorButton::btnCheckStateChanged, this, [ = ](bool show) {
        showColorPanel(DrawStatus::Stroke, cursor().pos(), show);
    });

    connect(m_straightline, &CPushButton::buttonClick, [this]() {
        clearOtherSelections(m_straightline);
    });

    connect(m_arrowline, &CPushButton::buttonClick, [this]() {
        clearOtherSelections(m_arrowline);
    });
}

void CPenWidget::clearOtherSelections(CPushButton *clickedButton)
{
    foreach (CPushButton *button, m_actionButtons) {
        if (button->isChecked() && button != clickedButton) {
            button->setChecked(false);
            return;
        }
    };
}
