/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** FileLister
*/

#pragma once

#include <vector>
#include <filesystem>
#include "File.hpp"
#include "Fire.hpp"

namespace bf {
    class FileLister {
        public:
            FileLister() = default;
            ~FileLister() = default;

            std::vector<File>& run();

        protected:
        private:
            std::uint32_t entrySize(const std::filesystem::directory_entry& entry) const;
            std::vector<File> _files = {};
    };
}
