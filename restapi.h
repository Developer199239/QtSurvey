#ifndef RESTAPI_H
#define RESTAPI_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>



class RestApi : public QObject
{
    Q_OBJECT
public:
    explicit RestApi(QObject *parent = nullptr);

    void get(const QUrl& url);
    void post(const QUrl& url, const QByteArray& data);
    void del(const QUrl& url);

signals:
    void success(QByteArray response);
    void error(QString message);

private slots:
    void onReplyFinished(QNetworkReply* reply);

private:
    QNetworkAccessManager m_networkAccessManager;
};

#endif // RESTAPI_H
