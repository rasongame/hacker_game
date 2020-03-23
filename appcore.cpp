#include "appcore.hpp"
#include <QDebug>

AppCore::AppCore(Player *player, QObject *parent) : QObject(parent)
{
	this->player = player;
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
