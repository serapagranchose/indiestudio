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
    InitWindow(this->_Window._ScreenWidth, this->_Window._ScreenHeight, "Anatoly Karpov!!!");
    SetTargetFPS(60);
    ToggleFullscreen();
    this->_Audio = new Audio();
    this->_Map = new Map();
    this->_Audio->init(this);
    this->initButton();

    this->_Camera.position = Vector3 {0.0f, 20.0f, 6.0f};
    this->_Camera.target = Vector3 {0.0f, 0.0f, 0.0f};
    this->_Camera.up = Vector3 {0.0f, 1.0f, 0.0f};
    this->_Camera.fovy = 45.0f;
    this->_Camera.projection = CAMERA_PERSPECTIVE;

    this->_FramesAnim = 0;
    this->_ImageAnim = LoadImageAnim("assets/graphic/background/menu.gif", &this->_FramesAnim);
    this->_Menu = LoadTextureFromImage(this->_ImageAnim);

    this->_LastGifTime = GetTime();
    this->_GifFrameRate = 1 / 20.0f;
}

Game::~Game()
{
    while (!this->_Players.empty())
        this->_Players.pop_back();
    while (!this->_Map->_Blocks.empty())
        this->_Map->_Blocks.pop_back();
    CloseWindow();
}

void Game::initButton()
{
    Button *play = new Button(&this->_Window, 3.0f, 4.5f, "Play", "assets/graphic/button/play.png");
    Button *settings = new Button(&this->_Window, 1.325f, 1.0f, "Settings", "assets/graphic/button/settings.png");
    Button *quit = new Button(&this->_Window, 1.15f, 1.0f, "Quit", "assets/graphic/button/quit.png");
    Button *credits = new Button(&this->_Window, 1.7f, 3.5f, "Credits", "assets/graphic/button/credits.png");
    Button *load = new Button(&this->_Window, 2.15f, 3.5f, "Continue", "assets/graphic/button/continue.png");
    Button *home = new Button(&this->_Window, 1.15f, 1.0f, "Home", "assets/graphic/button/home.png");
    Button *sound = new Button(&this->_Window, 1.5f, 3.5f, "Sound", "assets/graphic/button/volume.png");
    Button *plus = new Button(&this->_Window, 1.62f, 3.5f, "Plus", "assets/graphic/button/plus.png");
    Button *minus = new Button(&this->_Window, 1.62f, 3.5f, "Minus", "assets/graphic/button/minus.png");
    Button *resume = new Button(&this->_Window, 3.0f, 4.5f, "Resume", "assets/graphic/button/resume.png");
    Button *homePause = new Button(&this->_Window, 2.15f, 3.5f, "homePause", "assets/graphic/button/home.png");
    Button *save = new Button(&this->_Window, 1.6f, 1.0f, "Save", "assets/graphic/button/save.png");
    this->_Buttons.push_back(*play);
    this->_Buttons.push_back(*settings);
    this->_Buttons.push_back(*quit);
    this->_Buttons.push_back(*credits);
    this->_Buttons.push_back(*load);
    this->_Buttons.push_back(*home);
    this->_Buttons.push_back(*sound);
    this->_Buttons.push_back(*plus);
    this->_Buttons.push_back(*minus);
    this->_Buttons.push_back(*resume);
    this->_Buttons.push_back(*homePause);
    this->_Buttons.push_back(*save);
}

void Game::initPlayer()
{
    for (int i = 0; i != _NamePlayer.size(); i++) {
        if (_NamePlayer[i] == "One") {
            Player *playerOne = new Player("Player 1", false, KEY_D, KEY_W, KEY_A, KEY_S, KEY_SPACE, this->_CoordPlayer[i]);
            this->_Players.push_back(*playerOne);
        }
        if (_NamePlayer[i] == "Two") {
            Player *playerTwo = new Player("Player 2", false, KEY_RIGHT, KEY_UP, KEY_LEFT, KEY_DOWN, KEY_ENTER, this->_CoordPlayer[i]);
            this->_Players.push_back(*playerTwo);
        }
        if (_NamePlayer[i] == "Three") {
            Player *playerThree = new Player("Player 3", false, KEY_J, KEY_Y, KEY_G, KEY_H, KEY_K, this->_CoordPlayer[i]);
            this->_Players.push_back(*playerThree);
        }
        if (_NamePlayer[i] == "Four") {
            Player *playerFour = new Player("Player 4", false, KEY_B, KEY_F, KEY_C, KEY_V, KEY_X, this->_CoordPlayer[i]);
            this->_Players.push_back(*playerFour);
        }
    }
}

