#pragma once

#include <QWidget>
#include "player.hpp"
class Ledit : public QWidget {

  public:
    Ledit(Player *player, QWidget *parent = 0);
};
