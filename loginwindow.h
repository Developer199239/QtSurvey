#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
//#include "restapi.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();
//    void onReplyReceived(QByteArray response);
    void makeRequest(QString leUserId, QString lePassword);
    void handleResponse();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
