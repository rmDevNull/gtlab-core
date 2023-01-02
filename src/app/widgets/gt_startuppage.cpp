/* GTlab - Gas Turbine laboratory
 * Source File: gt_startuppage.cpp
 * copyright 2009-2017 by DLR
 *
 *  Created on: 19.06.2017
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#include <QIcon>
#include <QFrame>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QToolButton>

#include "gt_application.h"
#include "gt_settings.h"
#include "gt_icons.h"

#include "gt_startuppage.h"

GtStartupPage::GtStartupPage()
{
    setObjectName("Home");

    QVBoxLayout* lay = new QVBoxLayout;
    lay->setContentsMargins(0, 0, 0, 0);
    lay->setSpacing(0);

    m_frame = new QFrame(widget());
    m_frame->setFrameShape(QFrame::StyledPanel);
    m_frame->setFrameShadow(QFrame::Sunken);

    // must be set explicitly otherwise this widget may sometimes not rerecieve
    // the focus and shortcuts etc. wont be handled by main window
    widget()->setFocusPolicy(Qt::StrongFocus);

    QVBoxLayout* frameLay = new QVBoxLayout;

    m_logoLabel = new QLabel;

    frameLay->addWidget(m_logoLabel);
    frameLay->addStretch(1);

//    QGridLayout* gridLay = new QGridLayout;

//    gridLay->addItem(new QSpacerItem(10, 10, QSizePolicy::Minimum,
//                                     QSizePolicy::Expanding), 0, 1);
//    gridLay->addItem(new QSpacerItem(10, 10, QSizePolicy::Minimum,
//                                     QSizePolicy::Expanding), 2, 1);
//    gridLay->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding,
//                                     QSizePolicy::Minimum), 1, 0);
//    gridLay->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding,
//                                     QSizePolicy::Minimum), 1, 2);

//    QGridLayout* btnGridLay = new QGridLayout;

//    QSize iconSize(80, 80);

//    m_newProjBtn = new QToolButton;
//    m_newProjBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//    m_newProjBtn->setIcon(gt::gui::icon::addProject());
//    m_newProjBtn->setIconSize(iconSize);
//    m_newProjBtn->setText(tr("New Project"));
//    btnGridLay->addWidget(m_newProjBtn, 0, 0);

//    m_examplesBtn = new QToolButton;
//    m_examplesBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//    m_examplesBtn->setIcon(gt::gui::icon::examples());
//    m_examplesBtn->setIconSize(iconSize);
//    m_examplesBtn->setText(tr("Examples"));
//    btnGridLay->addWidget(m_examplesBtn, 0, 1);

//    m_helpBtn = new QToolButton;
//    m_helpBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//    m_helpBtn->setIcon(gt::gui::icon::help());
//    m_helpBtn->setIconSize(iconSize);
//    m_helpBtn->setText(tr("Help Contents"));
//    btnGridLay->addWidget(m_helpBtn, 1, 0);

//    m_infoBtn = new QToolButton(widget());
//    m_infoBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//    m_infoBtn->setIcon(gt::gui::icon::info());
//    m_infoBtn->setIconSize(iconSize);
//    m_infoBtn->setText("Info");

//    btnGridLay->addWidget(m_infoBtn, 1, 1);

//    connect(m_newProjBtn, SIGNAL(clicked(bool)), this, SIGNAL(newProject()));
//    connect(m_examplesBtn, SIGNAL(clicked(bool)), this,
//            SIGNAL(openExamplesWidget()));
//    connect(m_helpBtn, SIGNAL(clicked(bool)), this, SIGNAL(helpContents()));
//    connect(m_infoBtn, SIGNAL(clicked(bool)), this, SIGNAL(showInfo()));

//    gridLay->addLayout(btnGridLay, 1, 1);

//    frameLay->addLayout(gridLay);

    m_frame->setLayout(frameLay);

    lay->addWidget(m_frame);

    QHBoxLayout* checkLay = new QHBoxLayout;

    QCheckBox* check = new QCheckBox(tr("Show at Startup"));

    if (gtApp->settings()->showStartupPage())
    {
        check->setChecked(true);
    }

    connect(check, SIGNAL(clicked(bool)), SLOT(showIndicatorToggled(bool)));

    checkLay->addWidget(check);
    checkLay->setContentsMargins(5, 0, 0, 0);

    lay->addLayout(checkLay);

    widget()->setLayout(lay);

    initializeTheme();

    m_logoLabel->setPixmap(gt::gui::pixmap::logo());
    m_logoLabel->setLayoutDirection(Qt::RightToLeft);
}

QIcon
GtStartupPage::icon() const
{
    return gt::gui::icon::infoBlue16();
}

bool
GtStartupPage::allowsMultipleInstances() const
{
    return false;
}

void
GtStartupPage::onThemeChange()
{
    initializeTheme();
}

void
GtStartupPage::showIndicatorToggled(bool val)
{
    gtApp->settings()->setShowStartupPage(val);
}

void
GtStartupPage::initializeTheme()
{
    QString welcomebuttonStyleSheet;

    QString border = "border: 1px solid gray;"
                     "border-radius: 4px;";

    QString size = "min-width: 110px;"
                   "min-height:110px;";

    if (!gtApp->inDarkMode())
    {
        welcomebuttonStyleSheet =  "QAbstractButton { "
                + border +
               "background-color:white;"
                + size +
                "font: bold;}"
               "QAbstractButton:hover{background-color:"
               "rgb(220,235,250)}"
               "QAbstractButton:disabled {background-color:"
               "rgb(240,240,240)}"
               "QAbstractButton:pressed{background-color:"
               "rgb(180,213,246)}";
    }
    else
    {
        welcomebuttonStyleSheet =  "QAbstractButton { "
                + border +
                "background-color:#2d2d2d;" /// the same as 45,45,45 RGB
                + size +
                "font: bold;}"
               "QAbstractButton:hover{background-color:"
               "rgb(180,200,200)}"
               "QAbstractButton:disabled {background-color:"
               "rgb(180,180,180)}"
               "QAbstractButton:pressed{background-color:"
               "rgb(180,213,213)}";
    }

//    m_newProjBtn->setStyleSheet(welcomebuttonStyleSheet);
//    m_helpBtn->setStyleSheet(welcomebuttonStyleSheet);
//    m_examplesBtn->setStyleSheet(welcomebuttonStyleSheet);
//    m_infoBtn->setStyleSheet(welcomebuttonStyleSheet);

    m_frame->setAutoFillBackground(true);
    m_frame->setObjectName(QStringLiteral("frame"));
    m_frame->setAutoFillBackground(true);
    m_frame->setFrameShape(QFrame::Box);
    m_frame->setFrameShadow(QFrame::Raised);

    m_logoLabel->setPixmap(gt::gui::pixmap::logo());
    m_logoLabel->setLayoutDirection(Qt::RightToLeft);

    if (gtApp->inDarkMode())
    {
        m_frame->setStyleSheet("#frame {border-image: "
                             "url(:/pixmaps/startup-background_dark.png)}");
    }
    else
    {
        m_frame->setStyleSheet("#frame {border-image: "
                             "url(:/pixmaps/startup-background.png)}");
    }
}
