/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** FileLister
*/

#include "FileLister.hpp"

std::vector<bf::File>& bf::FileLister::run(double deltaTime)
{
    this->_timeout -= deltaTime;
    if (this->_timeout > .0)
        return this->_files;
    this->_files.clear();
    for (const auto & entry : std::filesystem::directory_iterator(".")) {
        auto name = entry.path().filename();
        auto size = this->entrySize(entry);
        this->_files.push_back(File(name, size, entry.is_directory()));
    }
    this->_timeout = 1.0;
    return this->_files;
}

std::uint32_t bf::FileLister::entrySize(const std::filesystem::directory_entry& entry) const
{
    std::uint32_t size = 0;

    if (entry.is_directory()) {
        for (const auto & e : std::filesystem::directory_iterator(entry.path()))
            size += this->entrySize(e);
        return size;
    }
    return entry.file_size();
}
