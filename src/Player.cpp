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

Player::Player(char *name, int key_right, int key_up, int key_left, int key_down)
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
    if (bomberman->status == this->place)
        DrawCubeV(this->position, this->size, this->color);
}

void Player::update(Game *bomberman)
{
    if (bomberman->status == this->place){
        this->header = GetWorldToScreen(Vector3{this->position.x, this->position.y + 1.5f, this->position.z}, bomberman->camera);


        for (int i = 0; i < bomberman->map->blocks.size(); i++)
            if (CheckCollisionBoxes(
                BoundingBox{
                    Vector3{this->next_position.x - this->size.x / 2, this->next_position.y - this->size.y / 2, this->next_position.z - this->size.z / 2},
                    Vector3{this->next_position.x + this->size.x / 2, this->next_position.y + this->size.y / 2, this->next_position.z + this->size.z / 2}},
                BoundingBox{
                    Vector3{bomberman->map->blocks[i].position.x - bomberman->map->blocks[i].size.x / 2, bomberman->map->blocks[i].position.y - bomberman->map->blocks[i].size.y / 2, bomberman->map->blocks[i].position.z - bomberman->map->   blocks[i].size.z / 2 },
                    Vector3{bomberman->map->blocks[i].position.x + bomberman->map->blocks[i].size.x / 2, bomberman->map->blocks[i].position.y + bomberman->map->blocks[i].size.y / 2, bomberman->map->blocks[i].position.z + bomberman->map->blocks[i].size.z / 2 }}
                )
            ){
                this->position = this->past_position;
                this->next_position = this->position;
            }
        /*
        for (int i = 0; i < bomberman->players.size(); i++)
            if (CheckCollisionBoxes(
                BoundingBox{
                    Vector3{this->next_position.x - this->size.x / 2, this->next_position.y - this->size.y / 2, this->next_position.z - this->size.z / 2},
                    Vector3{this->next_position.x + this->size.x / 2, this->next_position.y + this->size.y / 2, this->next_position.z + this->size.z / 2}},
                BoundingBox{
                    Vector3{bomberman->players[i].position.x - bomberman->players[i].size.x / 2, bomberman->players[i].position.y - bomberman->players[i].size.y / 2, bomberman->players[i].position.z - bomberman->players[i].size.z / 2 },
                    Vector3{bomberman->players[i].position.x + bomberman->players[i].size.x / 2, bomberman->players[i].position.y + bomberman->players[i].size.y / 2, bomberman->players[i].position.z + bomberman->players[i].size.z / 2 }}
                )
            ){
                this->position = this->past_position;
                this->next_position = this->position;
            }
        */


        if (round(this->position.x * 10) < round(this->next_position.x * 10)){
            while(round(this->position.x * 10) != round(this->next_position.x * 10)){
                this->past_position = this->position;
                this->position.x += 0.1f;
            }
            this->next_position = this->position;
        }
        if (round(this->position.z * 10) < round(this->next_position.z * 10)){
            while(round(this->position.z * 10) != round(this->next_position.z * 10)){
                this->past_position = this->position;
                this->position.z += 0.1f;
            }
            this->next_position = this->position;
        }
        if (round(this->position.x * 10) > round(this->next_position.x * 10)){
            while(round(this->position.x * 10) != round(this->next_position.x * 10)){
                this->past_position = this->position;
                this->position.x -= 0.1f;
            }
            this->next_position = this->position;
        }
        if (round(this->position.z * 10) > round(this->next_position.z * 10)){
            while(round(this->position.z * 10) != round(this->next_position.z * 10)){
                this->past_position = this->position;
                this->position.z -= 0.1f;
            }
            this->next_position = this->position;
        }
    }
}
