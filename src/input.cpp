/*
** EPITECH PROJECT, 2019
** input.cpp
** File description:
** input
*/

#include "indiestudio.hpp"

int game_input(Game *bomberman)
{
    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, bomberman->buttons[0].bounds))
        bomberman->status = 1;
    if (IsKeyDown(KEY_S))
        bomberman->status = 1;

    if (bomberman->status == 1){
        if (IsKeyDown(KEY_P)){
            Player onch;
            bomberman->players.push_back(onch);
        } else if (IsKeyDown(KEY_B)){
            Block brick;
            bomberman->map.blocks.push_back(brick);
        }

        if (IsKeyDown(KEY_RIGHT))
            bomberman->players[0].position.x += 0.2f;
        else if (IsKeyDown(KEY_LEFT))
            bomberman->players[0].position.x -= 0.2f;
        else if (IsKeyDown(KEY_DOWN))
            bomberman->players[0].position.z += 0.2f;
        else if (IsKeyDown(KEY_UP))
            bomberman->players[0].position.z -= 0.2f;
    }

    return (0);
}
