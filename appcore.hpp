#include <QObject>
#include <QString>
#include "player.hpp"
class AppCore : public QObject
{
	Q_OBJECT

public:
	AppCore(Player *player, QObject *parent = 0);
	Player *player;
	virtual ~AppCore() {};

signals:
	// Сигнал для передачи данных в qml-интерфейс
	void sendToQml(QString name, int age, int skill, int level);

public slots:
	// Слот для приёма данных из qml-интерфейса
	void receiveFromQml(QString name, int age, int skill, int level);

private:
	QString string = "";
};
