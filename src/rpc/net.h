// Copyright (c) 2021 The Wflscoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WFLSCOIN_RPC_NET_H
#define WFLSCOIN_RPC_NET_H

class CConnman;
class PeerManager;
struct NodeContext;

CConnman& EnsureConnman(const NodeContext& node);
PeerManager& EnsurePeerman(const NodeContext& node);

#endif // WFLSCOIN_RPC_NET_H
