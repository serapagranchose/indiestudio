/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "Player.hpp"

Player::Player()
{
}

Player::Player(const char *name, int key_right, int key_up, int key_left, int key_down, int key_space, Vector3 position)
{
    this->_Name = name;
    this->_KeyRight = key_right;
    this->_KeyUp = key_up;
    this->_KeyLeft = key_left;
    this->_KeyDown = key_down;
    this->_KeyBomb = key_space;
    this->_Position = position;
    this->_NextPosition = position;
}

Player::~Player()
{
}

Vector3 Player::getPosition(void) const
{
    return (this->_Position);
}

void Player::setPosition(const Vector3 position)
{
    this->_Position = position;
}

Vector3 Player::getPastPosition(void) const
{
    return (this->_PastPosition);
}

void Player::setPastPosition(const Vector3 position)
{
    this->_PastPosition = position;
}

Vector3 Player::getNextPosition(void) const
{
    return (this->_NextPosition);
}

void Player::setNextPositionX(const float x)
{
    this->_NextPosition.x = x;
}

void Player::setNextPositionZ(const float z)
{
    this->_NextPosition.z = z;
}

Vector2 Player::getHeader(void) const
{
    return (this->_Header);
}

int Player::getKeyRight(void) const
{
    return (this->_KeyRight);
}

int Player::getKeyUp(void) const
{
    return (this->_KeyUp);
}

int Player::getKeyLeft(void) const
{
    return (this->_KeyLeft);
}

int Player::getKeyDown(void) const
{
    return (this->_KeyDown);
}

int Player::getKeyBomb(void) const
{
    return (this->_KeyBomb);
}

int Player::getBombNumber(void) const
{
    return (this->_BombNumber);
}

void Player::setBombNumber(const int bomb_number)
{
    this->_BombNumber = bomb_number;
}

const char * Player::getName(void) const
{
    return (this->_Name);
}

int Player::getUpdate(void) const
{
    return (this->_Update);
}

void Player::setUpdate(const int update)
{
    this->_Update = update;
}

std::vector<Bomb> Player::getBombs(void) const
{
    return (this->_Bombs);
}

bool Player::getAlive(void) const
{
    return (this->_Alive);
}

void Player::setAlive(const bool alive)
{
    this->_Alive = alive;
}

void Player::update(Game *bomberman)
{
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    double elapsed_time_ns;

    this->_Header = GetWorldToScreen(Vector3{this->_Position.x, this->_Position.y + 1.5f, this->_Position.z}, bomberman->getCamera());
    this->_PastPosition = this->_Position;
    for (int i = 0; i < bomberman->getMap()->_Blocks.size(); i++) {
        if (CheckCollisionBoxes(
                BoundingBox{
                    Vector3{this->_NextPosition.x - this->_Size.x / 2, this->_NextPosition.y - this->_Size.y / 2, this->_NextPosition.z - this->_Size.z / 2},
                    Vector3{this->_NextPosition.x + this->_Size.x / 2, this->_NextPosition.y + this->_Size.y / 2, this->_NextPosition.z + this->_Size.z / 2}},
                BoundingBox{
                    Vector3{bomberman->getMap()->_Blocks[i].getPosition().x - bomberman->getMap()->_Blocks[i].getSize().x / 2, bomberman->getMap()->_Blocks[i].getPosition().y - bomberman->getMap()->_Blocks[i].getSize().y / 2, bomberman->getMap()->_Blocks[i].getPosition().z - bomberman->getMap()->_Blocks[i].getSize().z / 2},
                    Vector3{bomberman->getMap()->_Blocks[i].getPosition().x + bomberman->getMap()->_Blocks[i].getSize().x / 2, bomberman->getMap()->_Blocks[i].getPosition().y + bomberman->getMap()->_Blocks[i].getSize().y / 2, bomberman->getMap()->_Blocks[i].getPosition().z + bomberman->getMap()->_Blocks[i].getSize().z / 2}}))
        {
            this->_Position = this->_PastPosition;
            this->_NextPosition = this->_Position;
        }
    }
    if (round(this->_Position.x * 10) < round(this->_NextPosition.x * 10)) {
        this->_PastPosition = this->_Position;
        while (round(this->_Position.x * 10) < round(this->_NextPosition.x * 10))
            this->_Position.x += 0.1f;
        this->_NextPosition = this->_Position;
    }
    if (round(this->_Position.z * 10) < round(this->_NextPosition.z * 10)) {
        this->_PastPosition = this->_Position;
        while (round(this->_Position.z * 10) < round(this->_NextPosition.z * 10))
            this->_Position.z += 0.1f;
        this->_NextPosition = this->_Position;
    }
    if (round(this->_Position.x * 10) > round(this->_NextPosition.x * 10)) {
        this->_PastPosition = this->_Position;
        while (round(this->_Position.x * 10) > round(this->_NextPosition.x * 10))
            this->_Position.x -= 0.1;
        this->_NextPosition = this->_Position;
    }
    if (round(this->_Position.z * 10) > round(this->_NextPosition.z * 10)) {
        this->_PastPosition = this->_Position;
        while (round(this->_Position.z * 10) > round(this->_NextPosition.z * 10))
            this->_Position.z -= 0.1;
        this->_NextPosition = this->_Position;
    }
    for (int i = 0; i < this->_Bombs.size(); i++) {
        this->_Bombs[i].update(bomberman);
        elapsed_time_ns = double(std::chrono::duration_cast <std::chrono::milliseconds> (end - this->_Bombs[i].getTimer()).count());
        if (this->_Bombs[i].getExploding() == true && elapsed_time_ns >= 60)
            this->_Bombs.erase(this->_Bombs.begin() + i);
    }
    this->_Update = 0;
}

void Player::draw(Game *bomberman)
{
    DrawCubeV(this->_Position, this->_Size, this->_Color);
}

void Player::drop_bomb(void)
{
    Bomb bomb(this->_Position);

    this->_Bombs.push_back(bomb);
}

int Player::can_I_plant(void) const
{
    for (int i = 0; i < this->_Bombs.size(); i++) {
        if (round(this->_Position.x) == round(this->_Bombs[i].getPosition().x)
        && round(this->_Position.z) == round(this->_Bombs[i].getPosition().z))
            return (0);
    }
    return (1);
}
