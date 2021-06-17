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

Player::Player(const char * _name, int key_right, int key_up, int key_left, int key_down, int key_space, Vector3 _position)
{
    this->name = _name;
    this->right = key_right;
    this->up = key_up;
    this->left = key_left;
    this->down = key_down;
    this->bomb = key_space;
    this->position = _position;
    this->next_position = _position;
}

Player::~Player()
{
}

Vector3 Player::getPosition(void) const
{
    return (this->position);
}

void Player::setPosition(const Vector3 _position)
{
    this->position = _position;
}

Vector3 Player::getPastPosition(void) const
{
    return (this->past_position);
}

void Player::setPastPosition(const Vector3 _past_position)
{
    this->past_position = _past_position;
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

Vector2 Player::getHeader(void) const
{
    return (this->header);
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

int Player::getUp(void) const
{
    return (this->up);
}

int Player::getLeft(void) const
{
    return (this->left);
}

int Player::getDown(void) const
{
    return (this->down);
}

int Player::getBomb(void) const
{
    return (this->bomb);
}

int Player::getBombNB(void) const
{
    return (this->bomb_nb);
}

void Player::setBombNB(const int bomb_nb)
{
    this->bomb_nb = bomb_nb;
}

const char * Player::getName(void) const
{
    return (this->name);
}

int Player::getUpdate(void) const
{
    return (this->_update);
}

void Player::setUpdate(const int update)
{
    this->_update = update;
}

std::vector<Bomb> Player::getBomb_List(void) const
{
    return (this->_Bomb_list);
}

int Player::getStatus(void) const
{
    return (this->_Status);
}

void Player::setStatus(const int status)
{
    this->_Status = status;
}

void Player::update(Game *bomberman)
{
    this->header = GetWorldToScreen(Vector3{this->position.x, this->position.y + 1.5f, this->position.z}, bomberman->getCamera());
    this->past_position = this->position;
    for (int i = 0; i < bomberman->getMap()->blocks.size(); i++) {
        if (CheckCollisionBoxes(
                BoundingBox{
                    Vector3{this->next_position.x - this->size.x / 2, this->next_position.y - this->size.y / 2, this->next_position.z - this->size.z / 2},
                    Vector3{this->next_position.x + this->size.x / 2, this->next_position.y + this->size.y / 2, this->next_position.z + this->size.z / 2}},
                BoundingBox{
                    Vector3{bomberman->getMap()->blocks[i].getPosition().x - bomberman->getMap()->blocks[i].getSize().x / 2, bomberman->getMap()->blocks[i].getPosition().y - bomberman->getMap()->blocks[i].getSize().y / 2, bomberman->getMap()->blocks[i].getPosition().z - bomberman->getMap()->blocks[i].getSize().z / 2},
                    Vector3{bomberman->getMap()->blocks[i].getPosition().x + bomberman->getMap()->blocks[i].getSize().x / 2, bomberman->getMap()->blocks[i].getPosition().y + bomberman->getMap()->blocks[i].getSize().y / 2, bomberman->getMap()->blocks[i].getPosition().z + bomberman->getMap()->blocks[i].getSize().z / 2}}))
        {
            this->position = this->past_position;
            this->next_position = this->position;
        }
    }
    if (round(this->position.x * 10) < round(this->next_position.x * 10)) {
        this->past_position = this->position;
        while (round(this->position.x * 10) < round(this->next_position.x * 10))
            this->position.x += 0.1f;
        this->next_position = this->position;
    }
    if (round(this->position.z * 10) < round(this->next_position.z * 10)) {
        this->past_position = this->position;
        while (round(this->position.z * 10) < round(this->next_position.z * 10))
            this->position.z += 0.1f;
        this->next_position = this->position;
    }
    if (round(this->position.x * 10) > round(this->next_position.x * 10)) {
        this->past_position = this->position;
        while (round(this->position.x * 10) > round(this->next_position.x * 10))
            this->position.x -= 0.1;
        this->next_position = this->position;
    }
    if (round(this->position.z * 10) > round(this->next_position.z * 10)) {
        this->past_position = this->position;
        while (round(this->position.z * 10) > round(this->next_position.z * 10))
            this->position.z -= 0.1;
        this->next_position = this->position;
    }
    this->_update = 0;
}

void Player::draw(Game *bomberman)
{
    DrawCubeV(this->position, this->size, this->color);
}

void Player::drop_bomb(void)
{
    Bomb bomb(this->position);

    this->_Bomb_list.push_back(bomb);
}

int Player::can_I_plant(void) const
{
    for (int i = 0; i < this->_Bomb_list.size(); i++) {
        if (round(this->position.x) == round(this->_Bomb_list[i].getPosition().x)
        && round(this->position.z) == round(this->_Bomb_list[i].getPosition().z))
            return (0);
    }
    return (1);
}