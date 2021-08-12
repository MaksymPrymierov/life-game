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
        for (int i = 1; i < this->height; ++i)
        {
                for (int j = 1; j < this->width; ++j)
                {
                        if (this->screen_map.at(i - 1).at(j - 1)) {
                                mvwaddch(game_win, j, i, life);
                        } else {
                                mvwaddch(game_win, j, i, dead);
                        }
                }
        }

        wrefresh(game_win);
}

void screen_ncurses::create_window()
{
        game_win = newwin(
                        this->height + 1,
                        this->width + 1,
                        (LINES - this->height + 1) / 2,
                        (COLS - this->width + 1) / 2
                );

        box(game_win, 0, 0);
        wrefresh(game_win);
        wborder(game_win, vboard, vboard, hboard, hboard, corner, corner, corner, corner);
}

};
