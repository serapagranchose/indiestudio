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

void Block::load_mouse()
{
    Texture2D texture = LoadTexture("../graphic/texture/Brick_Block.png");
    Mesh mesh = GenMeshCube(1.0, 1.0, 1.0);
    this->one_model = LoadModelFromMesh(mesh);
    this->one_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void Block::load_holy_block()
{
    Texture2D texture = LoadTexture("../graphic/texture/Bloc_vide.png");
    Mesh mesh = GenMeshCube(1.0, 1.0, 1.0);
    this->one_model = LoadModelFromMesh(mesh);
    this->one_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void Block::draw_mousse()
{

    DrawModel(this->one_model, position, 1.0f, WHITE);
}

void Block::draw_holy_block()
{

    DrawModel(this->one_model, position, 1.0f, WHITE);
}

void Block::draw()
{
    DrawCubeV(this->position, this->size, this->color);
}
