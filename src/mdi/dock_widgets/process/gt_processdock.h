/* GTlab - Gas Turbine laboratory
 * Source File:
 * copyright 2009-2015 by DLR
 *
 *  Created on: 02.09.2015
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#ifndef GTPROCESSDOCK_H
#define GTPROCESSDOCK_H

#include "gt_dockwidget.h"

#include <QPointer>
#include <QPersistentModelIndex>

#include "gt_command.h"
#include "gt_mdi_exports.h"

class QPushButton;
class QMenu;
class QSignalMapper;
class GtProcessView;
class GtProcessComponentModel;
class GtTreeFilterModel;
class GtSearchWidget;
class GtProcessData;
class GtTask;
class GtCalculator;
class GtObject;
class GtProcessComponent;
class GtPropertyConnection;
class GtRelativeObjectLinkProperty;

/**
 * @brief The GtProcessDock class
 */
class GtProcessDock : public GtDockWidget
{
    Q_OBJECT

public:
    /**
     * @brief GtProcessDock
     */
    Q_INVOKABLE GtProcessDock();

    /** Returns the recommended dock widget area in main windows.
        @return dock widget area */
    virtual Qt::DockWidgetArea getDockWidgetArea();

    /**
     * @brief mapToSource
     * @param index
     * @return
     */
    QModelIndex mapToSource(const QModelIndex& index);

    /**
     * @brief mapFromSource
     * @param index
     * @return
     */
    QModelIndex mapFromSource(const QModelIndex& index);

    /**
     * @brief Returns pointer to process data object.
     * @return Process data object
     */
    GtProcessData* processData();


    /**
     * @brief searches for a copy of certain property connection within a
     * list of all copies
     * @param original connection
     * @param copied connections
     * @return
     */
    GT_MDI_EXPORT static GtPropertyConnection* findConnectionCopy(
        GtPropertyConnection* origCon,
        QList<GtPropertyConnection*> newCons);

    /**
     * @brief updates a certain property connection to new values
     * regarding target and source uuids/properties in case of a copy process
     * @param original connection
     * @param copied conneciton
     * @param original task
     * @param copied task
     * @return
     */
    GT_MDI_EXPORT static bool updateConnectionProperties(
        GtPropertyConnection* origCon,
        GtPropertyConnection* copyCon,
        GtTask* orig, GtTask* copy);

    /**
     * @brief Updates all relative object links in a copied object based on
     * the original object
     * @param original object
     * @param copied object
     * @return
     */
    GT_MDI_EXPORT static bool updateRelativeObjectLinks(GtObject* orig,
                                                        GtObject* copy);

    /**
     * @brief searches for an equivalent object in a new task
     * (after a copy process) in order to updated property connections
     * @param copied task
     * @param otiginal object from original task
     * @return
     */
    GT_MDI_EXPORT static GtObject* findEquivalentObject(GtObject *parent,
            GtObject* origObj);

    /**
     * @brief returns the highest parent object of type GtTask of the
     * considered task
     * @param task
     * @return
     */
    GT_MDI_EXPORT static GtTask* highestParentTask(GtTask* childTask);

    /**
     * @brief returns the highest parent object of type GtTask of the
     * considered calculator
     * @param calculator
     * @return
     */
    GT_MDI_EXPORT static GtTask* highestParentTask(GtCalculator* childCalc);

    /**
     * @brief returns the highest parent object of type GtTask of the
     * considered process component
     * @param process component
     * @return
     */
    GT_MDI_EXPORT static GtTask* highestParentTask(GtProcessComponent*
                                                   childComp);

    /**
     * @brief Returns all property connections which will be kept in case
     * that the considered task will be cut/moved/copied
     * @param task
     * @return
     */
    GT_MDI_EXPORT static QList<GtPropertyConnection*>
    internalPropertyConnections(GtTask* task);

    /**
     * @brief Returns all property connections which will be kept in case
     * that the considered process component will be cut/moved/copied
     * @param process component
     * @return
     */
    GT_MDI_EXPORT static QList<GtPropertyConnection*>
    internalPropertyConnections(GtProcessComponent* pComp);

    /**
     * @brief Returns all property connections which will be lost in case
     * that the considered calculator will be cut/moved/copied
     * @param task
     * @return
     */
    GT_MDI_EXPORT static QList<GtPropertyConnection*>
    lostPropertyConnections(GtTask* task);

