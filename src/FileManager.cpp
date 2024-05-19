/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** FileManager
*/

#include "FileManager.hpp"


void bf::FileManager::update(double dt)
{
    bool flag = false;

    // Erase burnt files
    for (auto file = this->_files.begin(); file != this->_files.end();) {
        if (file->burning()) flag = true;

        if (file->burnt()) file = this->_files.erase(file);
        else file++;
    }

    // Update list
    this->_timeout -= dt;
    if (this->_timeout > 0 || flag)
        return;
    this->_timeout = 2.f;
    this->_files.clear();
    auto files = this->_lister.run();
    for (const auto& file : files)
        this->_files.push_back(FileHandler(file, this->_path));
}

std::vector<bf::FileHandler>& bf::FileManager::dump()
{
    return this->_files;
}

void bf::FileManager::burn(Fire& fire)
{
    for (auto& file : this->_files)
        file.burn(fire);
}
