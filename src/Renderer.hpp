/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Renderer
*/

#pragma once

#include <optional>
#include <cmath>
#include "Fire.hpp"
#include "File.hpp"
#include <SFML/Graphics.hpp>

namespace bf {
    class Renderer {
        public:
            Renderer(sf::RenderWindow& window);
            ~Renderer() = default;

            void draw(std::vector<File>& files);
            void draw(Fire& files) const;
            std::optional<std::uint32_t> hovered() const { return this->_hovered; };

        protected:
        private:
            const double _scale = 1.5625;
            std::optional<std::uint32_t> _hovered;

            sf::RenderWindow& _win;
            sf::Font _font;
            sf::Texture _fileTex;
            sf::Texture _folderTex;

            sf::Texture _fireMinTex;
            sf::Texture _fireMedTex;
            sf::Texture _fireMaxTex;
    };
}
