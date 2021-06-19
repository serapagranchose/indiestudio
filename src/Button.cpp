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
    if (name == "Resume" || name == "homePause" || name == "Save") {
        this->_Texture = LoadTexture(path);
        this->_Name = name;
        this->_FrameHeight = (float)this->_Texture.height / NUM_FRAMES;
        this->_Size = {0, 0, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Bounds = {window->_ScreenWidth / 2.0f - this->_Texture.width / 2.0f, window->_ScreenHeight / heightScreen - this->_Texture.height/NUM_FRAMES/heightButton, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Sound = LoadSound("assets/audio/button.wav");
        return;
    }
    else if (name != "Sound" && name != "Plus" && name != "Minus") {
        this->_Texture = LoadTexture(path);
        this->_Name = name;
        this->_FrameHeight = (float)this->_Texture.height / NUM_FRAMES;
        this->_Size = {0, 0, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Bounds = {window->_ScreenWidth / 4.5f - this->_Texture.width / 2.0f, window->_ScreenHeight / heightScreen - this->_Texture.height/NUM_FRAMES/heightButton, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Sound = LoadSound("assets/audio/button.wav");
    }
    else if (name == "Sound") {
        this->_Texture = LoadTexture(path);
        this->_Name = name;
        this->_FrameHeight = (float)this->_Texture.height / NUM_SOUND;
        this->_Size = {0, 0, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Bounds = {window->_ScreenWidth / 4.5f - this->_Texture.width / 2.0f, window->_ScreenHeight / heightScreen - this->_Texture.height/NUM_FRAMES/heightButton, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Sound = LoadSound("assets/audio/button.wav");
    }
    else if (name == "Plus") {
        this->_Texture = LoadTexture(path);
        this->_Name = name;
        this->_FrameHeight = (float)this->_Texture.height / NUM_FRAMES;
        this->_Size = {0, 0, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Bounds = {window->_ScreenWidth / 3.1f - this->_Texture.width / 2.0f, window->_ScreenHeight / heightScreen - this->_Texture.height/NUM_FRAMES/heightButton, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Sound = LoadSound("assets/audio/button.wav");
    }
    else if (name == "Minus") {
        this->_Texture = LoadTexture(path);
        this->_Name = name;
        this->_FrameHeight = (float)this->_Texture.height / NUM_FRAMES;
        this->_Size = {0, 0, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Bounds = {window->_ScreenWidth / 8.4f - this->_Texture.width / 2.0f, window->_ScreenHeight / heightScreen - this->_Texture.height/NUM_FRAMES/heightButton, (float)this->_Texture.width, (float)this->_FrameHeight};
        this->_Sound = LoadSound("assets/audio/button.wav");
    }
}

Button::~Button()
{

}

void Button::draw(Game *bomberman)
{
    DrawTextureRec(this->_Texture, this->_Size, Vector2 {this->_Bounds.x, this->_Bounds.y}, WHITE);
}

void Button::start(Game *bomberman)
{
    PlaySound(this->_Sound);
    if (bomberman->getStatus() == 0){
        bomberman->setStatus(4);
        if (bomberman->getGenerated() == 0) {
            bomberman->getMap()->randomMap(bomberman);
            bomberman->getMap()->addBlock(bomberman);
        }
    } else if (bomberman->getStatus() == 4){
        while (bomberman->getPlayers().size() != 4)
            bomberman->pushPlayer("ai");
        bomberman->setStatus(1);
    }
}

void Button::settings(Game *bomberman)
{
    this->_Check = 1;
    PlaySound(this->_Sound);
    bomberman->setStatus(2);
}

void Button::quit(Game *bomberman)
{
    PlaySound(this->_Sound);
    bomberman->setStatus(-1);
}

void Button::credits(Game *bomberman)
{
    this->_Check = 1;
    PlaySound(this->_Sound);
    bomberman->setStatus(3);
}

void Button::load(Game *bomberman)
{
    PlaySound(this->_Sound);
    bomberman->setStatus(1);
    bomberman->getMap()->loadMap(bomberman);
}

void Button::home(Game *bomberman)
{
    PlaySound(this->_Sound);
    if (bomberman->getStatus() == 5 || bomberman->getStatus() == 4) {
        std::cout << "Yo" << std::endl;
        bomberman->_Players.clear();
        bomberman->_NamePlayer.clear();
        bomberman->_CoordPlayer.clear();
    }
    bomberman->setStatus(0);
}

void Button::plus(Game *bomberman)
{
    if (bomberman->getStatus() == 2) {
        if (bomberman->getAudio()->getVolume() < 1) {
            bomberman->getAudio()->setVolume(bomberman->getAudio()->getVolume() + 0.1);
            SetMasterVolume(bomberman->getAudio()->getVolume());
        }
        if (round(bomberman->getAudio()->getVolume() * 10) < 10) {
            bomberman->getAudio()->setVolume(bomberman->getAudio()->getVolume() + 0.1);
            SetMasterVolume(bomberman->getAudio()->getVolume());
        }
    } else if (bomberman->getStatus() == 4)
        if (bomberman->getPlayers().size() < 4)
            bomberman->pushPlayer("non-ai");

    PlaySound(this->_Sound);
}

void Button::minus(Game *bomberman)
{
    if (bomberman->getStatus() == 2){
        if (bomberman->getAudio()->getVolume() > 0) {
            bomberman->getAudio()->setVolume(bomberman->getAudio()->getVolume() - 0.1);
            SetMasterVolume(bomberman->getAudio()->getVolume());
        }
        if (round(bomberman->getAudio()->getVolume() * 10) > 0) {
            bomberman->getAudio()->setVolume(bomberman->getAudio()->getVolume() - 0.1);
            SetMasterVolume(bomberman->getAudio()->getVolume());
        }
    } else if (bomberman->getStatus() == 4)
        if (bomberman->getPlayers().size() != 0)
            bomberman->popPlayer();
    PlaySound(this->_Sound);
}

void Button::resume(Game *bomberman)
{
    PlaySound(this->_Sound);
    bomberman->setStatus(1);
}

void Button::save(Game *bomberman)
{
    PlaySound(this->_Sound);
    bomberman->getMap()->saveMap(bomberman);
    bomberman->setStatus(0);
}

void Button::input(Game *bomberman, Vector2 mouse)
{
    if (CheckCollisionPointRec(mouse, this->_Bounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            this->_Status = 2;
        else
            this->_Status = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->_Action = true;
    } else
        this->_Status = 0;
    if (bomberman->getStatus() == 0) {
        if (this->_Action && this->_Name == "Play")
            start(bomberman);
        else if (this->_Action && this->_Name == "Quit")
            quit(bomberman);
        else if (this->_Action && this->_Name == "Settings")
            settings(bomberman);
        else if (this->_Action && this->_Name == "Credits")
            credits(bomberman);
        else if (this->_Action && this->_Name == "Continue")
            load(bomberman);
        this->_Action = false;
        this->_Size.y = this->_Status * (float)this->_FrameHeight;
    }
    if (bomberman->getStatus() == 5) {
        if (this->_Action && this->_Name == "Resume")
            resume(bomberman);
        else if (this->_Action && this->_Name == "Save")
            save(bomberman);
        else if (this->_Action && this->_Name == "homePause")
            home(bomberman);
        this->_Size.y = this->_Status * (float)this->_FrameHeight;
        this->_Action = false;
    }
    if (bomberman->getStatus() == 2 || bomberman->getStatus() == 3) {
        if (this->_Action && this->_Name == "Home")
            home(bomberman);
        else if (this->_Action && this->_Name == "Plus")
            plus(bomberman);
        else if (this->_Action && this->_Name == "Minus")
            minus(bomberman);
        if (this->_Name != "Sound")
            this->_Size.y = this->_Status * (float)this->_FrameHeight;
        this->_Action = false;
    }
    if (bomberman->getStatus() == 4) {
        if (this->_Action && this->_Name == "Play")
            start(bomberman);
        else if (this->_Action && this->_Name == "Home")
            home(bomberman);
        else if (this->_Action && this->_Name == "Plus")
            plus(bomberman);
        else if (this->_Action && this->_Name == "Minus")
            minus(bomberman);
        this->_Size.y = this->_Status * (float)this->_FrameHeight;
        this->_Action = false;
    }
    if (bomberman->getStatus() == 6) {
        if (this->_Action && this->_Name == "homePause")
            home(bomberman);
        this->_Size.y = this->_Status * (float)this->_FrameHeight;
        this->_Action = false;
    }
}

float Button::getFrameHeight(void) const
{
    return (this->_FrameHeight);
}
