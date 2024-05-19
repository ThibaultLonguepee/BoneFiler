/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "FileManager.hpp"
#include "Fire.hpp"
#include "Renderer.hpp"

int main(void)
{
    bf::Fire fire;
    bf::FileManager files;
    sf::RenderWindow win(sf::VideoMode(600, 600), "Hey");
    bf::Renderer renderer(win);
    auto clock = sf::Clock();

    fire.feed(3000);
    while (win.isOpen()) {

        double dt = clock.restart().asSeconds();
        sf::Event event;

        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close(); return 0; }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                files.burn(fire);
        }

        fire.run(dt);
        files.update(dt);
        win.clear();
        renderer.draw(fire, dt);
        renderer.draw(files, dt);
        win.display();

    }
    return 0;
}
