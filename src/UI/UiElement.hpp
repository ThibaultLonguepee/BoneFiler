/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** UiElement
*/

#include <functional>
#include <Vector2.hpp>
#include <SFML/Graphics.hpp>

namespace bf {
    class UiElement {
        public:
            UiElement(Vector2d position, Vector2d size);
            ~UiElement() = default;

            bool clicked(sf::Vector2i pos) const;

        protected:
        private:
            Vector2d _position;
            Vector2d _size;
    };
}
