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
        Player(const char * _name, int key_right, int key_up, int key_left, int key_down, int key_space, Vector3 _position);
        ~Player();

        Vector3 getPosition(void) const;
        void setPosition(const Vector3 position);

        Vector3 getPastPosition(void) const;
        void setPastPosition(const Vector3 past_position);

        Vector3 getNextPosition(void) const;
        void setNextPositionX(const float next_positionx);
        void setNextPositionZ(const float next_positionz);

        Vector2 getHeader(void) const;

        int getPlace(void) const;
        void setPlace(const int place);

        int getRight(void) const;
        int getUp(void) const;
        int getLeft(void) const;
        int getDown(void) const;
        int getBomb(void) const;

        int getBombNB(void) const;
        void setBombNB(const int bomb_nb);

        const char * getName(void) const;

        int getUpdate() const;
        void setUpdate(const int);

        void update(Game *bomberman);
        void draw(Game *bomberman);

    private:
        Color color = RED;
        Vector3 position;
        Vector3 past_position;
        Vector3 next_position;
        Vector3 size = {0.99f, 0.99f, 0.99f};
        Vector2 header = {0.0f, 0.0f};
        int place = 1;
        int right;
        int up;
        int left;
        int down;
        int bomb;
        int bomb_nb = 0;
        int _update = 0;
        const char * name;
};

#endif