/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Player class
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Game.hpp"

class Player{
    public:
        Player();
        Player(char *name, int key_right, int key_up, int key_left, int key_down, int key_space);
        ~Player();

        Color getColor(void) const;
        void setColor(const Color color);

        Vector3 getPosition(void) const;
        void setPosition(const Vector3 position);

        Vector3 getPastPosition(void) const;
        void setPastPosition(const Vector3 past_position);

        Vector3 getNextPosition(void) const;
        void setNextPositionX(const float next_positionx);
        void setNextPositionZ(const float next_positionz);

        Vector3 getSize(void) const;
        void setSize(const Vector3 size);

        Vector2 getHeader(void) const;
        void setHeader(const Vector2 header);

        int getPlace(void) const;
        void setPlace(const int place);

        int getRight(void) const;
        int getUp(void) const;
        int getLeft(void) const;
        int getDown(void) const;
        int getBomb(void) const;

        int getBombNB(void) const;
        void setBombNB(const int bomb_nb);

        const char *getName(void) const;
        void setName(const char *name);

        void update(Game *bomberman);
        void draw(Game *bomberman);

    private:
        Color color = RED;
        Vector3 position = {0.0f, 0.0f, 0.0f};
        Vector3 past_position;
        Vector3 next_position = position;
        Vector3 size = {0.99f, 0.99f, 0.99f};
        Vector2 header = {0.0f, 0.0f};
        int place = 1;
        int right = KEY_D;
        int up = KEY_W;
        int left = KEY_A;
        int down = KEY_S;
        int bomb = KEY_SPACE;
        int bomb_nb = 0;
        const char *name = "adrien karpapov";
};

#endif