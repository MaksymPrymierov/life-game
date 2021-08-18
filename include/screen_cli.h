#pragma once

#include <screen.h>

#include <string_view>

namespace game_life
{

class screen_cli : public screen
{
public:
        screen_cli(int x, int y, int life_prob);
        ~screen_cli();

        void show() override;

private:
        static constexpr inline std::string_view m_life = "▣";
        static constexpr inline std::string_view m_dead = "░";
        static constexpr inline std::string_view m_vboard = "┃";
        static constexpr inline std::string_view m_hboard = "━";
        static constexpr inline std::string_view m_corner_top_left = "┏";
        static constexpr inline std::string_view m_corner_top_right = "┓";
        static constexpr inline std::string_view m_corner_bottom_left = "┗";
        static constexpr inline std::string_view m_corner_bottom_right = "┛";

        void clear();
        void print_vboards();
        void print_hboards();
        void print_corner_top_left();
        void print_corner_top_right();
        void print_corner_bottom_left();
        void print_corner_bottom_right();
};

} // game_life
