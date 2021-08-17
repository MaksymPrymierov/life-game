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
        delwin(game_win);
        endwin();
}

void screen_ncurses::show()
{
        for (int i = 1; i < this->height + 1; ++i)
        {
                for (int j = 1; j < this->width + 1; ++j)
                {
                        if (this->screen_map.at(i - 1).at(j - 1)) {
                                mvwaddch(game_win, i, j, life);
                        } else {
                                mvwaddch(game_win, i, j, dead);
                        }
                }
        }

        wrefresh(game_win);
}

void screen_ncurses::create_window()
{
        game_win = newwin(
                        this->height + 2,
                        this->width + 2,
                        (LINES - this->height + 2) / 2,
                        (COLS - this->width + 2) / 2
                );

        box(game_win, 0, 0);
        wrefresh(game_win);
        wborder(game_win, vboard, vboard, hboard, hboard, corner, corner, corner, corner);
}

};
