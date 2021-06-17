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
    static int tick = 0;
    
    if (elapsed_time_ns >= 77) {
        tick -= -1;
        this->_Timer = end;
    }
    std::cout << _Tick << std::endl;
    if (tick % 5 == 0 && tick != 0) {
        std::cout << "bomb is growing" << std::endl;
        this->_Size.x += 0.1;
        this->_Size.y += 0.1;
        this->_Size.z += 0.1;
    }
    std::cout << this->_Size.x << std::endl;
}

void Bomb::Draw(void) const
{
    DrawCubeV(this->_Position, this->_Size, this->_Color);
}