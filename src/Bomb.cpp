/*
** EPITECH PROJECT, 2021
** Bomb.cpp
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"

Bomb::Bomb(Vector3 position)
{
    this->_Position = position;
    this->_Position.x = round(this->_Position.x);
    this->_Position.z = round(this->_Position.z);
    this->_Timer = std::chrono::steady_clock::now();
    std::cout <<  "Just created" << std::endl;
}

Bomb::~Bomb()
{
}

Vector3 Bomb::getPosition(void) const
{
    return (this->_Position);
}

void Bomb::update(void)
{
    std::chrono::_V2::steady_clock::time_point end = std::chrono::steady_clock::now();
    double elapsed_time_ns = double(std::chrono::duration_cast <std::chrono::milliseconds> (end - this->_Timer).count());
    printf("update at %f\n", elapsed_time_ns);

    if (elapsed_time_ns >= 77) {
        std::cout << "Tick tack" << std::endl;
        _Tick -= -1;
        this->_Timer = end;
    }
    std::cout << _Tick << std::endl;
    if (_Tick % 5 == 0 && _Tick != 0) {
        std::cout << "bomb is growing" << std::endl;
        this->_Size.x += 0.1;
        this->_Size.y += 0.1;
        this->_Size.z += 0.1;
    }
    std::cout << "this is the size " << this->_Size.x << std::endl;
}

void Bomb::Draw(void) const
{
    DrawCubeV(this->_Position, this->_Size, this->_Color);
    for (int i = 0; i < this->_Explosions_Positions.size(); i++)
        DrawCubeV(this->_Explosions_Positions[i], this->_Size, RED);
}

int is_there_a_wall(Game *bomberman, Vector3 position)
{
    for (int i = 0; bomberman->getMap()->getBlock().size() > i; i++) {
        if (round(bomberman->getMap()->getBlock()[i].getPosition().x) == round(position.x)
        && round(bomberman->getMap()->getBlock()[i].getPosition().z) == round(position.z)) {
            if (bomberman->getMap()->getBlock()[i].getDestructible() == false)
                return (1);
        }
    }
    return (0);
}

int is_there_a_player(Game *bomberman, Vector3 position)
{
    for (int i = 0; bomberman->getPlayers().size() > i; i++) {
        if (round(bomberman->getPlayers()[i].getPosition().z) == round(position.z)
        && round(bomberman->getPlayers()[i].getPosition().x) == round(position.x)) {
            bomberman->getPlayers()[i].setStatus(0);
            return (1);
        }
    }
    return (0);
}

void Bomb::explode(Game *bomberman)
{
    Vector3 position = this->_Position;

    this->_Color = RED;
    position.z++;
    for (int i = 0; is_there_a_wall(bomberman, position) == 0 && i < 3; position.z++) {
        this->_Explosions_Positions.push_back(position);
        if (is_there_a_player(bomberman, position) == 1)
            break;
        i++;
    }
    position = this->_Position;
    position.z--;
    for (int i = 0; is_there_a_wall(bomberman, position) == 0 && i < 3; position.z--) {
        this->_Explosions_Positions.push_back(position);
        if (is_there_a_player(bomberman, position) == 1)
            break;
        i++;
    }
    position = this->_Position;
    position.x++;
    for (int i = 0; is_there_a_wall(bomberman, position) == 0 && i < 3; position.x++) {
        this->_Explosions_Positions.push_back(position);
        if (is_there_a_player(bomberman, position) == 1)
            break;
        i++;
    }
    position = this->_Position;
    position.x--;
    for (int i = 0; is_there_a_wall(bomberman, position) == 0 && i < 3; position.x--) {
        this->_Explosions_Positions.push_back(position);
        if (is_there_a_player(bomberman, position) == 1)
            break;
        i++;
    }
    this->_Timer = std::chrono::steady_clock::now();
}
