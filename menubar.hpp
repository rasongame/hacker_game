#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QFile>
#include "player.hpp"
class SimpleMenu : public QMainWindow {

  public:
    SimpleMenu(Player *player,QFile *s_file, QWidget *parent = 0);
};
