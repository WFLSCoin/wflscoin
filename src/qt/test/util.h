// Copyright (c) 2018-2020 The Wflscoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WFLSCOIN_QT_TEST_UTIL_H
#define WFLSCOIN_QT_TEST_UTIL_H

#include <QString>

/**
 * Press "Ok" button in message box dialog.
 *
 * @param text - Optionally store dialog text.
 * @param msec - Number of milliseconds to pause before triggering the callback.
 */
void ConfirmMessage(QString* text = nullptr, int msec = 0);

#endif // WFLSCOIN_QT_TEST_UTIL_H