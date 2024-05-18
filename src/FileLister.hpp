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

            std::vector<File>& run(double);
            void burn(Fire& fire, std::uint32_t index);

        protected:
        private:
            std::uint32_t entrySize(const std::filesystem::directory_entry& entry) const;
            double _timeout = .0;
            std::vector<File> _files = {};
    };
}
