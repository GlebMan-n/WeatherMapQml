#include "databaseworker.h"
#include "databasesettings.h"
#include "city.h"

DataBaseWorker::DataBaseWorker(QObject *parent) : QObject(parent)
{

}

bool DataBaseWorker::initDataBase()
{
    m_db = new QSqlDatabase(std::move(QSqlDatabase::addDatabase(databaseSettings.getDriver())));
    m_db->setHostName(databaseSettings.getHostName());
    m_db->setDatabaseName(databaseSettings.getDatabasePath() + "/" + databaseSettings.getDatabaseName());
    m_db->setUserName(databaseSettings.getUserName());
    m_db->setPassword(databaseSettings.getPassword());
    return m_db->open();
}

bool DataBaseWorker::importCities(QString &&path)
{

}
