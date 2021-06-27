### QoS (Quality of service) ###

This is a Linux bash script that will set up tc to limit the outgoing bandwidth for connections to the Wflscoin network. It limits outbound TCP traffic with a source or destination port of 9357, but not if the destination IP is within a LAN.

This means one can have an always-on wflscoind instance running, and another local wflscoind/wflscoin-qt instance which connects to this node and receives blocks from it.