void Game::pushPlayer(const char *opt)
{
    bool artificial_intelligence = false;

    if (strcmp(opt, "ai") == 0)
        artificial_intelligence = true;

    if (this->_Players.size() == 0) {
        Player *player = new Player("Player 1", artificial_intelligence, KEY_D, KEY_W, KEY_A, KEY_S, KEY_SPACE, {-5.0f, 0.0f, -5.0f});
        this->_Players.push_back(*player);
    } else if (this->_Players.size() == 1){
        Player *player = new Player("Player 2", artificial_intelligence, KEY_RIGHT, KEY_UP, KEY_LEFT, KEY_DOWN, KEY_ENTER, {5.0f, 0.0f, -5.0f});
        this->_Players.push_back(*player);
    } else if (this->_Players.size() == 2){
        Player *player = new Player("Player 3", artificial_intelligence, KEY_J, KEY_Y, KEY_G, KEY_H, KEY_K, {-5.0f, 0.0f, 5.0f});
        this->_Players.push_back(*player);
    } else if (this->_Players.size() == 3){
        Player *player = new Player("Player 4", artificial_intelligence, KEY_B, KEY_F, KEY_C, KEY_V, KEY_X, {5.0f, 0.0f, 5.0f});
        this->_Players.push_back(*player);
    }
}

void Game::popPlayer()
{
    this->_Players.pop_back();
}

void Game::draw()
{
    BeginDrawing();
    BeginMode3D(this->_Camera);
    ClearBackground(DARKGRAY);
    if (this->_Status == 1 || this->_Status == 5) {
        for (int i = 0; i < this->_Players.size(); i++) {
            this->_Players[i].draw(this);
            for (int y = 0; y < this->_Players[i].getBombs().size(); y++)
                this->_Players[i].getBombs()[y].Draw();
        }
        for (int i = 0; i < this->_Map->_Blocks.size(); i++)
            this->_Map->_Blocks[i].drawBlockTexture();
    }
    EndMode3D();
    draw_text();
    if (this->_Status == 0) {
        DrawTexture(this->_Menu, GetScreenWidth() / 2 - this->_Menu.width/2, GetScreenHeight()/2 - this->_Menu.height / 2, WHITE);
        DrawText(TextSubtext("INDIE STUDIO", 0, this->_FramesCount/12), 100, 160, 100, DARKBLUE);
        for (int i = 0; i < 5; i++)
            this->_Buttons[i].draw(this);
    }
    if (this->_Status == 5) {
        DrawText(TextSubtext("PAUSE", 0, this->_FramesCount/12), 790, 80, 100, DARKBLUE);
        for (int i = 9; i != 12; i++)
            this->_Buttons[i].draw(this);
    }
    if (this->_Status == 2) {
        DrawTexture(this->_Menu, GetScreenWidth() / 2 - this->_Menu.width/2, GetScreenHeight()/2 - this->_Menu.height / 2, WHITE);
        DrawText("SETTINGS", 160, 160, 100, DARKBLUE);
        for (int i = 5; i < 9; i++)
            this->_Buttons[i].draw(this);
    }
    if (this->_Status == 3) {
        DrawTexture(this->_Menu, GetScreenWidth() / 2 - this->_Menu.width/2, GetScreenHeight()/2 - this->_Menu.height / 2, WHITE);
        DrawText("CREDITS", 170, 160, 100, DARKBLUE);
        this->_Buttons[5].draw(this);
    }
    if (this->_Status == 4) {
        DrawText(TextSubtext("PLAYER SELECTION", 0, this->_FramesCount/12), 100, 160, 100, DARKBLUE);
        DrawText(TextFormat("%d", this->_Players.size()), 420, 650, 75, PURPLE);
        this->_Buttons[0].draw(this);
        this->_Buttons[5].draw(this);
        this->_Buttons[7].draw(this);
        this->_Buttons[8].draw(this);
    }
    if (this->_Status == 6) {
        if (this->_Players.size() == 1) {
            DrawText(TextSubtext("You Win!", 0, this->_FramesCount/12), 790, 80, 100, DARKBLUE);
        }
        if (this->_Players.size() == 0) {
            DrawText(TextSubtext("You Lose", 0, this->_FramesCount/12), 790, 80, 100, DARKBLUE);
        }
        this->_Buttons[10].draw(this);
    }
    EndDrawing();
}

