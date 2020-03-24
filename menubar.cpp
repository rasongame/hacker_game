#include "menubar.hpp"
#include <QMenu>
#include <QFile>
#include <QMenuBar>
#include "player.hpp"
SimpleMenu::SimpleMenu(Player *player, QFile *s_file, QWidget *parent)
    : QMainWindow(parent) {

  // Создаём объект класса QAction (действие) с названием пункта меню "Quit"
  QAction *save_to_save_act = new QAction("&Save", this);
  QAction *load_save_act = new QAction("&Load", this);
  QAction *quit_act = new QAction("&Quit", this);

  // Создаём объект класса QMenu (меню)
  QMenu *file;
  file = menuBar()->addMenu("&File");

  // Помещаем действие "Quit" (Выход) в меню с помощью метода addAction()
  file->addAction(quit_act);
  file->addAction(save_to_save_act);
  file->addAction(load_save_act);

  // Когда мы выбираем в меню опцию "Quit", то приложение сразу же завершает своё выполнение
  connect(quit_act, &QAction::triggered, quit_act,[=]{
    player->saveToSaveFile(s_file);
  });
  // connect(quit, &QAction::triggered, qApp, QApplication::quit);
  // connect(quit, &QAction::triggered, qApp, QApplication::quit);
}
