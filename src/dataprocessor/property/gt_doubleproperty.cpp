/* GTlab - Gas Turbine laboratory
 * Source File: gt_doubleproperty.cpp
 * copyright 2009-2015 by DLR
 *
 *  Created on: 14.10.2015
 *      Author: Carsten Klein (AT-TWK)
 *		  Tel.: +49 2203 601 2859
 */

#include "gt_doubleproperty.h"

GtDoubleProperty::GtDoubleProperty(const QString& ident, const QString& name)
{
    setObjectName(name);

    m_id = ident;
    m_brief = QString();
    m_unitCategory = GtUnit::Category::None;
    m_value = 0.0;
    m_initValue = 0.0;
    m_boundsCheckFlagHi = false;
    m_boundsCheckFlagLow = false;
    m_boundHi = 0.0;
    m_boundLo = 0.0;
}

GtDoubleProperty::GtDoubleProperty(const QString& ident,
                                   const QString& name,
                                   const QString& brief,
                                   const GtUnit::Category &unitCategory,
                                   const double& value)
{
    setObjectName(name);

    m_id = ident;
    m_brief = brief;
    m_unitCategory = unitCategory;
    m_value = value;
    m_initValue = value;
    m_boundsCheckFlagHi = false;
    m_boundsCheckFlagLow = false;
    m_boundHi = 0.0;
    m_boundLo = 0.0;
}


GtDoubleProperty::GtDoubleProperty(const QString& ident,
                                   const QString& name,
                                   const QString& brief,
                                   const GtUnit::Category &unitCategory,
                                   const double lowSideBoundary,
                                   const double highSideBoundary,
                                   const double& value)
{
    setObjectName(name);

    m_id = ident;
    m_brief = brief;
    m_unitCategory = unitCategory;
    m_value = 0.0;
    m_initValue = 0.0;

    if (lowSideBoundary >= highSideBoundary)
    {
        m_boundsCheckFlagHi = false;
        m_boundsCheckFlagLow = false;
        m_boundHi = 0.0;
        m_boundLo = 0.0;
    }
    else
    {
        m_boundsCheckFlagLow = true;
        m_boundsCheckFlagHi = true;
        m_boundLo = lowSideBoundary;
        m_boundHi = highSideBoundary;
    }

    bool success = false;

    setVal(value, &success);

    if (success)
    {
        m_initValue = value;
    }
}

GtDoubleProperty::GtDoubleProperty(const QString& ident,
                                   const QString& name,
                                   const QString& brief,
                                   const GtUnit::Category& unitCategory,
                                   GtDoubleProperty::BoundType boundType,
                                   const double boundary,
                                   const double& value)
{
    setObjectName(name);

    m_id = ident;
    m_brief = brief;
    m_unitCategory = unitCategory;
    m_value = 0.0;
    m_initValue = 0.0;

    if (boundType == GtDoubleProperty::BoundLow)
    {
        m_boundsCheckFlagLow = true;
        m_boundsCheckFlagHi = false;
        m_boundLo = boundary;
        m_boundHi = 0.0;
    }
    else
    {
        m_boundsCheckFlagLow = false;
        m_boundsCheckFlagHi = true;
        m_boundLo = 0.0;
        m_boundHi = boundary;
    }

    bool success = false;

    setVal(value, &success);

    if (success)
    {
        m_initValue = value;
    }
}

QVariant
GtDoubleProperty::valueToVariant(const QString& unit,
                                 bool* success) const
{
    return getVal(unit, success);
}

bool
GtDoubleProperty::setValueFromVariant(const QVariant& val,
                                      const QString& unit,
                                      bool* success)
{
    bool retval = false;

    const double doubleVal = val.toDouble(&retval);

    if (retval)
    {
        setVal(doubleVal, unit, success);

        if (success)
        {
            retval = *success;
        }
    }

    return retval;
}

double
GtDoubleProperty::lowSideBoundary() const
{
    return m_boundLo;
}

double
GtDoubleProperty::highSideBoundary() const
{
    return m_boundHi;
}

double
GtDoubleProperty::convertFrom(const double &value, const QString& unit,
                              bool* success)
{
    GtUnit::Category cat = GtProperty<double>::m_unitCategory;
    GtUnitConverter<double>* conv = GtProperty<double>::m_unitConverter;

    // TODO: test vor invalidation
    return conv->from(cat, unit, value, success);
}

double
GtDoubleProperty::convertTo(const QString& unit, bool* success) const
{
    GtUnit::Category cat = GtProperty<double>::m_unitCategory;
    GtUnitConverter<double>* conv = GtProperty<double>::m_unitConverter;

    return conv->To(cat, unit, m_value, success);
}

bool
GtDoubleProperty::validateValue(const double& value)
{
    if (m_boundsCheckFlagLow)
    {
        if (value < m_boundLo)
        {
            gtWarning() << tr("Invalid value for ") << objectName()
                        << tr(". Value has to be bigger than")
                        << m_boundLo;
            return false;
        }
    }

    if (m_boundsCheckFlagHi)
    {
        if (value > m_boundHi)
        {
            gtWarning() << tr("Invalid value for ") << objectName()
                        << tr(". Value has to be lower than")
                        << m_boundHi;
            return false;
        }
    }

    return true;
}

double
GtDoubleProperty::initialValue() const
{
    return m_initValue;
}

gt::PropertyFactoryFunction
gt::makeDoubleProperty(double value)
{
    return makePropertyFactory<GtDoubleProperty>(std::move(value));
}
