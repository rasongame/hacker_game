#include <QObject>
#include <QString>
#include "player.hpp"
class AppCore : public QObject
{
	Q_OBJECT

public:
	explicit AppCore(QObject *parent = 0);
	virtual ~AppCore() {};

signals:
	// Сигнал для передачи данных в qml-интерфейс
	void sendToQml(QString string);

public slots:
	// Слот для приёма данных из qml-интерфейса
	void receiveFromQml(QString string);

private:

	QString string;  // Счетчик, которым будем оперировать
};
