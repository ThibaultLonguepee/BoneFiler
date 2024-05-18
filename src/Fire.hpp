/*
** EPITECH PROJECT, 2024
** Fire
** File description:
** Fire
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <cmath>
#include <sstream>

namespace bf {

    enum FireSize : int {
        Extinguished,
        Small,
        Medium,
        Big
    };

    class Fire {
        public:
            Fire() = default;
            ~Fire() = default;

            void feed(std::uint32_t);
            void run(double);
            double lifespan() const { return this->_lifespan; }
            FireSize state() const;
            std::string flifespan() const;
            sf::Sprite render() const = delete;

        protected:
        private:
            double _lifespan = .0;
    };
}
