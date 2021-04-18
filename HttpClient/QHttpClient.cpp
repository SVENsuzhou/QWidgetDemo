#include "QHttpClient.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>

QHttpClient::QHttpClient(const QString & strUrl)
    : m_url(strUrl)
{
    m_manager = new QNetworkAccessManager(this);
}

QHttpClient::QHttpClient(const QString & strUrl, QNetworkAccessManager * netManager)
    : m_url(strUrl)
    , m_manager(netManager)
{

}


void QHttpClient::get()
{
    QNetworkRequest request(m_url);

//    QNetworkReply * reply = m_manager->get(request);
    m_manager->get(request);
    QObject::connect(m_manager, &QNetworkAccessManager::finished, this, &QHttpClient::handleFinished);
}

void QHttpClient::handleFinished(QNetworkReply * reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << reply->error();
    }
}
