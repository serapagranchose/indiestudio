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
        void quit();
        void settings();
        void start();

        int place = 0;
        Texture2D texture;
        Rectangle size;
        Rectangle bounds;
        int status = 0;
        bool action = false;
        int i = 0;
        std::string name;

        Model model;
};

#endif