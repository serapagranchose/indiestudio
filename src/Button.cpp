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
    this->texture = LoadTexture(path);
    this->name = name;
    this->frameHeight = (float)this->texture.height / NUM_FRAMES;
    this->size = {0, 0, (float)this->texture.width, (float)this->frameHeight};
    this->bounds = {window->screen_width / 4.5f - this->texture.width / 2.0f, window->screen_height / heightScreen - this->texture.height/NUM_FRAMES/heightButton, (float)this->texture.width, (float)this->frameHeight};
    this->sound = LoadSound("../audio/button.wav");
}

Button::~Button()
{

}

void Button::draw(Game *bomberman)
{
    DrawTextureRec(this->texture, this->size, Vector2{this->bounds.x, this->bounds.y}, WHITE);
}

void Button::start(Game *bomberman)
{
    PlaySound(this->sound);
    bomberman->status = 1;
        if (bomberman->map_generated == 0) {
            bomberman->create_random_map();
            bomberman->random_map();
        }
}

void Button::settings(Game *bomberman)
{
    this->check = 1;
    PlaySound(this->sound);
    bomberman->status = 2;
}

void Button::quit(Game *bomberman)
{
    PlaySound(this->sound);
    bomberman->status = -1;
}

void Button::credits(Game *bomberman)
{
    this->check = 1;
    PlaySound(this->sound);
    bomberman->status = 3;
}

void Button::home(Game *bomberman)
{
    PlaySound(this->sound);
    bomberman->status = 0;
}

void Button::input(Game *bomberman, Vector2 mouse)
{
    if (bomberman->status == 0) {
        if (CheckCollisionPointRec(mouse, this->bounds)) {
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
        else if (this->action && this->name == "Credits")
            credits(bomberman);
        this->action = false;
        this->size.y = this->status * (float)this->frameHeight;
    }
    if (bomberman->status == 2 || bomberman->status == 3) {
        if (CheckCollisionPointRec(mouse, this->bounds)) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                this->status = 2;
            else
                this->status = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                this->action = true;
        } else
            this->status = 0;
        if (this->action && this->name == "Home")
            home(bomberman);
        this->action = false;
        this->size.y = this->status * (float)this->frameHeight;
    }
}
