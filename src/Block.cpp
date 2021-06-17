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

Block::Block(Vector3 position, bool destructible, Color couleur)
{
    this->color = couleur;
    this->position = position;
    this->destructible = destructible;
}

Block::~Block()
{

}

void Block::loadMousse()
{
    Texture2D texture = LoadTexture("graphic/texture/Brick_Block.png");
    Mesh mesh = GenMeshCube(1.0, 1.0, 1.0);
    this->one_model = LoadModelFromMesh(mesh);
    this->one_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void Block::loadHolyBlock()
{
    Texture2D texture = LoadTexture("graphic/texture/Bloc_vide.png");
    Mesh mesh = GenMeshCube(1.0, 1.0, 1.0);
    this->one_model = LoadModelFromMesh(mesh);
    this->one_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void Block::loadGround()
{
    Texture2D texture = LoadTexture("graphic/texture/grass.png");
    Mesh mesh = GenMeshCube(1.0, 1.0, 1.0);
    this->one_model = LoadModelFromMesh(mesh);
    this->one_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void Block::drawBlockTexture()
{
    DrawModel(this->one_model, position, 1.0f, WHITE);
}

void Block::draw()
{
    DrawCubeV(this->position, this->size, this->color);
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