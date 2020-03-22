
#include <string>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <iostream>
class Player {


private:
    int _age;
    int _skill;
    int _level;
    std::string _name;
public:
    Player(std::string name,int age);
    std::string getName() { return this->_name; };
    int skill() { return this->_skill; };
    int level() { return this->_level; };
    int age() { return this->_age; };
    void setSkill(int skill);
    void setLevel(int level);
    void setAge(int age);
    int loadSaveFile(QFile *file);
    int saveToSaveFile(QFile *file);
};
