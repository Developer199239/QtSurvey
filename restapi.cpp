#include "restapi.h"

RestApi::RestApi(QObject *parent) : QObject(parent)
{
    connect(&m_networkAccessManager, &QNetworkAccessManager::finished, this, &RestApi::onReplyFinished);
}

void RestApi::get(const QUrl& url)
{
    QNetworkRequest request(url);
    m_networkAccessManager.get(request);
}

void RestApi::post(const QUrl& url, const QByteArray& data)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    m_networkAccessManager.post(request, data);
}

void RestApi::del(const QUrl& url)
{
    QNetworkRequest request(url);
    m_networkAccessManager.deleteResource(request);
}

void RestApi::onReplyFinished(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        emit error(reply->errorString());
        return;
    }

    QByteArray response = reply->readAll();
    emit success(response);
}
