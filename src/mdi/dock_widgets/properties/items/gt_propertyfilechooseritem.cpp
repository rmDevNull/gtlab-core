/* GTlab - Gas Turbine laboratory
 * Source File: gt_propertyfilechooseritem.cpp
 * copyright 2009-2016 by DLR
 *
 *  Created on: 19.05.2016
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#include "gt_filechooserproperty.h"
#include "gt_propertyfilechoosereditor.h"

#include "gt_propertyfilechooseritem.h"

GtPropertyFileChooserItem::GtPropertyFileChooserItem()
{
}

GtFileChooserProperty*
GtPropertyFileChooserItem::fileChooserProperty() const
{
    return qobject_cast<GtFileChooserProperty*>(m_property);
}

QWidget*
GtPropertyFileChooserItem::editorWidget(
        QWidget* parent,
        const GtPropertyValueDelegate* /*delegate*/) const
{
    GtPropertyFileChooserEditor* e = new GtPropertyFileChooserEditor(parent);

    return e;
}

void
GtPropertyFileChooserItem::setEditorData(QWidget* editor,
                                         QVariant& /*var*/) const
{
    GtPropertyFileChooserEditor* e =
        static_cast<GtPropertyFileChooserEditor*>(editor);

    e->setFileChooserProperty(fileChooserProperty());
}

void
GtPropertyFileChooserItem::setModelData(QWidget* /*editor*/,
                                        QAbstractItemModel* /*model*/,
                                        const QModelIndex& /*index*/) const
{
    // nothing to do here
}
