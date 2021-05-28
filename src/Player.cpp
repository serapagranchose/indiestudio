/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "indiestudio.hpp"

Player::Player()
{

}

Player::Player(std::string name, int key_right, int key_up, int key_left, int key_down)
{
    this->name = name;
    this->right = key_right;
    this->up = key_up;
    this->left = key_left;
    this->down = key_down;
}

Player::~Player()
{

}

void Player::draw(Game *bomberman)
{
    if (bomberman->status == this->place){
        DrawCubeV(this->position, this->size, this->color);
        DrawText(TextFormat("%s", this->name), (int)this->header.x - MeasureText("adrien karpapov", 20)/2, (int)this->header.y, 20, BLACK);
    }
}

void Player::update(Game *bomberman)
{
    if (bomberman->status == this->place){
        this->header = GetWorldToScreen((Vector3){this->position.x, this->position.y + 2.5f, this->position.z}, bomberman->camera);


        for (int i = 0; i < bomberman->map.blocks.size(); i++)
            if (CheckCollisionBoxes(
                (BoundingBox){
                    (Vector3){this->position.x - this->size.x / 2, this->position.y - this->size.y / 2, this->position.z - this->size.z / 2},
                    (Vector3){this->position.x + this->size.x / 2, this->position.y + this->size.y / 2, this->position.z + this->size.z / 2}},
                (BoundingBox){
                    (Vector3){bomberman->map.blocks[i].position.x - bomberman->map.blocks[i].size.x / 2, bomberman->map.blocks[i].position.y - bomberman->map.blocks[i].size.y / 2, bomberman->map.blocks[i].position.z - bomberman->map.blocks[i].size.z / 2 },
                    (Vector3){bomberman->map.blocks[i].position.x + bomberman->map.blocks[i].size.x / 2, bomberman->map.blocks[i].position.y + bomberman->map.blocks[i].size.y / 2, bomberman->map.blocks[i].position.z + bomberman->map.blocks[i].size.z / 2 }}
                )
            )
                this->collision = true;
    }
}
