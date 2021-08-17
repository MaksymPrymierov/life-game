#include <screen_ncurses.h>

namespace game_life
{

screen_ncurses::screen_ncurses(int w, int h, int life_prob) :
        screen(w, h, life_prob)
{
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();

        create_window();
}

screen_ncurses::~screen_ncurses()
{
        delwin(m_game_win);
        endwin();
}

void screen_ncurses::show()
{
        for (int i = 1; i < m_height + 1; ++i)
        {
                for (int j = 1; j < m_width + 1; ++j)
                {
                        if (m_screen_map.at(i - 1).at(j - 1)) {
                                mvwaddch(m_game_win, i, j, m_life);
                        } else {
                                mvwaddch(m_game_win, i, j, m_dead);
                        }
                }
        }

        wrefresh(m_game_win);
}

void screen_ncurses::create_window()
{
        m_game_win = newwin(
                        m_height + 2,
                        m_width + 2,
                        (LINES - m_height + 2) / 2,
                        (COLS - m_width + 2) / 2
                );

        box(m_game_win, 0, 0);
        wrefresh(m_game_win);
        wborder(m_game_win, m_vboard, m_vboard, m_hboard, m_hboard, m_corner, m_corner, m_corner, m_corner);
}

};
