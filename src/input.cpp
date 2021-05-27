/*
** EPITECH PROJECT, 2019
** input.cpp
** File description:
** input
*/

#include "indiestudio.hpp"

int buttons_input(Game *bomberman, Vector2 mouse)
{
    if (CheckCollisionPointRec(mouse, bomberman->buttons[0].bounds)){
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            bomberman->buttons[0].status = 2;
        else
            bomberman->buttons[0].status = 1;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            bomberman->buttons[0].action = true;
    } else
    bomberman->buttons[0].status = 0;

    if (bomberman->buttons[0].action)
        bomberman->status = 1;

    bomberman->buttons[0].size.y = bomberman->status * bomberman->buttons[0].frame_height;

    return (0);
}

int game_input(Game *bomberman)
{
    Vector2 mouse = GetMousePosition();

    buttons_input(bomberman, mouse);

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
