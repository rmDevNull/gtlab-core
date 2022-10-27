/* GTlab - Gas Turbine laboratory
 * Source File:
 * copyright 2009-2015 by DLR
 *
 *  Created on: 30.07.2015
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#ifndef GTSETTINGSITEM_H
#define GTSETTINGSITEM_H

#include <QVariant>

/**
 * @brief The GtSettingsItem class
 */
class GtSettingsItem
{
    friend class GtAbstractSettings;

public:
    /**
     * @brief Returns identification string of settings item
     * @return identification string
     */
    const QString& ident() const;

    /**
     * @brief Returns initial setting
     * @return initial setting
     */
    const QVariant& initValue() const;

    /**
     * @brief Sets the value of the setting
     */
    void setValue(const QVariant& value);

    /**
     * @brief Retrieves the value of the setting
     *
     * Note, of the settings value could not be read from the global settings
     * Object, the init value will be returned.
     */
    QVariant getValue() const;

protected:
    /**
     * @brief GtSettingsItem
     * @param ident
     * @param initVal
     */
    explicit GtSettingsItem(const QString& ident,
                            const QVariant& initVal = QVariant());

private:
    /// settings item identification string
    QString m_ident;

    /// initial value for settings item
    QVariant m_initValue;

};

#endif // GTSETTINGSITEM_H
