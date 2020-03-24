#include "appcore.hpp"
#include <QDebug>
#include <QProcess>
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

void AppCore::process_mem_usage(double& vm_usage, double& resident_set) {
	vm_usage     = 0.0;
	resident_set = 0.0;
	using std::cout;
	using std::endl;
	// the two fields we want
	unsigned long vsize;
	long rss;
	{
		std::string ignore;
		std::ifstream ifs("/proc/self/stat", std::ios_base::in);
		ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
				>> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
				>> ignore >> ignore >> vsize >> rss;
	}

	long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
	vm_usage = vsize / 1024.0;
	resident_set = rss * page_size_kb;
}

void AppCore::getRam() {
	this->process_mem_usage(this->vm, this->rss);
	std::cout << vm << "\n" << rss << std::endl;
}
