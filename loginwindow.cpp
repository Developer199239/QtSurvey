#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QJsonObject>
#include <QJsonDocument>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
  QString leUserId = ui->leUserId->text();
  QString lePassword = ui->lePassword->text();

  if(leUserId.length() == 0 || lePassword.length() == 0) {
      QMessageBox::warning(this, "Login","Insert all information");
  } else {
      qDebug() << "clicked: ";
    RestApi api;
    QJsonObject data;
    data["pin"] = "105418";
    data["password"] = "123456";
    QJsonDocument doc(data);
    QByteArray postData = doc.toJson();
    QUrl url = QUrl::fromUserInput("https://hub.sensor.buzz/upg-auth/api/v1/account/login");
    api.post(url, postData);

    connect(&api, &RestApi::success, this, &LoginWindow::onReplyReceived);
  }
}

void LoginWindow::onReplyReceived(QByteArray response)
{
    qDebug() << "Response: ";
}

//void LoginWindow::onReplyReceived(QNetworkReply *reply)
//{
//    qDebug() << "Response: ";
//    if (reply->error() != QNetworkReply::NoError) {
//        qDebug() << "Error: " << reply->errorString();
//        return;
//    }

//    QByteArray data = reply->readAll();
//    // Do something with the response data
//}

