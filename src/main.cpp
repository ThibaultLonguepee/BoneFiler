/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "FileLister.hpp"

int main(void)
{
    bf::FileLister lister;
    sf::RenderWindow win(sf::VideoMode(600, 600), "Hey");
    sf::Font font; font.loadFromFile("assets/regular.ttf");

    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event))
            if (event.type == sf::Event::Closed) {
                win.close(); return 0; }
        auto files = lister.run(.1);
        win.clear();
        for (std::size_t i = 0; i < files.size(); i++)
            ;
        win.display();
    }
    return 0;
}