    /**
     * @brief Returns all property connections which will be lost in case
     * that the considered calculator will be cut/moved/copied
     * @param calculator
     * @return
     */
    GT_MDI_EXPORT static QList<GtPropertyConnection*>
    lostPropertyConnections(GtCalculator* calc);

    /**
     * @brief Returns all property connections which will be lost in case
     * that the considered processcomponent
     * @param process component
     * @return
     */
    GT_MDI_EXPORT static QList<GtPropertyConnection*>
    lostPropertyConnections(GtProcessComponent* pComp);

    /**
     * @brief Returns all property connections related to the considered task
     * @param task
     * @return
     */
    GT_MDI_EXPORT static QList<GtPropertyConnection*>
    relatedPropertyConnections(GtTask* task);

    /**
     * @brief Returns all property connections related to the considered
     * calculator
     * @param calculator
     * @return
     */
    GT_MDI_EXPORT static QList<GtPropertyConnection*>
    relatedPropertyConnections(GtCalculator* calc);

    /**
     * @brief Returns all property connections related to the considered
     * process component
     * @param calculator
     * @return
     */
    GT_MDI_EXPORT static QList<GtPropertyConnection*>
    relatedPropertyConnections(GtProcessComponent* comp);

    /**
     * @brief Standardized output messages for lost property connections in
     * case of cut/copy/move of process components
     * @param lost connections
     */
    GT_MDI_EXPORT static void  setOffLostConnectionWarnings(
            QList<GtPropertyConnection*> lostCons,
            GtTask* highestParent);

public slots:
    /**
     * @brief copies process element at index
     * @param index
     */
    void copyElement(const QModelIndex& index);

    /**
     * @brief renameElement open texteditor to rename the object which is
     * selected in the process view
     */
    void renameElement();

    /**
     * @brief clones process element at index
     * @param index
     */
    void cloneElement(const QModelIndex& index);

    /**
     * @brief cuts process element at index
     * @param index
     */
    void cutElement(const QModelIndex& index);

    /**
     * @brief deletes process elements at indexes
     * @param indexes
     */
    void deleteProcessElements(const QList<QModelIndex>& indexList);

    /**
     * @brief pastes process element at index
     * @param index
     */
    void pasteElement(GtObject* parent);

    /**
     * @brief pasteElement
     * @param obj
     * @param parent
     */
    void pasteElement(GtObject* obj, GtObject* parent);

    /**
     * @brief pasteElement
     * @param parentIndex
     */
    void pasteElement(const QModelIndex& parentIndex);

    /**
     * @brief sets skip status to calculator at index
     * @param index
     */
    void skipCalculator(const QModelIndex& index, bool skip = true);

    /**
     * @brief sets skip status to calculators at indexes
     * @param index
     */
    void skipCalculator(const QList<QModelIndex>& indexList, bool skip = true);

    /**
     * @brief sets skip status to calculator
     * @param calculator
     */
    void skipCalculator(GtCalculator* calc, bool skip = true);

protected:
    /** Event called after current project has changed.
        @param new current project */
    virtual void projectChangedEvent(GtProject* project);

private:
    /// Button to run selected process
    QPushButton* m_runButton;

    /// Button to add a new element to process control environment
    QPushButton* m_addElementButton;

    /// Tree view
    GtProcessView* m_view;

    /// model
    GtProcessComponentModel* m_model;

    /// model
    QPointer<GtTreeFilterModel> m_filterModel;

    /// Search widget
    GtSearchWidget* m_search;

    /// Root index
    QPersistentModelIndex m_rootIndex;

    /// Pointer to process data of current project
    QPointer<GtProcessData> m_processData;

    /// Pointer to current process
    QPointer<GtTask> m_currentProcess;

    /// Pointer to current project
    QPointer<GtProject> m_project;

    /// Command
    GtCommand m_command;

    /// mapper for action signals
    QSignalMapper* m_actionMapper;

    /**
     * @brief setCurrentProcess
     * @param process
     */
    void setCurrentProcess(GtTask* process = Q_NULLPTR);

    /**
     * @brief addTask
     */
    void addEmptyTaskToRoot();

    /**
     * @brief addCalculator
     */
    void addCalculator();

    /**
     * @brief Opens task wizard to select new task.
     */
    void addTask();

