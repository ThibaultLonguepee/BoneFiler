/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Renderer
*/

#include "Renderer.hpp"

bf::Renderer::Renderer(sf::RenderWindow& window)
    : _win(window)
{
    this->_font.loadFromFile("assets/regular.ttf");
    this->_fileTex.loadFromFile("assets/file.png");
    this->_folderTex.loadFromFile("assets/folder.png");
    this->_fireMinTex.loadFromFile("assets/fire_min.png");
    this->_fireMaxTex.loadFromFile("assets/fire_max.png");
}

void bf::Renderer::draw(std::vector<File>& files) const
{
    auto angle = M_PI * 2.0 / files.size();
    auto sprite = sf::Sprite();
    auto name = sf::Text("", this->_font, 14);
    auto size = sf::Text("", this->_font, 11);

    for (std::size_t i = 0; i < files.size(); i++) {
        auto pos = sf::Vector2f(
            std::cos(angle * i - M_PI_2) * 200.f + 300.f,
            std::sin(angle * i - M_PI_2) * 200.f + 300.f);

        sprite.setTexture(files.at(i).folder() ? this->_folderTex : this->_fileTex);
        sprite.setPosition(pos);
        sprite.setScale(this->_scale, this->_scale);
        sprite.setOrigin(sf::Vector2f(16.f, 16.f));

        name.setString(files.at(i).name());
        auto offset = (50.0 - name.getLocalBounds().width) / 2.0 - 25.0;
        name.setPosition(pos.x + offset, pos.y + 20.f);

        size.setString(std::to_string(files.at(i).size()));
        offset = (50.0 - size.getLocalBounds().width) / 2.0 - 25.0;
        size.setPosition(pos.x + offset, pos.y + 36.f);

        this->_win.draw(sprite);
        this->_win.draw(name);
        this->_win.draw(size);
    }
}

void bf::Renderer::draw(Fire& fire) const
{
    auto tex = fire.lifespan() > 60 ? this->_fireMaxTex : this->_fireMinTex;
    auto sprite = sf::Sprite(tex);
    sprite.setOrigin(32.f, 32.f);
    sprite.setPosition(300.f, 300.f);
    sprite.setScale(this->_scale, this->_scale);
    this->_win.draw(sprite);
}