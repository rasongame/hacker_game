#include "appcore.hpp"
#include <QDebug>

AppCore::AppCore(Player *player,QFile *saveFile, QObject *parent) : QObject(parent)
{
	this->saveFile = saveFile;
	this->player = player;
}
void AppCore::savePlayer() {
	this->player->saveToSaveFile(this->saveFile);
}
void AppCore::receiveFromQml(QString name, int age, int skill, int level)
{
	this->player->setName(name.toStdString());
	this->player->setAge(age);
	this->player->setSkill(skill);
	this->player->setLevel(level);
	qDebug() << QString::fromStdString(this->player->getName()) << endl;
	emit sendToQml(QString::fromStdString(this->player->getName()),
				   this->player->age(),
				   this->player->skill(),
				   this->player->level());
}
