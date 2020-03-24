#ifndef COMPUTER_HPP
#define COMPUTER_HPP
#include <QObject>
#include <QString>
class Computer : public QObject
{
	Q_OBJECT
public:
	Computer(QObject *parent = 0);
	virtual ~Computer() {};
	bool insertRam(int ram_count);
	int ramCount;
	int maxRamCount = 8192;
signals:
	void sendToQml_from_computer(QString string);
	void Just(QString string);
public slots:
	bool enable();
	bool disable();
	bool disableInternet();
	bool enableInternet();
private:
	bool enabledInternet;
	bool enabled;

};

#endif // COMPUTER_HPP
