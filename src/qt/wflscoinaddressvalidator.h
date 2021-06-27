// Copyright (c) 2011-2020 The Wflscoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WFLSCOIN_QT_WFLSCOINADDRESSVALIDATOR_H
#define WFLSCOIN_QT_WFLSCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class WflscoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit WflscoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Wflscoin address widget validator, checks for a valid wflscoin address.
 */
class WflscoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit WflscoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // WFLSCOIN_QT_WFLSCOINADDRESSVALIDATOR_H
