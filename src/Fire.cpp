/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Fire
*/

#include "Fire.hpp"

void bf::Fire::feed(std::uint32_t size)
{
    this->_lifespan += std::cbrt(size);
}

void bf::Fire::run(double deltaTime)
{
    this->_lifespan -= deltaTime;
    if (this->_lifespan < 0)
        this->_lifespan = .0;
}

std::string bf::Fire::flifespan() const
{
    auto seconds = static_cast<int>(this->_lifespan) % 60;
    auto minutes = static_cast<int>(this->_lifespan / 60.0) % 60;
    auto hours = static_cast<int>(this->_lifespan / 3600.0);
    auto ss = std::stringstream();
    if (hours > 0)
        ss << hours << "h " << minutes << "m " << seconds << "s";
    else if (minutes > 0)
        ss << minutes << "m " << seconds << "s";
    else
        ss << seconds << "s";
    return ss.str();
}
