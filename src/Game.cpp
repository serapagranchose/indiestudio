/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "Game.hpp"
#include "Block.hpp"
#include "Player.hpp"

Game::Game()
{
    srand(time(NULL));
    InitWindow(this->window.screen_width, this->window.screen_height, "Anatoly Karpov!!!");
    SetTargetFPS(60);
    this->initPlayer();
    this->audio = new AllMusic();
    this->map = new Map();
    audio->init(this);
    this->initButton();

    this->camera.position = Vector3 {0.0f, 15.0f, 10.0f};
    this->camera.target = Vector3 {0.0f, 0.0f, 0.0f};
    this->camera.up = Vector3 {0.0f, 1.0f, 0.0f};
    this->camera.fovy = 45.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;

    this->framesAnim = 0;
    this->imageAnim = LoadImageAnim("../graphic/menu/menu.gif", &this->framesAnim);
    this->menu = LoadTextureFromImage(this->imageAnim);

    this->lastGifTime = GetTime();
    this->gifFrameRate = 1 / 20.0f;
}

Game::~Game()
{
    while (!this->players.empty())
        this->players.pop_back();
    while (!this->map->getBlock().empty())
        this->map->blocks.pop_back();
    CloseWindow();
}

void Game::initButton()
{
    Button *play = new Button(&this->window, 3.0f, 4.5f, "Play", "../graphic/button/play.png");
    Button *settings = new Button(&this->window, 2.0f, 3.5f, "Settings", "../graphic/button/settings.png");
    Button *quit = new Button(&this->window, 1.15f, 1.0f, "Quit", "../graphic/button/quit.png");
    Button *credits = new Button(&this->window, 1.5f, 3.5f, "Credits", "../graphic/button/credits.png");
    Button *home = new Button(&this->window, 1.15f, 1.0f, "Home", "../graphic/button/home.png");
    Button *sound = new Button(&this->window, 1.5f, 3.5f, "Sound", "../graphic/button/sound.png");
    Button *plus = new Button(&this->window, 1.62f, 3.5f, "Plus", "../graphic/button/plus.png");
    Button *minus = new Button(&this->window, 1.62f, 3.5f, "Minus", "../graphic/button/minus.png");
    this->buttons.push_back(*play);
    this->buttons.push_back(*settings);
    this->buttons.push_back(*quit);
    this->buttons.push_back(*credits);
    this->buttons.push_back(*home);
    this->buttons.push_back(*sound);
    this->buttons.push_back(*plus);
    this->buttons.push_back(*minus);
}

void Game::initPlayer()
{
    Player *playerOne = new Player("Player 1" ,KEY_D, KEY_W, KEY_A, KEY_S, KEY_SPACE, {-5.0f, 0.0f, -5.0f});
    Player *playerTwo = new Player("Player 2" ,KEY_RIGHT, KEY_UP, KEY_LEFT, KEY_DOWN, KEY_M, {5.0f, 0.0f, -5.0f});
    //Player *playerThree = new Player("Player 3" ,KEY_Y, KEY_G, KEY_H, KEY_J, KEY_B, {-5.0f, 0.0f, 5.0f});
    //Player *playerFour = new Player("Player 4" ,KEY_M, KEY_K, KEY_L, KEY_O, KEY_PERIOD, {5.0f, 0.0f, 5.0f});
    this->players.push_back(*playerOne);
    this->players.push_back(*playerTwo);
    //this->players.push_back(*playerThree);
    //this->players.push_back(*playerFour);
}