void Game::draw_text()
{
    if (this->_Debug == true){
        DrawText(TextFormat("game_status: %d", this->_Status), 10, 10, 20, GRAY);
        DrawFPS(200, 10);

        DrawText(TextFormat("camera_position: x:%.2f y:%.2f z:%.2f", this->_Camera.position.x, this->_Camera.position.y, this->_Camera.position.z), 10, 50, 20, GRAY);
        DrawText(TextFormat("camera_target: x:%.2f y:%.2f z:%.2f", this->_Camera.target.x, this->_Camera.target.y, this->_Camera.target.z), 10, 70, 20, GRAY);
        DrawText(TextFormat("camera_up: x:%.2f y:%.2f z:%.2f", this->_Camera.up.x, this->_Camera.up.y, this->_Camera.up.z), 10, 90, 20, GRAY);
        DrawText(TextFormat("camera_fovy: %.2f", this->_Camera.fovy), 10, 110, 20, GRAY);
        DrawText(TextFormat("camera_type: %d", this->_Camera.projection), 10, 130, 20, GRAY);

        DrawText(TextFormat("player_nb:\t%d", this->_Players.size()), 10, 170, 20, GRAY);
        DrawText(TextFormat("block_nb:\t%d", this->_Map->_Blocks.size()), 10, 190, 20, GRAY);
        for (int i = 0; i < this->_Players.size(); i++)
            DrawText(TextFormat("%s:\npos = x:%0.2f y:%0.2f z:%0.2f\nnext_pos = x:%0.2f y:%0.2f z:%0.2f\nbomb_nb = %d", this->_Players[i].getName(), this->_Players[i].getPosition().x, this->_Players[i].getPosition().y, this->_Players[i].getPosition().z, this->_Players[i].getNextPosition().x, this->_Players[i].getNextPosition().y, this->_Players[i].getNextPosition().z, this->_Players[i].getBombNumber()), 10, 230 + (i * 120), 20, GRAY);
    }
    if (this->_Status == 1 || this->_Status == 5)
        for (int i = 0; i < this->_Players.size(); i++){
            if (this->_Players[i].getArtificialIntelligence() == false)
                DrawText(TextFormat("%s", this->_Players[i].getName()), (int)this->_Players[i].getHeader().x - MeasureText(TextFormat("%s", this->_Players[i].getName()), 20) / 2, (int)this->_Players[i].getHeader().y, 20, BLACK);
            else
                DrawText(TextFormat("%s (AI)", this->_Players[i].getName()), (int)this->_Players[i].getHeader().x - MeasureText(TextFormat("%s (AI)", this->_Players[i].getName()), 20) / 2, (int)this->_Players[i].getHeader().y, 20, BLACK);
        }
}

