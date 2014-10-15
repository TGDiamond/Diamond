// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DIAMONDADDRESSVALIDATOR_H
#define DIAMONDADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class DiamondAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DiamondAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Diamond address widget validator, checks for a valid diamond address.
 */
class DiamondAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DiamondAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // DIAMONDADDRESSVALIDATOR_H
