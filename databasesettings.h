#ifndef DATABASESETTINGS_H
#define DATABASESETTINGS_H
#include <QString>

struct DatabaseSettings
{
    DatabaseSettings() = default;
    DatabaseSettings(QString &&hn, QString &&dn, QString &&un, QString &&pwd, QString &&drv, QString &&path) :
        hostName{hn}, databaseName{dn}, userName{un}, password{pwd}, driver{drv}, databasePath(path)
    {
    }

    inline QString getDatabasePath() const
    {
        return databasePath;
    }

    inline void setDatabasePath(const QString &value)
    {
        databasePath = value;
    }
    inline QString getDriver() const
    {
        return driver;
    }
    inline void setDriver(const QString &value)
    {
        driver = value;
    }
    inline QString getPassword() const
    {
        return password;
    }

    inline void setPassword(const QString &value)
    {
        password = value;
    }
    inline QString getUserName() const
    {
        return userName;
    }
    inline void setUserName(const QString &value)
    {
        userName = value;
    }
    inline QString getDatabaseName() const
    {
        return databaseName;
    }
    inline void setDatabaseName(const QString &value)
    {
        databaseName = value;
    }
    inline QString getHostName() const
    {
        return hostName;
    }
    inline void setHostName(const QString &value)
    {
        hostName = value;
    }
    ~DatabaseSettings() = default;
private:
    QString hostName;
    QString databaseName;
    QString userName;
    QString password;
    QString driver;
    QString databasePath;
};

static const DatabaseSettings databaseSettings(std::move("localhost"),
                                               std::move("weather_db"),
                                               std::move("weather_user"),
                                               std::move("weather_pwd"),
                                               std::move("QSQLITE"),
                                               std::move("/home/gleb/database")
                                               );

#endif // DATABASESETTINGS_H
