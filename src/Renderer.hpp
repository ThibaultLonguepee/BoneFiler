/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Renderer
*/

#pragma once

#include <cmath>
#include "File.hpp"
#include <SFML/Graphics.hpp>

namespace bf {
    class Renderer {
        public:
            Renderer(sf::RenderWindow& window);
            ~Renderer() = default;

            void draw(std::vector<File>& files) const;

        protected:
        private:
            sf::RenderWindow& _win;
            sf::Font _font;
            sf::Texture _fileTex;
            sf::Texture _folderTex;
    };
}
