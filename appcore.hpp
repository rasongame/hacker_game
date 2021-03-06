﻿#include <QObject>
#include <QString>
#include <QFile>
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
class AppCore : public QObject
{
	Q_OBJECT

public:
	AppCore(Player *player,QFile *saveFile, QObject *parent = 0);
	Player *player;
	QFile *saveFile;
	double vm, rss;
	void process_mem_usage(double& vm_usage, double& resident_set);
	virtual ~AppCore() {};

signals:
	// Сигнал для передачи данных в qml-интерфейс
	void sendToQml(QString name, int age, int skill, int level);

public slots:
	// Слот для приёма данных из qml-интерфейса
	void receiveFromQml(QString name, int age, int skill, int level);
	void savePlayer();
	void getRam();
private:
	QString string = "";
};
