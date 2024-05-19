/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** FileManager
*/

#pragma once

#include "FileLister.hpp"
#include "AnimatedSprite.hpp"

namespace bf {

    class FileHandler {
        public:

            FileHandler(const File& file, const std::string& path) : _file(file) {
                this->_sprite = AnimatedSprite(path + "/assets/files.png", 0.1, 2, false, false);
                this->_sprite.setSize(50, 50);
                if (this->_file.folder()) this->_sprite.setAnimation(1);
            }
            FileHandler(const FileHandler& source) : _file(source.file()) {
                this->_sprite = source._sprite;
                this->_burning = source._burning;
                this->_hovered = source._hovered;
            }
            ~FileHandler() = default;

            void burn(Fire& fire) {
                if (!this->_hovered || this->_burning) return;
                std::system(("rm -rf " + this->_file.name()).c_str()); // !
                this->_burning = true;
                this->_sprite.play();
                fire.feed(this->_file.size());
            }

            void setHovered(bool hovered) { this->_hovered = hovered; }
            AnimatedSprite& sprite() { return this->_sprite; }
            const File& file() const { return this->_file; }
            bool burnt() const { return this->_burning && !this->_sprite.playing(); }
            bool burning() const { return this->_burning; }

        protected:
        private:
            bool _burning = false;
            bool _hovered = false;
            File _file;
            AnimatedSprite _sprite;
    };

    class FileManager {
        public:
            FileManager()
                : _path(std::filesystem::canonical("/proc/self/exe").parent_path()) {}
            ~FileManager() = default;

            void update(double dt);
            std::vector<FileHandler>& dump();
            void burn(Fire& fire);

        protected:
        private:
            double _timeout = .0f;
            std::vector<FileHandler> _files = {};
            FileLister _lister;
            std::string _path = "";
    };
}
