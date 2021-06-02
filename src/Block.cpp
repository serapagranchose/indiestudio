/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "indiestudio.hpp"

Block::Block()
{

}

Block::Block(Vector3 position, bool destructible)
{
    this->position = position;
    this->destructible = destructible;
}

Block::~Block()
{

}

void Block::draw(Game *bomberman)
{
    if (bomberman->status == this->place)
        DrawCubeV(this->position, this->size, this->color);
}
