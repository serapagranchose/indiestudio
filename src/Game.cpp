/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "indiestudio.hpp"

Game::Game()
{
    srand(time(NULL));
    InitWindow(this->window.screen_width, this->window.screen_height, "Anatoly Karpov!!!");
    SetTargetFPS(60);

    Button play;
    play.place = 0;
    play.texture = LoadTexture("../graphic/button/play.png");
    play.frame_height = (float)play.texture.height / 3;
    play.size = {0, 0, (float)play.texture.width, play.frame_height};
    play.bounds = {this->window.screen_width / 2.0f - play.texture.width / 2.0f, this->window.screen_height / 2.0f - play.texture.height / 3 / 2.0f, (float)play.texture.width, play.frame_height};
    this->buttons.push_back(play);

    this->camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    this->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    this->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    this->camera.fovy = 45.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
}

Game::~Game()
{
    UnloadTexture(this->map.flat_map);

    while (!this->players.empty())
        this->players.pop_back();
    while (!this->map.blocks.empty())
        this->map.blocks.pop_back();

    CloseWindow();
}

void Game::input()
{
    Vector2 mouse = GetMousePosition();
    if (this->debug == true)
        this->input_debug();

    for (int i = 0; i < this->buttons.size(); i++)
        this->buttons[i].input(this, mouse);

    if (this->status == 1){
        if (IsKeyDown(KEY_P)){
            Player onch;
            this->players.push_back(onch);
        } else if (IsKeyDown(KEY_B)){
            Block brick;
            this->map.blocks.push_back(brick);
        }

        if (IsKeyDown(KEY_RIGHT))
            this->players[0].position.x += 0.2f;
        else if (IsKeyDown(KEY_LEFT))
            this->players[0].position.x -= 0.2f;
        else if (IsKeyDown(KEY_DOWN))
            this->players[0].position.z += 0.2f;
        else if (IsKeyDown(KEY_UP))
            this->players[0].position.z -= 0.2f;
    }
}

void Game::input_debug()
{
    SetCameraMode(this->camera, CAMERA_FREE);
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(this->camera);
    if (this->status == 1)
        DrawGrid(10, 1.0f);
    for (int i = 0; i < this->players.size(); i++)
        this->players[i].draw(this);
    for (int i = 0; i < this->map.blocks.size(); i++)
        this->map.blocks[i].draw(this);
    EndMode3D();
    if (this->debug == true)
        this->draw_debug();
    for (int i = 0; i < this->buttons.size(); i++)
        this->buttons[i].draw(this);
    EndDrawing();
}

void Game::draw_debug()
{
    DrawText(TextFormat("game_status: %d", this->status), 10, 10, 20, GRAY);
    DrawFPS(200, 10);

    DrawText(TextFormat("camera_position: x:%.2f y:%.2f z:%.2f", this->camera.position.x, this->camera.position.y, this->camera.position.z), 10, 50, 20, GRAY);
    DrawText(TextFormat("camera_target: x:%.2f y:%.2f z:%.2f", this->camera.target.x, this->camera.target.y, this->camera.target.z), 10, 70, 20, GRAY);
    DrawText(TextFormat("camera_up: x:%.2f y:%.2f z:%.2f", this->camera.up.x, this->camera.up.y, this->camera.up.z), 10, 90, 20, GRAY);
    DrawText(TextFormat("camera_fovy: %.2f", this->camera.fovy), 10, 110, 20, GRAY);
    DrawText(TextFormat("camera_type: %d", this->camera.projection), 10, 130, 20, GRAY);

    DrawText(TextFormat("player_nb:\t%d", this->players.size()), 10, 170, 20, GRAY);
    DrawText(TextFormat("block_nb:\t%d", this->map.blocks.size()), 10, 190, 20, GRAY);
}

void Game::game_loop()
{
    while (!WindowShouldClose())
    {
        UpdateCamera(&this->camera);

        this->input();

        this->draw();
    }
}
