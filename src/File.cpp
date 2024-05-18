/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** File
*/

#include "File.hpp"

bf::File::File(const std::string& path)
{
    struct stat info = {};
    if (stat(path.c_str(), &info) < 0)
        return;
    this->_name = path;
    this->_size = info.st_size;
}

bf::File::File(const std::string& name, std::uint32_t size, bool folder)
    : _name(name), _size(size), _folder(folder)
{
}
