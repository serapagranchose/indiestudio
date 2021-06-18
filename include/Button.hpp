/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for button class
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Game.hpp"
#include "Audio.hpp"

class Window;
class Audio;

class Button{
    public:
        Button();
        Button(Window *window, float heightScreen, float heightButton,std::string name, const char* path);
        ~Button();

        float getFrameHeight(void) const;

        void draw(Game *bomberman);
        void input(Game *bomberman, Vector2 mouse);
        void quit(Game *bomberman);
        void settings(Game *bomberman);
        void start(Game *bomberman);
        void credits(Game *bomberman);
        void load(Game *bomberman);
        void home(Game *bomberman);
        void plus(Game *bomberman);
        void minus(Game *bomberman);


        Rectangle _Size;
    private:
        Texture2D _Texture;
        Rectangle _Bounds;
        int _Status = 0;
        bool _Action = false;
        int _I = 0;
        std::string _Name;
        float _FrameHeight;
        Sound _Sound;
        int _Check = 0;
};

#endif
