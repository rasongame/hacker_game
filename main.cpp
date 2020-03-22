#include "player.hpp"
#include <iostream>
#include <QFile>
#include <QCoreApplication>
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Player player("rason", 17);
    std::cout << "QtVersion" << qVersion() << std::endl;
    return 0;
}