void Game::draw()
{
    BeginDrawing();
    BeginMode3D(this->camera);
    ClearBackground(RAYWHITE);
    if (this->status == 1) {
        DrawGrid(13, 1.0f);
        for (int i = 0; i < this->players.size(); i++)
            this->players[i].draw(this);
        for (int i = 0; i < this->map->getBlock().size(); i++)
            this->map->getBlock()[i].draw();
    }
    EndMode3D();
    draw_text();
    if (this->status == 0) {
        DrawTexture(this->menu, GetScreenWidth() / 2 - this->menu.width/2, GetScreenHeight()/2 - this->menu.height / 2, WHITE);
        DrawText(TextSubtext("INDIE STUDIO", 0, this->framesCount/12), 100, 160, 100, DARKBLUE);
        for (int i = 0; i < 4; i++)
            this->buttons[i].draw(this);
    }
    if (this->status == 2) {
        DrawTexture(this->menu, GetScreenWidth() / 2 - this->menu.width/2, GetScreenHeight()/2 - this->menu.height / 2, WHITE);
        DrawText("SETTINGS", 160, 160, 100, DARKBLUE);
        for (int i = 4; i != 8; i++)
            this->buttons[i].draw(this);
    }
    if (this->status == 3) {
        DrawTexture(this->menu, GetScreenWidth() / 2 - this->menu.width/2, GetScreenHeight()/2 - this->menu.height / 2, WHITE);
        DrawText("CREDITS", 170, 160, 100, DARKBLUE);
        this->buttons[4].draw(this);
    }
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
        DrawText(TextFormat("block_nb:\t%d", this->map->getBlock().size()), 10, 190, 20, GRAY);
        for (int i = 0; i < this->players.size(); i++)
            DrawText(TextFormat("%s:\npos = x:%0.2f y:%0.2f z:%0.2f\nnext_pos = x:%0.2f y:%0.2f z:%0.2f\nbomb_nb = %d", this->players[i].getName(), this->players[i].getPosition().x, this->players[i].getPosition().y, this->players[i].getPosition().z, this->players[i].getNextPosition().x, this->players[i].getNextPosition().y, this->players[i].getNextPosition().z, this->players[i].getBombNB()), 10, 230 + (i * 120), 20, GRAY);
    }
    if (this->status == 1) {
        for (int i = 0; i < this->players.size(); i++) {
            if (this->status == this->players[i].getPlace())
                DrawText(TextFormat("%s", this->players[i].getName()), (int)this->players[i].getHeader().x - MeasureText(TextFormat("%s", this->players[i].getName()), 20) / 2, (int)this->players[i].getHeader().y, 20, BLACK);
        }
    }
}

void Game::input()
{
    Vector2 mouse = GetMousePosition();

    for (int i = 0; i < this->buttons.size(); i++)
        this->buttons[i].input(this, mouse);

    if (this->status == 1) {
        for (int i = 0; i < this->players.size(); i++) {
            if (this->players[i].getNextPosition().x == this->players[i].getPosition().x) {
                if (IsKeyDown(this->players[i].getRight())) {
                    this->players[i].setUpdate(1);
                    this->players[i].setNextPositionX(this->players[i].getNextPosition().x + 1);
                }
                if (IsKeyDown(this->players[i].getLeft())) {
                    this->players[i].setUpdate(1);
                    this->players[i].setNextPositionX(this->players[i].getNextPosition().x - 1);
                }
            }
            if (this->players[i].getNextPosition().z == this->players[i].getPosition().z && this->players[i].getUpdate() != 1) {
                if (IsKeyDown(this->players[i].getUp()))
                    this->players[i].setNextPositionZ(this->players[i].getNextPosition().z - 1);
                if (IsKeyDown(this->players[i].getDown()))
                    this->players[i].setNextPositionZ(this->players[i].getPosition().z + 1);
            }
        }
    }
}

void Game::update()
{
    audio->update();
    this->framesCount++;
    this->buttons[5].size.y = ((audio->getVolume() - 0.1) * 10)* this->buttons[5].getFrameHeight();
    if (GetTime() - this->lastGifTime >= this->gifFrameRate) {
        this->framesAnimCount++;
        if (this->framesAnimCount >= framesAnim) 
            this->framesAnimCount = 0;
        unsigned int nextFrameDataOffset = this->menu.width * this->menu.height * 4 * this->framesAnimCount;
        UpdateTexture(this->menu, ((unsigned char *)this->imageAnim.data) + nextFrameDataOffset);
        this->lastGifTime = GetTime();
    }
    this->input();
    UpdateCamera(&this->camera);
    if (this->debug == true)
        SetCameraMode(this->camera, CAMERA_FREE);
    if (this->status == 1) {
        for (int i = 0; i < this->players.size(); i++) {
            this->players[i].update(this);
        }
    }
}

void Game::game_loop()
{
    audio->setMusic("../audio/menu.mp3");
    audio->playMusic();
    while (!WindowShouldClose() && this->status != -1)
    {
        this->update();
        this->draw();
    }
    this->map->saveMap(this);
    UnloadTexture(this->menu);
    audio->endMusic();
}

int Game::getStatus() const
{
    return (this->status);
}

void Game::setStatus(const int _status)
{
    this->status = _status;
}

Map* Game::getMap() const
{
    return (this->map);
}

AllMusic* Game::getMusic() const
{
    return (this->audio);
}

std::vector<Player> Game::getPlayer() const
{
    return (this->players);
}

Camera Game::getCamera() const
{
    return (this->camera);
}

int Game::getGenerated() const
{
    return (this->map_generated);
}

void Game::setDebug(const bool _bool)
{
    this->debug = _bool;
}