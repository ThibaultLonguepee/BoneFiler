/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** AnimatedSprite
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace bf {
    class AnimatedSprite {
        public:
            AnimatedSprite() = default;
            AnimatedSprite(const std::string& path, double = 0.2, int = 1, bool = true, bool = true);
            ~AnimatedSprite() = default;

            bool playing() const { return this->_playing; }
            void play() { this->_playing = true; }
            void pause() { this->_playing = false; }

            AnimatedSprite& operator=(const AnimatedSprite& source);
            sf::Sprite& render(double);
            void setPosition(float, float, bool = false);
            void setSize(float, float);
            void setAnimation(std::uint32_t);

        protected:
        private:
            bool _playing = false;
            bool _loop = false;

            double _frameTime = .0;
            std::uint32_t _frame = 0;
            std::uint32_t _frameCount = 0;
            std::uint32_t _frameSize = 0;

            std::uint32_t _animation = 0;
            std::uint32_t _animationCount = 0;

            sf::Sprite _sprite;
            sf::Texture _texture;
            double _timer = .0;
    };
}
