#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

struct Coord
{
    QByteArray toJson() const
    {
        return QByteArray();
    }
    bool fromJson(const QByteArray &ba)
    {
        return true;
    }
    double lat;
    double lon;
};

struct City{
    QByteArray toJson() const
    {
        return QByteArray();
    }
    bool fromJson(const QByteArray &ba)
    {
        return true;
    }
    int id;
    QString name;
    QString findname;
    QString country;
    Coord coord;
    int zoom;
};

struct Cities{
    QByteArray toJson() const {
        QJsonObject jsonObj;
        QStringList list;
        for (auto i = 0; i < cities.size(); i++) {
            QString json_str = QString::fromLatin1((cities.at(i).toJson()));
            list.append(json_str);
        }
        jsonObj.insert("cities", QJsonArray::fromStringList(list));
        QJsonDocument jsonOutDoc;
        jsonOutDoc.setObject(jsonObj);
        QByteArray bytes = jsonOutDoc.toJson().simplified();
        return bytes.replace(QByteArray("\n"), QByteArray(""));
    }
    bool fromJson(const QByteArray &ba) {
        cities.clear();
        QJsonArray ar;
        QJsonObject jsonObj;
        QJsonDocument jsonOutDoc;
        QJsonParseError error;
        jsonOutDoc  = QJsonDocument::fromJson(ba,&error);
        jsonObj     = jsonOutDoc.object();
        if(error.offset > 0)
            return false;
        QString t = jsonObj.take("time").toString();
        ar           = jsonObj.take("medications").toArray();
        QVariantList list = ar.toVariantList();
        for (int i = 0; i < list.size(); i++)
        {
            QJsonObject obj = list.at(i).toJsonObject();
            QJsonDocument doc(obj);
            QByteArray bytes = doc.toJson();
            City city;
            city.fromJson(bytes);
            cities.push_back(city);
        }
        return true;
    }
    QVector<City> cities;
};

#endif // CITY_H
