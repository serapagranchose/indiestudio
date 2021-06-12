/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for button class
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Game.hpp"

class Button{
    public:
        Button();
        ~Button();

        void draw(Game *bomberman);
        void input(Game *bomberman, Vector2 mouse);
        void quit(Game *bomberman);
        void settings(Game *bomberman);
        void start(Game *bomberman);

        int place = 0;
        Texture2D texture;
        Rectangle size;
        Rectangle bounds;
        int status = 0;
        bool action = false;
        int i = 0;
        std::string name;
        float frameHeight;

        Model model;
};

#endif