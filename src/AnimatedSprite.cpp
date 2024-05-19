/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** AnimatedSprite
*/

#include "AnimatedSprite.hpp"
    #include <iostream>

bf::AnimatedSprite::AnimatedSprite(const std::string& path, double frameTime, int count, bool autoPlay, bool looping)
    : _playing(autoPlay), _loop(looping), _frameTime(frameTime), _frame(0), _animationCount(count)
{
    this->_texture.loadFromFile(path);
    this->_frameSize = this->_texture.getSize().y / this->_animationCount;
    this->_frameCount = this->_texture.getSize().x / this->_frameSize;
    auto rect = sf::IntRect(0, 0, this->_frameSize, this->_frameSize);
    this->_sprite = sf::Sprite(this->_texture, rect);
}

sf::Sprite& bf::AnimatedSprite::render(double dt)
{
    if (!this->_playing)
        return this->_sprite;

    this->_timer += dt;
    while (this->_timer > this->_frameTime) {
        this->_timer -= this->_frameTime;
        if (!this->_loop && this->_frame + 1 >= this->_frameCount)
            this->_playing = false;
        this->_frame = (this->_frame + 1) % this->_frameCount;
    }
    auto rect = this->_sprite.getTextureRect();
    rect.left = this->_frame * this->_frameSize;
    this->_sprite.setTextureRect(rect);
    return this->_sprite;
}

void bf::AnimatedSprite::setPosition(float x, float y, bool centered)
{
    this->_sprite.setOrigin(
        centered ? this->_frameSize / 2.f : 0.f,
        centered ? this->_frameSize / 2.f : 0.f
    );
    this->_sprite.setPosition(x, y);
}

void bf::AnimatedSprite::setAnimation(std::uint32_t animation)
{
    if (this->_animation == animation)
        return;
    this->_animation = animation;
    this->_frame = 0;
    auto rect = this->_sprite.getTextureRect();
    rect.top = this->_animation * this->_frameSize;
    this->_sprite.setTextureRect(rect);
}

void bf::AnimatedSprite::setSize(float w, float h)
{
    this->_sprite.setScale(w / this->_frameSize, h / this->_frameSize);
}

bf::AnimatedSprite& bf::AnimatedSprite::operator=(const AnimatedSprite& source)
{
    this->_playing = source.playing();
    this->_loop = source._loop;
    this->_frameTime = source._frameTime;
    this->_frameCount = source._frameCount;
    this->_frameSize = source._frameSize;
    this->_frame = source._frame;
    this->_texture = sf::Texture(source._texture);
    this->_timer = source._timer;
    this->_animation = source._animation;
    this->_animationCount = source._animationCount;
    this->_sprite = sf::Sprite(this->_texture, source._sprite.getTextureRect());
    return *this;
}

