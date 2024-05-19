/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Renderer
*/

#include "Renderer.hpp"

bf::Renderer::Renderer(sf::RenderWindow& window) : _win(window)
{
    auto path = std::filesystem::canonical("/proc/self/exe").parent_path().string();
    this->_font.loadFromFile(path + "/assets/regular.ttf");
    this->_fileTex.loadFromFile(path + "/assets/file.png");
    this->_folderTex.loadFromFile(path + "/assets/folder.png");
    this->_bgTex.loadFromFile(path + "/assets/background.png");

    this->_fire = AnimatedSprite(path + "/assets/fire.png", 0.2, 3);
    this->_fire.setPosition(300, 300, true);
    this->_fire.setSize(100, 100);

    this->_light = AnimatedSprite(path + "/assets/light.png", 0.4, 3);
    this->_light.setSize(600, 600);
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

void bf::Renderer::draw(Fire& fire, double dt)
{
    if (fire.state() == FireSize::Extinguished) return;
    if (fire.state() == FireSize::Big) {
        this->_fire.setAnimation(0); this->_light.setAnimation(0); }
    if (fire.state() == FireSize::Medium) {
        this->_fire.setAnimation(1); this->_light.setAnimation(1); }
    if (fire.state() == FireSize::Small) {
        this->_fire.setAnimation(2); this->_light.setAnimation(2); }

    auto life = sf::Text(fire.flifespan(), this->_font, 24);
    auto offset = (100.0 - life.getLocalBounds().width) / 2.0 - 50.0;
    life.setPosition(300.f + offset, 350.f);

    sf::Sprite tile(this->_bgTex);
    tile.setScale(this->_scale, this->_scale);
    for (std::uint32_t x = 0; x < this->_win.getSize().x; x += 50) {
        for (std::uint32_t y = 0; y < this->_win.getSize().y; y += 50) {
            tile.setPosition(x, y);
            this->_win.draw(tile);
        }
    }

    this->_win.draw(life);
    this->_win.draw(this->_fire.render(dt));
    this->_win.draw(this->_light.render(dt));
}
