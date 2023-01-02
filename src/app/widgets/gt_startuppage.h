/* GTlab - Gas Turbine laboratory
 * Source File: gt_startuppage.h
 * copyright 2009-2017 by DLR
 *
 *  Created on: 19.06.2017
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#ifndef GT_STARTUPPAGE_H
#define GT_STARTUPPAGE_H

#include "gt_mdiitem.h"

class QFrame;
class QToolButton;
class QLabel;

/**
 * @brief The GtStartupPage class
 */
class GtStartupPage : public GtMdiItem
{
    Q_OBJECT

public:
    /**
     * @brief GtStartupPage
     */
    Q_INVOKABLE GtStartupPage();

    /**
     * @brief Virtual function to specify item specific icon.
     * @return Object specific icon.
     */
    QIcon icon() const override;

    /**
     * @brief allowsMultipleInstances
     * @return true because the memento viewer can be opened multiple times
     */
    bool allowsMultipleInstances() const override;

public slots:
    /**
     * @brief onThemeChange - handle the change between the GUI theme options
     */
    void onThemeChange();

private slots:
    /**
     * @brief showIndicatorToggled
     * @param val
     */
    void showIndicatorToggled(bool val);

//signals:
//    /**
//     * @brief newProject
//     */
//    void newProject();

//    /**
//     * @brief importProject
//     */
//    void importProject();

//    /**
//     * @brief helpContents
//     */
//    void helpContents();

//    /**
//     * @brief showInfo
//     */
//    void showInfo();

//    /**
//     * @brief openExamplesWidget
//     */
//    void openExamplesWidget();

private:
    /// main frame
    QFrame* m_frame;

//    /// Button to start new project
//    QToolButton* m_newProjBtn;

//    /// Button to open example
//    QToolButton* m_examplesBtn;

//    /// button to open help menu
//    QToolButton* m_helpBtn;

//    /// button to open info menu
//    QToolButton* m_infoBtn;

    /// Placeholder for gtlab logo
    QLabel* m_logoLabel;

    /**
     * @brief initialize widget content
     */
    void initializeTheme();
};

#endif // GT_STARTUPPAGE_H
