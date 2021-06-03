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
    InitAudioDevice();
    SetTargetFPS(60);

    Button play;
    play.place = 0;
    play.texture = LoadTexture("../graphic/button/play.png");
    play.size = {0, 0, (float)play.texture.width, (float)play.texture.height};
    play.bounds = {this->window.screen_width / 2.0f - play.texture.width / 2.0f, this->window.screen_height / 2.0f - play.texture.height / 2.0f, (float)play.texture.width, (float)play.texture.height};
    this->buttons.push_back(play);

    this->camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    this->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    this->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    this->camera.fovy = 45.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
}

Game::~Game()
{
    while (!this->players.empty())
        this->players.pop_back();
    while (!this->map.blocks.empty())
        this->map.blocks.pop_back();

    CloseWindow();
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
    draw_text();
    for (int i = 0; i < this->buttons.size(); i++)
        this->buttons[i].draw(this);
    EndDrawing();
}


void Game::draw_text()
{
    if (this->debug == true){
        DrawText(TextFormat("game_status: %d", this->status), 10, 10, 20, GRAY);
        DrawFPS(200, 10);

        DrawText(TextFormat("camera_position: x:%.2f y:%.2f z:%.2f", this->camera.position.x, this->camera.position.y, this->camera.position.z), 10, 50, 20, GRAY);
        DrawText(TextFormat("camera_target: x:%.2f y:%.2f z:%.2f", this->camera.target.x, this->camera.target.y, this->camera.target.z), 10, 70, 20, GRAY);
        DrawText(TextFormat("camera_up: x:%.2f y:%.2f z:%.2f", this->camera.up.x, this->camera.up.y, this->camera.up.z), 10, 90, 20, GRAY);
        DrawText(TextFormat("camera_fovy: %.2f", this->camera.fovy), 10, 110, 20, GRAY);
        DrawText(TextFormat("camera_type: %d", this->camera.projection), 10, 130, 20, GRAY);

        DrawText(TextFormat("player_nb:\t%d", this->players.size()), 10, 170, 20, GRAY);
        DrawText(TextFormat("block_nb:\t%d", this->map.blocks.size()), 10, 190, 20, GRAY);
        for (int i = 0; i < this->players.size(); i++)
            DrawText(TextFormat("%s:\npos = x:%0.2f y:%0.2f z:%0.2f\nnext_pos = x:%0.2f y:%0.2f z:%0.2f\nbomb_nb = %d", this->players[i].name, this->players[i].position.x, this->players[i].position.y, this->players[i].position.z, this->players[i].next_position.x, this->players[i].next_position.y, this->players[i].next_position.z, this->players[i].bomb_nb), 10, 230 + (i * 120), 20, GRAY);
    }
    for (int i = 0; i < this->players.size(); i++)
        if (this->status == this->players[i].place)
            DrawText(TextFormat("%s", this->players[i].name), (int)this->players[i].header.x - MeasureText(TextFormat("%s", this->players[i].name), 20) / 2, (int)this->players[i].header.y, 20, BLACK);
}

void Game::input()
{
    Vector2 mouse = GetMousePosition();

    if (this->debug == true)
        SetCameraMode(this->camera, CAMERA_FREE);

    for (int i = 0; i < this->buttons.size(); i++)
        this->buttons[i].input(this, mouse);

    if (this->status == 1){
        if (IsKeyPressed(KEY_P)){
            Player onch;
            this->players.push_back(onch);
        } else if (IsKeyPressed(KEY_B)){
            Block brick;
            this->map.blocks.push_back(brick);
        }

        for (int i = 0; i < this->players.size(); i++){
            //if (this->players[i].position.x == this->players[i].next_position.x){
                if (IsKeyDown(this->players[i].right))
                    this->players[i].next_position.x += 1;
                else if (IsKeyDown(this->players[i].left))
                    this->players[i].next_position.x -= 1;
            //}
            //if (this->players[i].position.z == this->players[i].next_position.z){
                if (IsKeyDown(this->players[i].up))
                    this->players[i].next_position.z -= 1;
                else if (IsKeyDown(this->players[i].down))
                    this->players[i].next_position.z += 1;
            //}
        }
    }
}

void Game::update()
{
    UpdateCamera(&this->camera);
    for (int i = 0; i < this->players.size(); i++)
        this->players[i].update(this);

    this->input();
}

void Game::game_loop()
{
    while (!WindowShouldClose())
    {
        this->update();

        this->draw();
    }
}
