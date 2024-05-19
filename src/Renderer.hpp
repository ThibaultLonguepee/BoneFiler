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
#include <filesystem>

namespace bf {
    class Renderer {
        public:
            Renderer(sf::RenderWindow& window);
            ~Renderer() = default;

            void draw(std::vector<File>&);
            void draw(Fire&) const;
            std::optional<std::uint32_t> hovered() const { return this->_hovered; };

        protected:
        private:
            std::string _path = "";
            const double _scale = 1.5625;
            double _timer = .0;
            std::optional<std::uint32_t> _hovered;

            sf::RenderWindow& _win;
            sf::Font _font;
            sf::Texture _bgTex;
            sf::Texture _fileTex;
            sf::Texture _folderTex;
            sf::Texture _fireMinTex;
            sf::Texture _fireMedTex;
            sf::Texture _fireMaxTex;
            sf::Texture _lightTex;
    };
}
