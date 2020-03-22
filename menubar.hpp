#pragma once

#include <QMainWindow>
#include <QApplication>
#include "player.hpp"
class SimpleMenu : public QMainWindow {

  public:
    SimpleMenu(Player *player, QWidget *parent = 0);
};
