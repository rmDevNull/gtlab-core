/* GTlab - Gas Turbine laboratory
 * Source File: gt_regexp.cpp
 * copyright 2009-2017 by DLR
 *
 *  Created on: 05.12.2017
 *  Author: Jens Schmeink (AT-TW)
 *  Tel.: +49 2203 601 2191
 */

#include "gt_regexp.h"


QRegExp
GtRegExp::woUmlauts()
{
    return QRegExp(("[^äöüßÄÖÜ]*"));
}

QRegExp
GtRegExp::umlauts()
{
    return QRegExp(("[äöüßÄÖÜ]"));
}

QRegExp
GtRegExp::umlautsAndSpecialChar()
{
    return QRegExp(("[äöüßÄÖÜ\\.\\:\\,\\;\\#\\?\\+\\~\\*\\/"
                    "\\&\\%\\$\\§\\!\"\\{\\}\\=\\`\\´\\'\\°\\^]"));
}

QRegExp
GtRegExp::onlyLetters()
{
    return QRegExp(("[A-Za-z]+"));
}

QRegExp
GtRegExp::onlyLettersAndNumbers()
{
    return QRegExp(("[A-Za-z0-9\\_\\-\\[\\]]+"));
}

QRegExp
GtRegExp::onlyLettersAndNumbersAndDot()
{
    return QRegExp(("[A-Za-z0-9\\.\\_\\-\\[\\]]+"));
}

QRegExp
GtRegExp::onlyLettersAndNumbersAndSpace()
{
    return QRegExp(("[A-Za-z0-9\\_\\-\\[\\]\\s\\␣]+"));
}

QRegExp
GtRegExp::forUnits()
{
    return QRegExp(("[A-Za-z0-9\\_\\-\\+\\^\\°\\%\\/]*"));
}

QRegExp
GtRegExp::forExpressions()
{
    return QRegExp(("[A-Za-z0-9\\_\\-\\+\\^\\°\\/\\*\\.\\,\\(\\)\\[\\]]*"));
}

QRegExp
GtRegExp::forStations()
{
    return QRegExp(("S[0-9]{1,3}"));
}

QRegExp
GtRegExp::forDoubles()
{
    return QRegExp(("-?[0-9]+.*[E,e]?-?[0-9]*"));
}

QRegExp
GtRegExp::forDoublesLists()
{
    return QRegExp(("[eE0-9\\-\\.\\;]+"));
}

QRegExp
GtRegExp::forSemVers()
{
    return QRegExp(R"(^(0|[1-9]\d*)(\.(0|[1-9]\d*)(\.(0|[1-9]\d*))?)?(?:-((?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*))"
                                         R"((?:\.(?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*))*))?(?:\+([0-9a-zA-Z-]+(?:\.[0-9a-zA-Z-]+)*))?$)");
}
