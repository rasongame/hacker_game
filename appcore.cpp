#include "appcore.hpp"
#include "player.hpp"
AppCore::AppCore(QObject *parent) : QObject(parent)
{
	string = "";
}

void AppCore::receiveFromQml(QString string)
{
	string = string;
}
