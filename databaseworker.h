#ifndef DATABASEWORKER_H
#define DATABASEWORKER_H

#include <QObject>
#include <QSqlDatabase>

class DataBaseWorker : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseWorker(QObject *parent = nullptr);
    bool initDataBase();
private:
    QSqlDatabase* m_db;
signals:

};

#endif // DATABASEWORKER_H
