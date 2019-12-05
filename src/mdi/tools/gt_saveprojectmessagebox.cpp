/* GTlab - Gas Turbine laboratory
 * Source File:
 * copyright 2009-2017 by DLR
 *
 *  Created on: 08.12.2017
 *  Author: Jens Schmeink (AT-TWK)
 *  Tel.: +49 2203 601 2191
 */
#include <QIcon>
#include "gt_application.h"

#include "gt_saveprojectmessagebox.h"

GtSaveProjectMessageBox::GtSaveProjectMessageBox(QString text,
                                                 QWidget* parent) :
    QMessageBox(parent)
{
    setIcon(QMessageBox::Question);
    setWindowTitle(tr("Save Project"));
    setWindowIcon(gtApp->icon("saveProjectIcon_16.png"));

    if (text.isEmpty())
    {
        setText(tr("Found unsaved project.\nDo you want to ") +
                tr("save all your changes before closing GTlab?"));
    }
    else
    {
        setText(text);
    }

    setStandardButtons(QMessageBox::Yes | QMessageBox::No |
                       QMessageBox::Cancel);
    setDefaultButton(QMessageBox::Cancel);
}

