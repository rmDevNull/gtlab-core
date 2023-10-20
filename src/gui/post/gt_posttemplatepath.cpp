/* GTlab - Gas Turbine laboratory
 *
 * SPDX-License-Identifier: MPL-2.0+
 * SPDX-FileCopyrightText: 2023 German Aerospace Center (DLR)
 * Source File: gt_posttemplatepath.cpp
 *
 *  Created on: 26.04.2016
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#include "gt_posttemplatepath.h"

GtPostTemplatePath::GtPostTemplatePath(const QString& path)
{
    setObjectName(path);
}

QString
GtPostTemplatePath::path()
{
    return objectName();
}