void Game::input()
{
    Vector2 mouse = GetMousePosition();

    for (int i = 0; i < this->_Buttons.size(); i++)
        this->_Buttons[i].input(this, mouse);
    if (this->_Status == 1) {
        for (int i = 0; i < this->_Players.size(); i++) {
            if (this->_Players[i].getBombNumber() > 0 && IsKeyDown(this->_Players[i].getKeyBomb())) {
                if (this->_Players[i].can_I_plant() == 1) {
                    this->_Players[i].drop_bomb();
                    this->_Players[i].setBombNumber(this->_Players[i].getBombNumber() - 1);
                }
            }
            if (this->_Players[i].getNextPosition().x == this->_Players[i].getPosition().x) {
                if (IsKeyDown(this->_Players[i].getKeyRight())) {
                    this->_Players[i].setUpdate(1);
                    this->_Players[i].setNextPositionX(this->_Players[i].getNextPosition().x + 0.1f);
                }
                if (IsKeyDown(this->_Players[i].getKeyLeft())) {
                    this->_Players[i].setUpdate(1);
                    this->_Players[i].setNextPositionX(this->_Players[i].getNextPosition().x - 0.1f);
                }
            }
            if (this->_Players[i].getNextPosition().z == this->_Players[i].getPosition().z && this->_Players[i].getUpdate() != 1) {
                if (IsKeyDown(this->_Players[i].getKeyUp()))
                    this->_Players[i].setNextPositionZ(this->_Players[i].getNextPosition().z - 0.1f);
                if (IsKeyDown(this->_Players[i].getKeyDown()))
                    this->_Players[i].setNextPositionZ(this->_Players[i].getPosition().z + 0.1f);
            }
        }
    }
}

void Game::update()
{
    if (this->_Status == 0) {
        if (WindowShouldClose())
            this->_Status = -1;
    }
    if (this->_Status == 4 || this->_Status == 5 || this->_Status == 2) {
        if (WindowShouldClose()) {
            this->_Players.clear();
            this->_CoordPlayer.clear();
            this->_NamePlayer.clear();
            this->_Status = 0;
        }
    }
    if (this->_Status == 6 && WindowShouldClose()) {
        this->_Map->saveMap(this);
        this->_Status = 0;
    }
    if (this->_Status == 1 && WindowShouldClose())
        this->_Status = 5;
    this->_Audio->update();
    this->_FramesCount++;
    this->_Buttons[6]._Size.y = round((this->_Audio->getVolume() + 0.1f) * 10) * (this->_Buttons[6].getFrameHeight());
    if (GetTime() - this->_LastGifTime >= this->_GifFrameRate) {
        this->_FramesAnimCount++;
        if (this->_FramesAnimCount >= this->_FramesAnim)
            this->_FramesAnimCount = 0;
        unsigned int nextFrameDataOffset = this->_Menu.width * this->_Menu.height * 4 * this->_FramesAnimCount;
        UpdateTexture(this->_Menu, ((unsigned char *)this->_ImageAnim.data) + nextFrameDataOffset);
        this->_LastGifTime = GetTime();
    }
    this->input();
    UpdateCamera(&this->_Camera);
    if (this->_Debug == true)
        SetCameraMode(this->_Camera, CAMERA_FREE);
    if (this->_Status == 1) {
        for (int i = 0; i < this->_Players.size(); i++) {
            if (this->_Players[i].getAlive() == false)
                this->_Players.erase(this->_Players.begin() + i);
            else
                this->_Players[i].update(this);
        }
    }
}

void Game::game_loop()
{
    this->_Audio->setMusic("assets/audio/menu.mp3");
    this->_Audio->playMusic();
    while (this->_Status != -1)
    {
        this->update();
        this->draw();
        if (this->_Status == 1)
            this->win_or_lose();
    }
    UnloadTexture(this->_Menu);
    this->_Audio->endMusic();
}

int Game::getStatus() const
{
    return (this->_Status);
}

void Game::setStatus(const int _status)
{
    this->_Status = _status;
}

Map* Game::getMap() const
{
    return (this->_Map);
}

Audio *Game::getAudio() const
{
    return (this->_Audio);
}

std::vector<Player> Game::getPlayers() const
{
    return (this->_Players);
}

Camera Game::getCamera() const
{
    return (this->_Camera);
}

int Game::getGenerated() const
{
    return (this->_MapGenerated);
}

void Game::setDebug(const bool _bool)
{
    this->_Debug = _bool;
}

void Game::win_or_lose(void)
{
    if (this->_Players.size() <= 1) {
        this->_Status = 6;
    }
}
