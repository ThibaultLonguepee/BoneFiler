/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** File
*/

#pragma once

#include <cstdint>
#include <string>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>

namespace bf {
    class File {
        public:
            File(const std::string& name, std::uint32_t size);
            File(const std::string& path);
            ~File() = default;

            std::string name() const { return this->_name; }
            std::uint32_t size() const { return this->_size; }
        protected:
        private:
            std::string _name = "";
            std::uint32_t _size = 0;
    };
}