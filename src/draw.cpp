/*
** EPITECH PROJECT, 2019
** draw.cpp
** File description:
** draw
*/

#include "indiestudio.hpp"

int draw3d(Game *bomberman)
{
    if (bomberman->status == 1){
        //DrawModel(bomberman->map.model, bomberman->map.position, 1.0f, WHITE);
        for (int i = 0; i < bomberman->players.size(); i++)
            DrawCubeV(bomberman->players[i].position, bomberman->players[i].size, bomberman->players[i].color);
        for (int i = 0; i < bomberman->map.blocks.size(); i++)
            DrawCubeV(bomberman->map.blocks[i].position, bomberman->map.blocks[i].size, bomberman->map.blocks[i].color);
        DrawTextureEx(bomberman->map.flat_map, (Vector2){ bomberman->window.screen_width - bomberman->map.flat_map.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
        DrawRectangleLines(bomberman->window.screen_width - bomberman->map.flat_map.width*4 - 20, 20, bomberman->map.flat_map.width*4, bomberman->map.flat_map.height*4, GREEN);
        DrawGrid(10, 1.0f);
    }

    return (0);
}

int draw2d(Game *bomberman)
{
    if (bomberman->status == 0){
        DrawTextureRec(bomberman->buttons[0].texture, bomberman->buttons[0].size, (Vector2){bomberman->buttons[0].bounds.x, bomberman->buttons[0].bounds.y}, WHITE);
    } else if (bomberman->status == 1){
        DrawText("SCORE", 658, 90, 10, RED);
        DrawText("LIFE", 658, 104, 10, RED);
        DrawFPS(10, 10);
    }

    return (0);
}

int draw(Game *bomberman)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(bomberman->camera);
    draw3d(bomberman);
    EndMode3D();
    draw2d(bomberman);
    EndDrawing();
}
