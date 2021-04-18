#ifndef QHTTPCLIENT_H
#define QHTTPCLIENT_H

#include <QUrl>
#include <QObject>
#include <QString>

class QNetworkReply;
class QNetworkAccessManager;

class QHttpClient : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief 构造析构函数
     */
    explicit QHttpClient(const QString & strUrl);
    QHttpClient(const QString & strUrl, QNetworkAccessManager * netManager);
    ~QHttpClient() {}

    /**
     * @brief 执行GET方法
     */
    void get();

    /**
     * @brief 执行POST方法
     */
    void post();

private slots:
    void handleFinished(QNetworkReply * reply);

private:
    QUrl m_url;
    QNetworkAccessManager * m_manager = Q_NULLPTR;
};

#endif // QHTTPCLIENT_H
