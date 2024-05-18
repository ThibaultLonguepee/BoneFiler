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

    fire.feed(1000000);
    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event))
            if (event.type == sf::Event::Closed) {
                win.close(); return 0; }
        win.clear();
        renderer.draw(fire);
        renderer.draw(lister.run(.1));
        win.display();
    }
    return 0;
}
