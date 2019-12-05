/* GTlab - Gas Turbine laboratory
 * Source File: gt_labelcontainer.h
 * copyright 2009-2016 by DLR
 *
 *  Created on: 21.04.2016
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#ifndef GTLABELCONTAINER_H
#define GTLABELCONTAINER_H

#include <QPointer>

#include "gt_object.h"

class GtProject;
class GtLabel;

/**
 * @brief The GtLabelContainer class
 */
class GtLabelContainer : public GtObject
{
public:
    /**
     * @brief GtLabelContainer
     * @param project
     * @param label
     */
    GtLabelContainer(GtProject* project, GtLabel* label);

    /**
     * @brief project
     * @return
     */
    GtProject* project();

    /**
     * @brief label
     * @return
     */
    GtLabel* label();

    /**
     * @brief isValid
     * @return
     */
    bool isValid();

private:
    /// Project
    QPointer<GtProject> m_project;

    /// Label
    QPointer<GtLabel> m_label;

};

#endif // GTLABELCONTAINER_H
