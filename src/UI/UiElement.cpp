/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** UiElement
*/

#include "UiElement.hpp"

bf::UiElement::UiElement(Vector2d position, Vector2d size)
    : _position(position), _size(size)
{
}

bool bf::UiElement::clicked(sf::Vector2i pos) const
{
    if (pos.x < this->_position.x || pos.x > this->_position.x + this->_size.x)
        return false;
    if (pos.y < this->_position.y || pos.y > this->_position.y + this->_size.y)
        return false;
    return true;
}
