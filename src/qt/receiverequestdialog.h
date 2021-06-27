// Copyright (c) 2011-2020 The Wflscoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WFLSCOIN_QT_RECEIVEREQUESTDIALOG_H
#define WFLSCOIN_QT_RECEIVEREQUESTDIALOG_H

#include <qt/sendcoinsrecipient.h>

#include <QDialog>

class WalletModel;

namespace Ui {
    class ReceiveRequestDialog;
}

class ReceiveRequestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiveRequestDialog(QWidget *parent = nullptr);
    ~ReceiveRequestDialog();

    void setModel(WalletModel *model);
    void setInfo(const SendCoinsRecipient &info);

private Q_SLOTS:
    void on_btnCopyURI_clicked();
    void on_btnCopyAddress_clicked();
    void updateDisplayUnit();

private:
    Ui::ReceiveRequestDialog *ui;
    WalletModel *model;
    SendCoinsRecipient info;
};

#endif // WFLSCOIN_QT_RECEIVEREQUESTDIALOG_H
