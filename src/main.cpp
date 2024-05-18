/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** main
*/

#include <iostream>
#include "Fire.hpp"

int main(void)
{
    bf::Fire fire;
    fire.feed(10 * 1000 * 1000); // 10 Mo
    std::cout << fire.lifespan() << std::endl;
    fire.run(1000.0); // 1000 sec
    std::cout << fire.lifespan() << std::endl;
    return 0;
}
