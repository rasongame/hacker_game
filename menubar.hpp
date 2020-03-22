#pragma once

#include <QMainWindow>
#include <QApplication>

class SimpleMenu : public QMainWindow {

  public:
    SimpleMenu(Player *player, QWidget *parent = 0);
};
