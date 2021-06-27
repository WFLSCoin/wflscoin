// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Wflscoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WFLSCOIN_SCRIPT_WFLSCOINCONSENSUS_H
#define WFLSCOIN_SCRIPT_WFLSCOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_WFLSCOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/wflscoin-config.h>
  #if defined(_WIN32)
    #if defined(HAVE_DLLEXPORT_ATTRIBUTE)
      #define EXPORT_SYMBOL __declspec(dllexport)
    #else
      #define EXPORT_SYMBOL
    #endif
  #elif defined(HAVE_DEFAULT_VISIBILITY_ATTRIBUTE)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBWFLSCOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define WFLSCOINCONSENSUS_API_VER 1

typedef enum wflscoinconsensus_error_t
{
    wflscoinconsensus_ERR_OK = 0,
    wflscoinconsensus_ERR_TX_INDEX,
    wflscoinconsensus_ERR_TX_SIZE_MISMATCH,
    wflscoinconsensus_ERR_TX_DESERIALIZE,
    wflscoinconsensus_ERR_AMOUNT_REQUIRED,
    wflscoinconsensus_ERR_INVALID_FLAGS,
} wflscoinconsensus_error;

/** Script verification flags */
enum
{
    wflscoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    wflscoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    wflscoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    wflscoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    wflscoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    wflscoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    wflscoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    wflscoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = wflscoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | wflscoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               wflscoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | wflscoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               wflscoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | wflscoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int wflscoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, wflscoinconsensus_error* err);

EXPORT_SYMBOL int wflscoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, wflscoinconsensus_error* err);

EXPORT_SYMBOL unsigned int wflscoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // WFLSCOIN_SCRIPT_WFLSCOINCONSENSUS_H
