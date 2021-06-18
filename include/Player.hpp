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
        void setPastPosition(const Vector3 position);
        Vector3 getNextPosition(void) const;
        void setNextPositionX(const float x);
        void setNextPositionZ(const float z);
        Vector2 getHeader(void) const;
        int getKeyRight(void) const;
        void setKeyRight(const int key_right);
        int getKeyUp(void) const;
        void setKeyUp(const int key_up);
        int getKeyLeft(void) const;
        void setKeyLeft(const int key_left);
        int getKeyDown(void) const;
        void setKeyDown(const int key_down);
        int getKeyBomb(void) const;
        void setKeyBomb(const int key_bomb);
        int getBombNumber(void) const;
        void setBombNumber(const int bomb_number);
        const char *getName(void) const;
        void setName(const char *name);
        int getUpdate() const;
        void setUpdate(const int);
        std::vector<Bomb> getBombs(void) const;

        bool getAlive(void) const;
        void setAlive(const bool alive);

        void update(Game *bomberman);
        void draw(Game *bomberman);
        int can_I_plant(void) const;
        void drop_bomb(void);

    private:
        Color _Color = RED;
        Vector3 _Position;
        Vector3 _PastPosition;
        Vector3 _NextPosition;
        Vector3 _Size = {0.5f, 0.8f, 0.5f};
        Vector2 _Header = {0.0f, 0.0f};
        int _KeyRight;
        int _KeyUp;
        int _KeyLeft;
        int _KeyDown;
        int _KeyBomb;
        int _BombNumber = 10;
        int _Update = 0; //whut
        const char * _Name;
        bool _Alive = true;
        std::vector<Bomb> _Bombs;
};

#endif
