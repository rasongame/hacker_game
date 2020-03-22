#include "player.hpp"
#include <QJsonDocument>
#include <QString>
#include <iostream>
#include <QtGlobal>
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
    qWarning("%s", parseError);
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
    auto self = this;

    if(!file->open(QIODevice::ReadWrite)) {
        return 1;
    }
    QTextStream configStream(file);
    auto configJson = configStream.readAll();
    QJsonParseError parseError;
    auto config = QJsonDocument::fromJson(configJson.toUtf8(), &parseError);
    qWarning("%s", parseError);
    qInfo("writing to save file");
    qInfo("Player name: %s", this->_name);
    // config["player"].toObject()["age"] = config["player"].toObject()["age"].toInt()++;
    config["player"]["name"] = QString::fromStdString(self->getName());
    file->write(config.toJson());
    file->close();
    return 0;
}

