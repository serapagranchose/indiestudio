/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Player class
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Game.hpp"
#include "Bomb.hpp"

class Bomb;

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

        int getStatus(void) const;
        void setStatus(const int status);

        void update(Game *bomberman);
        void draw(Game *bomberman);
        int can_I_plant(void) const;

        std::vector<Bomb> getBomb_List(void) const;

        void drop_bomb(void);

    private:
        Color color = RED;
        Vector3 position;
        Vector3 past_position;
        Vector3 next_position;
        Vector3 size = {0.5f, 0.8f, 0.5f};
        Vector2 header = {0.0f, 0.0f};
        int place = 1;
        int right;
        int up;
        int left;
        int down;
        int bomb;
        int bomb_nb = 10;
        int _update = 0;
        int _Status = 1;
        const char * name;
        std::vector<Bomb> _Bomb_list;
};

#endif