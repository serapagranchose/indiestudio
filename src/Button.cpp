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
    if (name != "Sound" && name != "Plus" && name != "Minus") {
        this->texture = LoadTexture(path);
        this->name = name;
        this->frameHeight = (float)this->texture.height / NUM_FRAMES;
        this->size = {0, 0, (float)this->texture.width, (float)this->frameHeight};
        this->bounds = {window->screen_width / 4.5f - this->texture.width / 2.0f, window->screen_height / heightScreen - this->texture.height/NUM_FRAMES/heightButton, (float)this->texture.width, (float)this->frameHeight};
        this->sound = LoadSound("../audio/button.wav");
    }
    else if (name == "Sound") {
        this->texture = LoadTexture(path);
        this->name = name;
        this->frameHeight = (float)this->texture.height / NUM_SOUND;
        this->size = {0, 0, (float)this->texture.width, (float)this->frameHeight};
        this->bounds = {window->screen_width / 4.5f - this->texture.width / 2.0f, window->screen_height / heightScreen - this->texture.height/NUM_FRAMES/heightButton, (float)this->texture.width, (float)this->frameHeight};
        this->sound = LoadSound("../audio/button.wav");
    }
    else if (name == "Plus") {
        this->texture = LoadTexture(path);
        this->name = name;
        this->frameHeight = (float)this->texture.height / NUM_FRAMES;
        this->size = {0, 0, (float)this->texture.width, (float)this->frameHeight};
        this->bounds = {window->screen_width / 3.1f - this->texture.width / 2.0f, window->screen_height / heightScreen - this->texture.height/NUM_FRAMES/heightButton, (float)this->texture.width, (float)this->frameHeight};
        this->sound = LoadSound("../audio/button.wav");
    }
    else if (name == "Minus") {
        this->texture = LoadTexture(path);
        this->name = name;
        this->frameHeight = (float)this->texture.height / NUM_FRAMES;
        this->size = {0, 0, (float)this->texture.width, (float)this->frameHeight};
        this->bounds = {window->screen_width / 8.4f - this->texture.width / 2.0f, window->screen_height / heightScreen - this->texture.height/NUM_FRAMES/heightButton, (float)this->texture.width, (float)this->frameHeight};
        this->sound = LoadSound("../audio/button.wav");
    }
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
    bomberman->setStatus(1);
        if (bomberman->getGenerated() == 0) {
            bomberman->getMap()->random_map();
            bomberman->getMap()->add_block(bomberman);
        }
}

void Button::settings(Game *bomberman)
{
    this->check = 1;
    PlaySound(this->sound);
    bomberman->setStatus(2);
}

void Button::quit(Game *bomberman)
{
    PlaySound(this->sound);
    bomberman->setStatus(-1);
}

void Button::credits(Game *bomberman)
{
    this->check = 1;
    PlaySound(this->sound);
    bomberman->setStatus(3);
}

void Button::home(Game *bomberman)
{
    PlaySound(this->sound);
    bomberman->setStatus(0);
}

void Button::plus(Game *bomberman)
{
    if (bomberman->getMusic()->getVolume() < 1) {
        bomberman->getMusic()->setVolume(bomberman->getMusic()->getVolume() + 0.1);
        SetMasterVolume(bomberman->getMusic()->getVolume());
    }
    PlaySound(this->sound);
}

void Button::minus(Game *bomberman)
{
    if (bomberman->getMusic()->getVolume() > 0) {
        bomberman->getMusic()->setVolume(bomberman->getMusic()->getVolume() - 0.1);
        SetMasterVolume(bomberman->getMusic()->getVolume());
    }
    PlaySound(this->sound);
}

void Button::input(Game *bomberman, Vector2 mouse)
{
    if (bomberman->getStatus() == 0) {
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
    if (bomberman->getStatus() == 2 || bomberman->getStatus() == 3) {
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
        else if (this->action && this->name == "Plus")
            plus(bomberman);
        else if (this->action && this->name == "Minus")
            minus(bomberman);
        if (this->name != "Sound")
            this->size.y = this->status * (float)this->frameHeight;
        this->action = false;
    }
}

float Button::getFrameHeight() const
{
    return (this->frameHeight);
}