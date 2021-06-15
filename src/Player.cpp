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

Player::Player(char *name, int key_right, int key_up, int key_left, int key_down, int key_space)
{
    this->name = name;
    this->right = key_right;
    this->up = key_up;
    this->left = key_left;
    this->down = key_down;
    this->bomb = key_space;
}

Player::~Player()
{

}

Color Player::getColor(void) const
{
    if (bomberman->getStatus() == this->place)
        DrawCubeV(this->position, this->size, this->color);
    return (this->color);
}

void Player::setColor(const Color color)
{
    this->color = color;
}

Vector3 Player::getPosition(void) const
{
    return (this->position);
}

void Player::setPosition(const Vector3 position)
{
    this->position = position;
}

Vector3 Player::getPastPosition(void) const
{
    return (this->past_position);
}

void Player::setPastPosition(const Vector3 past_position)
{
    this->past_position = past_position;
}

Vector3 Player::getNextPosition(void) const
{
    return (this->next_position);
}

void Player::setNextPositionX(const float next_positionx)
{
    this->next_position.x = next_positionx;
}

void Player::setNextPositionZ(const float next_positionz)
{
    this->next_position.z = next_positionz;
}

Vector3 Player::getSize(void) const
{
    return (this->size);
}

void Player::setSize(const Vector3 size)
{
    this->size = size;
}

Vector2 Player::getHeader(void) const
{
    return (this->header);
}

void Player::setHeader(const Vector2 header)
{
    this->header = header;
}

int Player::getPlace(void) const
{
    return (this->place);
}

void Player::setPlace(const int place)
{
    this->place = place;
}

int Player::getRight(void) const
{
    return (this->right);
}

void Player::setRight(const int right)
{
    this->right = right;
}

int Player::getUp(void) const
{
    return (this->up);
}

void Player::setUp(const int up)
{
    this->up = up;
}

int Player::getLeft(void) const
{
    return (this->left);
}

void Player::setLeft(const int left)
{
    this->left = left;
}

int Player::getDown(void) const
{
    return (this->down);
}

void Player::setDown(const int down)
{
    this->down = down;
}

int Player::getBomb(void) const
{
    return (this->bomb);
}

void Player::setBomb(const int bomb)
{
    this->bomb = bomb;
}

int Player::getBombNB(void) const
{
    return (this->bomb_nb);
}

void Player::setBombNB(const int bomb_nb)
{
    this->bomb_nb = bomb_nb;
}

const char *Player::getName(void) const
{
    return (this->name);
}

void Player::setName(const char *name)
{
    this->name = name;
}

void Player::update(Game *bomberman)
{
    if (bomberman->getStatus() == this->place){
        this->header = GetWorldToScreen(Vector3{this->position.x, this->position.y + 1.5f, this->position.z}, bomberman->getCamera());


        for (int i = 0; i < bomberman->getMap()->blocks.size(); i++)
            if (CheckCollisionBoxes(
                BoundingBox{
                    Vector3{this->next_position.x - this->size.x / 2, this->next_position.y - this->size.y / 2, this->next_position.z - this->size.z / 2},
                    Vector3{this->next_position.x + this->size.x / 2, this->next_position.y + this->size.y / 2, this->next_position.z + this->size.z / 2}},
                BoundingBox{
                    Vector3{bomberman->getMap()->blocks[i].position.x - bomberman->getMap()->blocks[i].size.x / 2, bomberman->getMap()->blocks[i].position.y - bomberman->getMap()->blocks[i].size.y / 2, bomberman->getMap()->blocks[i].position.z - bomberman->getMap()->blocks[i].size.z / 2 },
                    Vector3{bomberman->getMap()->blocks[i].position.x + bomberman->getMap()->blocks[i].size.x / 2, bomberman->getMap()->blocks[i].position.y + bomberman->getMap()->blocks[i].size.y / 2, bomberman->getMap()->blocks[i].position.z + bomberman->getMap()->blocks[i].size.z / 2 }}
                )
            ){
                this->position = this->past_position;
                this->next_position = this->position;
            }

        if (round(this->position.x * 10) < round(this->next_position.x * 10)){
            while(round(this->position.x * 10) != round(this->next_position.x * 10)){
                this->past_position = this->position;
                this->position.x += 0.1f;
            }
        }
        if (round(this->position.z * 10) < round(this->next_position.z * 10)){
            while(round(this->position.z * 10) != round(this->next_position.z * 10)){
                this->past_position = this->position;
                this->position.z += 0.1f;
            }
        }
        if (round(this->position.x * 10) > round(this->next_position.x * 10)){
            while(round(this->position.x * 10) != round(this->next_position.x * 10)){
                this->past_position = this->position;
                this->position.x -= 0.1f;
            }
        }
        if (round(this->position.z * 10) > round(this->next_position.z * 10)){
            while(round(this->position.z * 10) != round(this->next_position.z * 10)){
                this->past_position = this->position;
                this->position.z -= 0.1f;
            }
        }
    }
}

void Player::draw(Game *bomberman)
{
    if (bomberman->status == this->place)
        DrawCubeV(this->position, this->size, this->color);
}