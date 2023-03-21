#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include "mainwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->leUserId->setText("105418");
    ui->lePassword->setText("123456");
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
      this->makeRequest(leUserId,lePassword);
  }
}


void LoginWindow::makeRequest(QString leUserId, QString lePassword) {
    QByteArray postData;
        postData.append("pin=");
        postData.append(leUserId.toUtf8());
        postData.append("&password=");
        postData.append(lePassword.toUtf8());

    QNetworkRequest request(QUrl("https://hub.sensor.buzz/upg-auth/api/v1/account/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->post(request, postData);
    // Connect the reply's finished() signal to a slot that will handle the response
    connect(reply, SIGNAL(finished()), this, SLOT(handleResponse()));
}

void LoginWindow::handleResponse() {
    // Get the HTTP reply from the sender object
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        qDebug() << data;

        MainWindow *main = new MainWindow(this);
            main->show();
            this->hide();
    } else {
        qDebug() << "Error: " << reply->errorString();
    }

    // Clean up the reply object
    reply->deleteLater();
}
