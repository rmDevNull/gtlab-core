/* GTlab - Gas Turbine laboratory
 * Source File: gt_propertyobjectlinkitem.cpp
 * copyright 2009-2016 by DLR
 *
 *  Created on: 15.02.2016
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#include "gt_objectlinkproperty.h"
#include "gt_propertyobjectlinkeditor.h"

#include "gt_propertyobjectlinkitem.h"

GtPropertyObjectLinkItem::GtPropertyObjectLinkItem()
{
}

QVariant
GtPropertyObjectLinkItem::data(int column, int role) const
{
    if (objectLinkProperty() == Q_NULLPTR)
    {
        return QVariant();
    }

    if (column < 0 || column >= 3)
    {
        return QVariant();
    }

    if (column == 0)
    {
        return GtPropertyItem::data(column, role);
    }

    if (m_property == Q_NULLPTR)
    {
        return QVariant();
    }

    switch (role)
    {
        case Qt::DisplayRole:
        case Qt::EditRole:
        {
            if (column == 2)
            {
                const QString uuid = objectLinkProperty()->linkedObjectUUID();

                if (scope() == Q_NULLPTR)
                {
                    return QVariant();
                }

                GtObject* linkedObject = scope()->getObjectByUuid(uuid);

                if (linkedObject == Q_NULLPTR)
                {
                    return QStringLiteral("-");
                }

                return linkedObject->objectName();
            }
        }
    }

    return GtPropertyItem::data(column, role);
}

bool
GtPropertyObjectLinkItem::setData(int column, const QVariant& value,
                                  GtObject* obj, int role)
{
    if (column == 0)
    {
        GtPropertyItem::setData(column, value, obj, role);
        return true;
    }

    if (column != 2)
    {
        return false;
    }

    if (role != Qt::EditRole)
    {
        return false;
    }

    return GtPropertyItem::setData(column, value, obj, role);
}

GtObjectLinkProperty*
GtPropertyObjectLinkItem::objectLinkProperty() const
{
    return qobject_cast<GtObjectLinkProperty*>(m_property);
}

QWidget*
GtPropertyObjectLinkItem::editorWidget(
    QWidget* parent,
    const GtPropertyValueDelegate* /*delegate*/) const
{
    GtPropertyObjectLinkEditor* e = new GtPropertyObjectLinkEditor(parent);

    return e;
}

void
GtPropertyObjectLinkItem::setEditorData(QWidget* editor,
                                        QVariant& /*var*/) const
{
    if (objectLinkProperty() == Q_NULLPTR)
    {
        return;
    }

    GtPropertyObjectLinkEditor* e =
        static_cast<GtPropertyObjectLinkEditor*>(editor);

    e->setScope(scope());
    e->setObjectLinkProperty(objectLinkProperty());
}

void
GtPropertyObjectLinkItem::setModelData(QWidget* /*editor*/,
                                       QAbstractItemModel* /*model*/,
                                       const QModelIndex& /*index*/) const
{
    // nothing to do here
}
