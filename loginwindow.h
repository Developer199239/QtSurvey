#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "mytask.h"

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
    void makeRequest(QString leUserId, QString lePassword);
    void handleResponse();
//    void setProgress(qint64 bytesReceived, qint64 bytesTotal);

private:
    Ui::LoginWindow *ui;
    MyTask *myTask;
};

#endif // LOGINWINDOW_H
