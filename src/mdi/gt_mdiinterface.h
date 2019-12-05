/* GTlab - Gas Turbine laboratory
 * Source File:
 * copyright 2009-2015 by DLR
 *
 *  Created on: 11.08.2015
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#ifndef GTMDIINTERFACE_H
#define GTMDIINTERFACE_H

#include "gt_mdi_exports.h"

#include <QtPlugin>

#include "gt_objectui.h"

/**
 * @brief The GtMdiInterface class
 */
class GT_MDI_EXPORT GtMdiInterface
{
public:
    /** Virtual destructor to keep compilers happy */
    virtual ~GtMdiInterface() {}

    /**
     * @brief Returns static meta objects of mdi item classes.
     * @return list including meta objects
     */
    virtual QList<QMetaObject> mdiItems() = 0;

    /**
     * @brief Returns static meta objects of dockwidget classes.
     * @return list including meta objects
     */
    virtual QList<QMetaObject> dockWidgets() = 0;

    /**
     * @brief uiItems
     * @return
     */
    virtual QMap<const char*, QMetaObject> uiItems() = 0;

    /**
     * @brief postItems
     * @return
     */
    virtual QList<QMetaObject> postItems() = 0;

    /**
     * @brief postPlots
     * @return
     */
    virtual QList<QMetaObject> postPlots() = 0;

};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(GtMdiInterface,
                    "de.dlr.gtlab.GtMdiInterface/0.1")
QT_END_NAMESPACE

#endif // GTMDIINTERFACE_H
