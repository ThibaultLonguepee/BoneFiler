/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Renderer
*/

#pragma once

#include <cmath>
#include <optional>
#include <SFML/Graphics.hpp>

#include "Fire.hpp"
#include "FileManager.hpp"
#include "AnimatedSprite.hpp"

namespace bf {
    class Renderer {
        public:
            Renderer(sf::RenderWindow& window);
            ~Renderer() = default;

            void draw(FileManager&, double);
            void draw(Fire&, double);
            std::optional<std::uint32_t> hovered() const { return this->_hovered; };

        protected:
        private:
            const double _scale = 1.5625;
            double _timer = .0;
            std::optional<std::uint32_t> _hovered;

            sf::RenderWindow& _win;
            sf::Font _font;
            sf::Texture _bgTex;

            AnimatedSprite _fire;
            AnimatedSprite _light;
            AnimatedSprite _weight;
    };
}
