/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "indiestudio.hpp"

Player::Player()
{

}

Player::~Player()
{

}

void Player::draw(Game *bomberman)
{
    if (bomberman->status == this->place)
        DrawCubeV(this->position, this->size, this->color);
}
