#include "player.hpp"
#include <QJsonDocument>
#include <QString>
#include <iostream>
#include <QtGlobal>
#include <QDebug>
#include <QJsonObject>
int Player::loadSaveFile(QFile *file) {
    if(!file->open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return 1;
    }
    QTextStream configStream(file);
    QTextStream out(stdout);

    const auto configJson = configStream.readAll();
    QJsonParseError parseError;
    auto config = QJsonDocument::fromJson(configJson.toUtf8(), &parseError).object();
    const auto player = config["player"].toObject();
    const auto age = player["age"].toInt();
    out << "Name: " << player["name"].toString() << endl;
    out << "Age: " << age << endl;
    out << "Skill: " << player["skill"].toInt() << endl;
    out << "Level: " << player["level"].toInt() << endl;
    file->close();
    return 0;
}
int Player::saveToSaveFile(QFile *file) {
    if(!file->open(QIODevice::ReadWrite)) {
        return 1;
    }
	QTextStream out(stdout);
	QTextStream configStream(file);

    auto configJson = configStream.readAll();
    file->seek(0);
    QJsonParseError parseError;
    auto config = QJsonDocument::fromJson(configJson.toUtf8(), &parseError);
	qWarning() << parseError.errorString();
    qInfo("writing to save file");
	qInfo("Player name: %s", this->getName().c_str());
    // config["player"].toObject()["age"] = config["player"].toObject()["age"].toInt()++;
    auto configObject = config.object();
    auto player = configObject["player"].toObject();

    player["age"] = QString::number(this->age());
    player["level"] = QString::number(this->level());
    player["skill"] = QString::number(this->skill());
    player["name"] = QString::fromStdString(this->getName());
    configObject["player"] = player;
    config.setObject(configObject);
    file->write(config.toJson());
    file->close();
    return 0;
}

