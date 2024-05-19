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
    this->_bgTex.loadFromFile(path + "/assets/background.png");

    this->_fire = AnimatedSprite(path + "/assets/fire.png", 0.2, 3);
    this->_fire.setPosition(300, 300, true);
    this->_fire.setSize(100, 100);

    this->_light = AnimatedSprite(path + "/assets/light.png", 0.4, 3);
    this->_light.setSize(600, 600);

    this->_weight = AnimatedSprite(path + "/assets/weight.png", 1, 3, false, false);
    this->_weight.setSize(25, 25);
}

void bf::Renderer::draw(FileManager& manager, double dt)
{
    auto angle = .0;
    auto& files = manager.dump();

    this->_font.setSmooth(false);
    auto name = sf::Text("", this->_font, 14);
    name.setStyle(sf::Text::Bold);

    auto outline = sf::CircleShape(32.f);
    outline.setOrigin(32.f, 32.f);
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineThickness(5.f);
    outline.setOutlineColor(sf::Color(255, 0, 77));

    for (auto file = files.begin(); file != files.end(); file++) {

        // Compute file pos
        angle += M_PI * 2.0 / files.size();
        auto pos = sf::Vector2f(
            std::cos(angle - M_PI_2) * 200.f + 300.f,
            std::sin(angle - M_PI_2) * 200.f + 300.f);
        file->sprite().setPosition(pos.x, pos.y, true);
        outline.setPosition(pos);

        // Setup name tag
        name.setString(file->file().name());
        auto offset = (50.0 - name.getLocalBounds().width) / 2.0 - 25.0;
        name.setPosition(pos.x + offset, pos.y + 25.f);

        // Setup weight icon
        this->_weight.setPosition(pos.x, pos.y - 35.f, true);
        if (file->file().heavy()) this->_weight.setAnimation(2);
        else if (file->file().light()) this->_weight.setAnimation(1);
        else this->_weight.setAnimation(0);

        // Draw stuff & check hover
        bool h = file->sprite().hovered(sf::Mouse::getPosition(this->_win));
        file->setHovered(h);
        if (h) this->_win.draw(outline);
        this->_win.draw(file->sprite().render(dt));
        this->_win.draw(this->_weight.render(.0));
        this->_win.draw(name);
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
