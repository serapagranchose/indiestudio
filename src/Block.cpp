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

Block::~Block()
{

}

void Block::draw(Game *bomberman)
{
    if (bomberman->status == this->place)
        DrawCubeV(this->position, this->size, this->color);
}
