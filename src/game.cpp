/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "indiestudio.hpp"

int setdown(Game *bomberman)
{
    UnloadTexture(bomberman->map.flat_map);

    printf("player nb:%ld\n", bomberman->players.size());
    printf("game_status:%d\n", bomberman->status);
    printf("position:\nx:%.2f y:%.2f z:%.2f\n\n", bomberman->camera.position.x, bomberman->camera.position.y, bomberman->camera.position.z); // Camera position
    printf("target:\nx:%.2f y:%.2f z:%.2f\n\n", bomberman->camera.target.x, bomberman->camera.target.y, bomberman->camera.target.z);      // Camera looking at point
    printf("up:\nx:%.2f y:%.2f z:%.2f\n\n", bomberman->camera.up.x, bomberman->camera.up.y, bomberman->camera.up.z);          // Camera up vector (rotation towards target)
    printf("fovy:\t%.2f\n\n", bomberman->camera.fovy);                               // Camera field-of-view Y
    printf("type:\t%d\n", bomberman->camera.projection);

    while (!bomberman->players.empty())
        bomberman->players.pop_back();
    while (!bomberman->map.blocks.empty())
        bomberman->map.blocks.pop_back();

    CloseWindow();

    return (0);
}

int game_loop(Game *bomberman)
{
    while (!WindowShouldClose())
    {
        UpdateCamera(&bomberman->camera);

        game_input(bomberman);

//draw(bomberman); is a segfault cause
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(bomberman->camera);
        draw3d(bomberman);
        EndMode3D();
        draw2d(bomberman);
        EndDrawing();
    }
    return (0);
}

int setup(Game *bomberman)
{
    srand(time(NULL));
    InitWindow(bomberman->window.screen_width, bomberman->window.screen_height, "Anatoly Karpov!!!");
    SetTargetFPS(60);

    Button play;
    play.texture = LoadTexture("../graphic/button/play.png");
    play.frame_height = (float)play.texture.height / 3;
    play.size = {0, 0, (float)play.texture.width, play.frame_height};
    play.bounds = {bomberman->window.screen_width / 2.0f - play.texture.width / 2.0f, bomberman->window.screen_height / 2.0f - play.texture.height / 3 / 2.0f, (float)play.texture.width, play.frame_height};
    bomberman->buttons.push_back(play);

    bomberman->camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    bomberman->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    bomberman->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    bomberman->camera.fovy = 45.0f;
    bomberman->camera.projection = CAMERA_PERSPECTIVE;
//    SetCameraMode(bomberman->camera, CAMERA_FREE);

    return (0);
}
