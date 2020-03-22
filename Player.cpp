#include <bits/stdc++.h>
#include "player.hpp"
#include <iostream>
Player::Player(std::string name, int age) {
    this->_name  = name;
    this->setAge(age);
    this->setLevel(1);
    this->setSkill(1);

    QFile file("config.json");
    this->loadSaveFile(&file);
    this->saveToSaveFile(&file);

}

void Player::setAge(int age) {
    this->_age = age;
}

void Player::setLevel(int level) {
    this->_level = level;
}

void Player::setSkill(int skill) {
    this->_skill = skill;
}