    /**
     * @brief findRootTaskHelper
     * @param obj
     * @return
     */
    GtTask* findRootTaskHelper(GtObject* obj);

    /**
     * @brief isReady
     * @param comp
     * @return
     */
    bool componentIsReady(GtProcessComponent* comp);

    /**
     * @brief calcByModelIndex
     * @param index
     * @return
     */
    GtCalculator* calcByModelIndex(QModelIndex index);

    /**
     * @brief Updates property connections in a copied object based on the
     *  information contained in the original object
     * @param orig
     * @param copy
     * @return
     */
    bool mapPropertyConnections(GtTask* orig,
                                GtTask* copy);

    /**
     * @brief Updates relative object link properties in a copied object based
     * on the information contained in the original object
     * @param original parent object
     * @param copied parent object
     * @param clone of copied parent object
     * @param parent object of considered property
     * @param considered property
     * @return
     */
    static bool mapRelativeObjectLink(GtObject* orig, GtObject* copy,
                               GtObject* copyClone, GtObject* obj,
                               GtRelativeObjectLinkProperty* relLink);

    /**
     * @brief Updates list of last used process elements.
     * @param str Last used process element class name.
     */
    void updateLastUsedElementList(const QString& str);

    /**
     * @brief Generates menu based on list of last used process elements.
     * @param menu Parent menu.
     * @param isRoot Identifier whether element menu should be generated for a
     * root component.
     */
    void generateLastUsedElementMenu(QMenu* menu, bool isRoot);

    /**
     * @brief deleteProcessComponent
     * @param pComp
     */
    void deleteProcessComponent(GtObject* obj);

private slots:
    /**
     * @brief filterData
     * @param val
     */
    void filterData(const QString& val);

    /**
     * @brief updateButtons
     * @param obj
     */
    void updateButtons(GtObject* obj = Q_NULLPTR);

    /**
     * @brief updateRunButton
     * @param str
     * @param process
     */
    void updateRunButton();

    /**
     * @brief onProcessDestroyed
     */
    void onProcessDestroyed();

    /**
     * @brief onCurrentChanged
     * @param current
     * @param previous
     */
    void onCurrentChanged(const QModelIndex& current,
                          const QModelIndex& previous = QModelIndex());

    /**
     * @brief onClicked
     * @param index
     */
    void onClicked(const QModelIndex& index);

    /**
     * @brief onDoubleClicked
     * @param index
     */
    void onDoubleClicked(const QModelIndex& index);

    /**
     * @brief runProcess
     */
    void runProcess();

    /**
     * @brief Terminates current task.
     */
    void terminateProcess();

    /**
     * @brief addElement
     */
    void addElement();

    /**
     * @brief customContextMenu
     * @param pos
     */
    void customContextMenu(const QPoint& pos);

    /**
     * @brief processContextMenu
     * @param obj
     */
    void processContextMenu(GtTask* obj, const QModelIndex& index);

    /**
     * @brief calculatorContextMenu
     * @param obj
     */
    void calculatorContextMenu(GtCalculator* obj, const QModelIndex& index);

    /**
     * @brief multiSelectionContextMenu
     * @param indexList
     */
    void multiSelectionContextMenu(QList<QModelIndex> indexList);

    /**
     * @brief configCalculator
     * @param calc
     */
    void configCalculator(GtCalculator* calc);

    /**
     * @brief Opens the task configuration wizard.
     * @param task Task for configuration.
     */
    void configTask(GtTask* task);

    /**
     * @brief resetModel
     */
    void resetModel();

    /**
     * @brief Opens a connection editor.
     * @param Model index.
     */
    void openConnectionEditor(const QModelIndex& index);

    /**
     * @brief onProcessQueueChange
     */
    void onProcessQueueChange();

    /**
     * @brief onRowsAboutToBeMoved
     */
    void onRowsAboutToBeMoved();

    /**
     * @brief onRowsMoved
     */
    void onRowsMoved();

    /**
     * @brief Called after current task object has changes.
     * @param Changed object pointer.
     */
    void onTaskDataChanged(GtObject* obj);

    /**
     * @brief Called after action was triggered.
     * @param obj Triggered aciton
     */
    void actionTriggered(QObject* obj);

signals:
    /**
     * @brief selectedObjectChanged
     */
    void selectedObjectChanged(GtObject*);
};

#endif // GTPROCESSDOCK_H
