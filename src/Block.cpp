/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "Block.hpp"

Block::Block()
{
}

Block::Block(Vector3 position, bool destructible, Color color)
{
    this->_Color = color;
    this->_Position = position;
    this->_Destructible = destructible;
}

Block::~Block()
{

}

void Block::loadMousse()
{
    Texture2D texture = LoadTexture("assets/graphic/texture/brick_block.png");
    Mesh mesh = GenMeshCube(1.0, 1.0, 1.0);
    this->_Model = LoadModelFromMesh(mesh);
    this->_Model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    printf("SUCE\n");
}

void Block::loadHolyBlock()
{
    Texture2D texture = LoadTexture("assets/graphic/texture/empty_block.png");
    Mesh mesh = GenMeshCube(1.0, 1.0, 1.0);
    this->_Model = LoadModelFromMesh(mesh);
    this->_Model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    printf("SUCE\n");
}

void Block::loadGround()
{
    Texture2D texture = LoadTexture("assets/graphic/texture/grass.png");
    Mesh mesh = GenMeshCube(1.0, 1.0, 1.0);
    this->_Model = LoadModelFromMesh(mesh);
    this->_Model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    printf("SUCE\n");
}

void Block::drawBlockTexture()
{
    DrawModel(this->_Model, this->_Position, 1.0f, WHITE);
}

void Block::draw()
{
    DrawCubeV(this->_Position, this->_Size, this->_Color);
}

Vector3 Block::getPosition(void) const
{
    return (this->position);
}

bool Block::getDestructible(void) const
{
    return (this->destructible);
}

Vector3 Block::getSize(void) const
{
    return (this->size);
}