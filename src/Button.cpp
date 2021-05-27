/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "indiestudio.hpp"

Button::Button()
{

}

Button::~Button()
{

}

void Button::draw(Game *bomberman)
{
    if (bomberman->status == this->place)
        DrawTextureRec(this->texture, this->size, (Vector2){this->bounds.x, this->bounds.y}, WHITE);
}

void Button::input(Game *bomberman, Vector2 mouse)
{
    if (CheckCollisionPointRec(mouse, this->bounds)){
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            this->status = 2;
        else
            this->status = 1;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->action = true;
    } else
        this->status = 0;

    if (this->action)
        bomberman->status = 1;

    this->size.y = bomberman->status * this->frame_height;
}
