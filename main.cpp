﻿#include "player.hpp"
#include "menubar.hpp"
#include "ledit.hpp"
#include <QFile>
#include <QApplication>
#include <QWidget>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QQuickView>
#include "appcore.hpp"
#include "Computer.hpp"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QFile file("config.json");
    Player player("rason", 17);
	QQmlApplicationEngine engine;
	qDebug() << "Running rootContext.." << endl;

	QQmlContext* rootContext = engine.rootContext();
	qDebug() << "runnin appCore.." << endl;
	AppCore appCore(&player, &file);
	Computer computer;
	rootContext->setContextProperty("Skill", player.skill());
	rootContext->setContextProperty("Level", player.level());
	rootContext->setContextProperty("Age", player.age());
	rootContext->setContextProperty("Name", QString::fromStdString(player.getName()));
	rootContext->setContextProperty("appCore", &appCore);
	rootContext->setContextProperty("Computer", &computer);
	qDebug() << "Running GUI subsystem.." << endl;

	engine.load(QUrl(QStringLiteral("main.qml")));
	return app.exec();
}
