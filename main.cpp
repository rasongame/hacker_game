#include "player.hpp"
#include "menubar.hpp"

#include <QFile>
#include <QApplication>
#include <QWidget>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFile file("config.json");
    Player player("rason", 17);
    SimpleMenu window;

    window.resize(250, 150); // изменяем размер виджета
    window.setWindowTitle("Hacker: The Game"); // устанавливаем заголовок для главного окна
    window.show(); // выводим виджет на экране
    return app.exec();
}
