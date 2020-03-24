#include "Computer.hpp"
#include <QObject>
#include <QDebug>
Computer::Computer(QObject *parent) : QObject(parent) {
	this->ramCount = 2048;
}
bool Computer::insertRam(int ram_count) {
	if (ram_count < this->maxRamCount) {
		this->ramCount += ram_count;
	} else {
		return false;
	}
	return true;
}

bool Computer::enableInternet() {
	if(!this->enabledInternet) {
		this->enabledInternet = true;
		return true;
	}
	return false;
}
bool Computer::enable() {
	if(!this->enabled) {
		this->enabled = true;
		return true;
	}
	return false;
}
bool Computer::disable() {
	if (this->enabled) {
		this->enabled = false;
		return true;
	}
	return false;
}
bool Computer::disableInternet() {
	if(this->enabledInternet) {
		emit sendToQml_from_computer(QString("hehe"));
		this->enabledInternet = false;
		return true;
	}
	return false;
}
