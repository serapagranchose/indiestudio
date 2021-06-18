/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** File for Block class
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "Game.hpp"

class Block{
    public:
        Block();
        Block(Vector3 position, bool destructible, Color couleur);
        ~Block();

        void draw();
        void drawBlockTexture();
        void loadMousse();
        void loadHolyBlock();
        void loadGround();

        Vector3 getPosition(void) const;

        bool getDestructible(void) const;

        Vector3 getSize(void) const;
    private:
        Vector3 _Position = {-1.0f, 0.0f, -1.0f};
        Model _Model;
        Vector3 _Size = {1.0f, 1.0f, 1.0f};

        Color _Color = GREEN;
        bool _Destructible;
};

#endif
