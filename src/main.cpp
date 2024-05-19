/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "FileLister.hpp"
#include "Fire.hpp"
#include "Renderer.hpp"

int main(void)
{
    bf::Fire fire;
    bf::FileLister lister;
    sf::RenderWindow win(sf::VideoMode(600, 600), "Hey");
    bf::Renderer renderer(win);

    auto clock = sf::Clock();
    std::optional<std::uint32_t> selected = std::nullopt;

    fire.feed(40000);
    while (win.isOpen()) {
        double dt = clock.restart().asSeconds();
        auto& files = lister.run(dt);
        sf::Event event;

        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close(); return 0; }
            if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left && selected.has_value())
                lister.burn(fire, selected.value());
        }

        fire.run(dt);
        win.clear();
        renderer.draw(fire);
        renderer.draw(files);
        selected = renderer.hovered();
        win.display();
    }
    return 0;
}
