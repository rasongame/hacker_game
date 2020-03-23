#include "player.hpp"
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

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFile file("config.json");
    Player player("rason", 17);
    SimpleMenu window(&player, &file);
	Ledit ledit(&player);
	QQmlApplicationEngine engine;
	QQmlContext* rootContext = engine.rootContext();
	AppCore appCore;    // Создаём ядро приложения
	rootContext->setContextProperty("Skill", player.skill());
	rootContext->setContextProperty("Level", player.level());
	rootContext->setContextProperty("Age", player.age());
	rootContext->setContextProperty("Name", QString::fromStdString(player.getName()));
	rootContext->setContextProperty("appCore", &appCore);

	engine.load(QUrl(QStringLiteral("main.qml")));
	return app.exec();
}
