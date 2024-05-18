/*
** EPITECH PROJECT, 2024
** BoneFiler
** File description:
** Vector2
*/

#pragma once

namespace bf {
    template<typename T>
    class Vector2 {
        public:
            Vector2();
            ~Vector2();

            T x = .0;
            T y = .0;
    };
}

#define Vector2d Vector2<double>
