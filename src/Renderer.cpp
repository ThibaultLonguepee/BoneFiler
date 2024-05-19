/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Renderer
*/

#include "Renderer.hpp"

bf::Renderer::Renderer(sf::RenderWindow& window) : _win(window)
{
    this->_path = std::filesystem::canonical("/proc/self/exe").parent_path();
    this->_font.loadFromFile(this->_path + "/assets/regular.ttf");
    this->_fileTex.loadFromFile(this->_path + "/assets/file.png");
    this->_folderTex.loadFromFile(this->_path + "/assets/folder.png");
    this->_fireMinTex.loadFromFile(this->_path + "/assets/fire_min.png");
    this->_fireMedTex.loadFromFile(this->_path + "/assets/fire_med.png");
    this->_fireMaxTex.loadFromFile(this->_path + "/assets/fire_max.png");
    this->_bgTex.loadFromFile(this->_path + "/assets/background.png");
    this->_lightTex.loadFromFile(this->_path + "/assets/light.png");
}

void bf::Renderer::draw(std::vector<File>& files)
{
    this->_hovered = std::nullopt;

    auto angle = M_PI * 2.0 / files.size();
    auto sprite = sf::Sprite();
    this->_font.setSmooth(false);
    auto name = sf::Text("", this->_font, 18);
    name.setStyle(sf::Text::Bold);
    auto size = sf::Text("", this->_font, 11);
    size.setStyle(sf::Text::Bold);

    auto mouse = sf::Mouse::getPosition(this->_win);
    auto outline = sf::CircleShape(32.f);
    outline.setOrigin(32.f, 32.f);
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineThickness(5.f);
    outline.setOutlineColor(sf::Color(255, 0, 77));

    for (std::size_t i = 0; i < files.size(); i++) {
        auto pos = sf::Vector2f(
            std::cos(angle * i - M_PI_2) * 200.f + 300.f,
            std::sin(angle * i - M_PI_2) * 200.f + 300.f);

        sprite.setTexture(files.at(i).folder() ? this->_folderTex : this->_fileTex);
        sprite.setPosition(pos);
        outline.setPosition(pos);
        sprite.setScale(this->_scale, this->_scale);
        sprite.setOrigin(sf::Vector2f(16.f, 16.f));

        name.setString(files.at(i).name());
        auto offset = (50.0 - name.getLocalBounds().width) / 2.0 - 25.0;
        name.setPosition(pos.x + offset, pos.y + 25.f);

        size.setString(std::to_string(files.at(i).size()));
        offset = (50.0 - size.getLocalBounds().width) / 2.0 - 25.0;
        size.setPosition(pos.x + offset, pos.y + 36.f);

        this->_win.draw(sprite);
        this->_win.draw(name);
        //this->_win.draw(size);
        if (sprite.getGlobalBounds().contains(mouse.x, mouse.y)) {
            this->_win.draw(outline);
            this->_hovered = i;
        }
    }
}

#include <iostream>
void bf::Renderer::draw(Fire& fire) const
{
    sf::Texture tex;
    if (fire.state() == FireSize::Extinguished) return;
    if (fire.state() == FireSize::Big) tex = this->_fireMaxTex;
    if (fire.state() == FireSize::Medium) tex = this->_fireMedTex;
    if (fire.state() == FireSize::Small) tex = this->_fireMinTex;

    auto time = 1.0 - (static_cast<int>(fire.lifespan() * 100) % 100) / 100.0;
    auto rect = sf::IntRect(sf::Vector2i(static_cast<int>(time * 7) * 64, 0), sf::Vector2i(64, 64));
    auto sprite = sf::Sprite(tex, rect);
    sprite.setOrigin(32.f, 32.f);
    sprite.setPosition(300.f, 300.f);
    sprite.setScale(this->_scale, this->_scale);

    auto life = sf::Text(fire.flifespan(), this->_font, 24);
    auto offset = (100.0 - life.getLocalBounds().width) / 2.0 - 50.0;
    life.setPosition(300.f + offset, 350.f);

    sf::Sprite light(this->_lightTex);
    light.setOrigin(64.f, 64.f);
    light.setPosition(300.f, 300.f);
    light.setScale(4.6875f, 4.6875f);

    sf::Sprite tile(this->_bgTex);
    tile.setScale(this->_scale, this->_scale);
    for (std::uint32_t x = 0; x < this->_win.getSize().x; x += 50) {
        for (std::uint32_t y = 0; y < this->_win.getSize().y; y += 50) {
            tile.setPosition(x, y);
            this->_win.draw(tile);
        }
    }

    this->_win.draw(sprite);
    this->_win.draw(life);
    this->_win.draw(light);
}
