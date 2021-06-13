/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "Button.hpp"

Button::Button()
{

}

Button::Button(Window *window, float heightScreen, float heightButton, std::string name, const char *path)
{
    this->place = 0;
    this->texture = LoadTexture(path);
    this->name = name;
    this->frameHeight = (float)this->texture.height / NUM_FRAMES;
    this->size = {0, 0, (float)this->texture.width, (float)this->frameHeight};
    this->bounds = {window->screen_width / 2.0f - this->texture.width / 2.0f, window->screen_height / heightScreen - this->texture.height/NUM_FRAMES/heightButton, (float)this->texture.width, (float)this->frameHeight};
}

Button::~Button()
{

}

void Button::draw(Game *bomberman)
{
    if (bomberman->status == this->place)
        DrawTextureRec(this->texture, this->size, Vector2{this->bounds.x, this->bounds.y}, WHITE);
}

void Button::start(Game *bomberman)
{
    bomberman->status = 1;
        if (bomberman->map_generated == 0){
            bomberman->basic_map();
            bomberman->random_map();
        }
}

void Button::settings(Game *bomberman)
{
    bomberman->status = 2;
}

void Button::quit(Game * bomberman)
{
    bomberman->status = -1;
}

void Button::input(Game *bomberman, Vector2 mouse)
{
    if (bomberman->status == this->place){
        if (CheckCollisionPointRec(mouse, this->bounds)){
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                this->status = 2;
            else
                this->status = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                this->action = true;
        } else
            this->status = 0;
        if (this->action && this->name == "Play")
           start(bomberman);
        else if (this->action && this->name == "Quit")
            quit(bomberman);
        else if (this->action && this->name == "Settings")
            settings(bomberman);
        this->size.y = this->status * (float)this->frameHeight  ;
    }
}
