/*
** EPITECH PROJECT, 2021
** Bomb.hpp
** File description:
** Bomb.hpp
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Game.hpp"

class Bomb {
    public:
        Bomb(Vector3 position);
        ~Bomb();

        Vector3 getPosition(void) const;

        bool getExploding(void) const;

        std::chrono::steady_clock::time_point getTimer(void) const;

        void update(Game *bomberman);
        void Draw(void) const;
        void explode(Game *bomberman);

        bool operator==(const Bomb &bomb);
    private:
        Color _Color = BLACK;
        Vector3 _Position;
        Vector3 _Size = {0.5f, 0.5f, 0.5f};
        std::chrono::steady_clock::time_point _Timer;
        std::vector<Vector3> _Explosions_Positions;
        bool _Exploding = false;
        int _Tick = 0;
};

#endif /* !BOMB_HPP_ */
