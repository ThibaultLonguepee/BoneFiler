/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Renderer
*/

#pragma once

#include <cmath>
#include "Fire.hpp"
#include "File.hpp"
#include <SFML/Graphics.hpp>

namespace bf {
    class Renderer {
        public:
            Renderer(sf::RenderWindow& window);
            ~Renderer() = default;

            void draw(std::vector<File>& files) const;
            void draw(Fire& files) const;

        protected:
        private:
            const double _scale = 1.5625;

            sf::RenderWindow& _win;
            sf::Font _font;
            sf::Texture _fileTex;
            sf::Texture _folderTex;

            sf::Texture _fireMinTex;
            sf::Texture _fireMedTex;
            sf::Texture _fireMaxTex;
    };
}
