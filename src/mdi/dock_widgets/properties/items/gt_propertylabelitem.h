/* GTlab - Gas Turbine laboratory
 * Source File: gt_propertylabelitem.h
 * copyright 2009-2016 by DLR
 *
 *  Created on: 19.04.2016
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#ifndef GTPROPERTYLABELITEM_H
#define GTPROPERTYLABELITEM_H

#include "gt_propertyitem.h"

class GtLabelProperty;

/**
 * @brief The GtPropertyLabelItem class
 */
class GtPropertyLabelItem : public GtPropertyItem
{
    Q_OBJECT

public:
    /**
     * @brief GtPropertyLabelItem
     * @param property
     * @param model
     * @param parent
     */
    Q_INVOKABLE GtPropertyLabelItem();

    /**
     * @brief labelProperty
     * @return
     */
    GtLabelProperty* labelProperty() const;

    /**
     * @brief data
     * @param column
     * @param role
     * @return
     */
    virtual QVariant data(int column, int role) const Q_DECL_OVERRIDE;

    /**
     * @brief editorWidget
     * @return
     */
    virtual QWidget* editorWidget(
        QWidget* parent,
        const GtPropertyValueDelegate* delegate) const Q_DECL_OVERRIDE;

    /**
     * @brief setEditorData
     * @param var
     */
    virtual void setEditorData(QWidget* editor,
                               QVariant& var) const Q_DECL_OVERRIDE;

    /**
     * @brief setModelData
     * @param editor
     * @param model
     */
    virtual void setModelData(QWidget* editor,
                              QAbstractItemModel* model,
                              const QModelIndex& index) const Q_DECL_OVERRIDE;

    /**
     * @brief paint
     * @param painter
     * @param option
     * @return
     */
    void paint(QPainter* painter,
               const QStyleOptionViewItem& option) const Q_DECL_OVERRIDE;

private:
    /**
     * @brief Returns project specific label list.
     * @return Label list.
     */
    QStringList labelList() const;

};

#endif // GTPROPERTYLABELITEM_H
