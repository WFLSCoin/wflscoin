// Copyright (c) 2020 The Wflscoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WFLSCOIN_WALLET_DUMP_H
#define WFLSCOIN_WALLET_DUMP_H

#include <fs.h>

class CWallet;

struct bilingual_str;

bool DumpWallet(CWallet& wallet, bilingual_str& error);
bool CreateFromDump(const std::string& name, const fs::path& wallet_path, bilingual_str& error, std::vector<bilingual_str>& warnings);

#endif // WFLSCOIN_WALLET_DUMP_H
