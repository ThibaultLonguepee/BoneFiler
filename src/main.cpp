/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** main
*/

#include <iostream>
#include "FileLister.hpp"

int main(void)
{
    bf::FileLister lister;
    auto files = lister.run(.0);
    for (std::size_t i = 0; i < files.size(); i++)
        std::cout << files.at(i).name() << " -> " << files.at(i).size() << " B" << std::endl;
    return 0;
}
