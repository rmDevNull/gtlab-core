/* GTlab - Gas Turbine laboratory
 * Source File:
 * copyright 2009-2015 by DLR
 *
 *  Created on: 11.11.2015
 *  Author: Stanislaus Reitenbach (AT-TW)
 *  Tel.: +49 2203 601 2907
 */

#ifndef GTFACTORYGROUP_H
#define GTFACTORYGROUP_H

#include "gt_datamodel_exports.h"

#include "gt_abstractobjectfactory.h"

/**
 * @brief The GtFactoryGroup class
 */
class GT_DATAMODEL_EXPORT GtFactoryGroup : public GtAbstractObjectFactory
{
public:
    /**
     * @brief GtFactoryGroup
     */
    GtFactoryGroup();

    /**
     * @brief newObject - generates gtlab objects based on given classname
     * @param className
     * @param parent object for the new object
     * @return new object
     */
    GtObject* newObject(const QString& className,
                        GtObject* parent = NULL) Q_DECL_OVERRIDE;

    /**
     * @brief knownClass - returns true if classname is registered in the
     * factory
     * @param className
     * @return whether classname is known or not
     */
    bool knownClass(const QString& className) Q_DECL_OVERRIDE;

    /**
     * @brief superClassName - returns superclass name of given class
     * @param className
     * @return name of superclass
     */
    QString superClassName(const QString& className) Q_DECL_OVERRIDE;

    /**
     * @brief knownClasses - returns a list of all stored meta class names
     * @return class name list
     */
    QStringList knownClasses() const Q_DECL_OVERRIDE;

    /**
     * @brief registerClass
     * @param metaObject
     * @return
     */
    bool registerClass(QMetaObject metaObj) Q_DECL_OVERRIDE;

    /**
     * @brief registerClasses
     * @param metaObject
     * @return
     */
    bool registerClasses(const QList<QMetaObject>& metaData) Q_DECL_OVERRIDE;

    /**
     * @brief containsDuplicates
     * @param plugin
     * @return
     */
    bool containsDuplicates(const QList<QMetaObject>& metaData) Q_DECL_OVERRIDE;

    /**
     * @brief invokable
     * @param metaObj
     * @return
     */
    bool invokable(const QMetaObject& metaObj) Q_DECL_OVERRIDE;

    /**
     * @brief classHierarchy
     * @param className
     * @return
     */
    virtual QStringList classHierarchy(
            const QString& className) Q_DECL_OVERRIDE;

    /**
     * @brief addFactory
     * @param factory
     * @return
     */
    bool addFactory(GtAbstractObjectFactory* factory);

private:
    QList<GtAbstractObjectFactory*> m_factories;

};

#endif // GTFACTORYGROUP_H
