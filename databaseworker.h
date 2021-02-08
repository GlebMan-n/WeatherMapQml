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
    inline bool isValid() const { return m_db ? m_db->isValid() : false; }
    bool importCities(QString &&path);
private:
    QSqlDatabase* m_db;
signals:

};

#endif // DATABASEWORKER_H
