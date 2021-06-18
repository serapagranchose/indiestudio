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

        void update();
        void Draw(void) const;
        void explode(Game *bomberman);
    private:
        Color _Color = BLACK;
        Vector3 _Position;
        Vector3 _Size = {0.5f, 0.5f, 0.5f};
        std::chrono::_V2::steady_clock::time_point _Timer;
        std::vector<Vector3> _Explosions_Positions;
        int _Tick = 0;
};

#endif /* !BOMB_HPP_ */
