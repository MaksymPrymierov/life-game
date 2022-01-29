#include <form.h>
#include <screen_ncurses.h>

#include <cstring>

namespace game_life {

screen_ncurses::screen_ncurses(int w, int h, int life_prob)
    : screen(w, h, life_prob) {}

screen_ncurses::~screen_ncurses() {
  delwin(m_game_win_ptr);
  endwin();
}

void screen_ncurses::start() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);

  setup_options();
  refresh();

  m_screen_map.resize(m_height);
  for (auto &i : m_screen_map) {
    i.resize(static_cast<std::size_t>(m_width));
  }
  random_map_set();

  create_window();
}

void screen_ncurses::show() {
  for (int i = 1; i < m_height + 1; ++i) {
    for (int j = 1; j < m_width + 1; ++j) {
      if (m_screen_map.at(i - 1).at(j - 1)) {
        mvwaddch(m_game_win_ptr, i, j, m_life);
      } else {
        mvwaddch(m_game_win_ptr, i, j, m_dead);
      }
    }
  }

  wrefresh(m_game_win_ptr);
}

void screen_ncurses::create_window() {
  m_game_win_ptr = newwin(m_height + 2, m_width + 2, (LINES - m_height + 2) / 2,
                          (COLS - m_width + 2) / 2);
  wattron(m_game_win_ptr, COLOR_PAIR(1));

  box(m_game_win_ptr, 0, 0);
  wrefresh(m_game_win_ptr);
  wborder(m_game_win_ptr, m_vboard, m_vboard, m_hboard, m_hboard, m_corner,
          m_corner, m_corner, m_corner);
}

void screen_ncurses::setup_options() {
  FIELD *options[4];
  FORM *option_form;
  char form_data[3][128]; /* 0 - width, 1 - height, 2 - life_probability */
  int ch;
  int current_option;

  options[0] = new_field(1, 10, 4, 30, 0, 0);
  options[1] = new_field(1, 10, 6, 30, 0, 0);
  options[2] = new_field(1, 10, 8, 30, 0, 0);

  options[3] = NULL;

  for (int i = 0; i < 3; ++i) {
    set_field_back(options[i], A_UNDERLINE);
    field_opts_off(options[i], O_AUTOSKIP);
  }

  option_form = new_form(options);
  post_form(option_form);

  mvprintw(4, 10, "           Width: ");
  mvprintw(6, 10, "           Heigh: ");
  mvprintw(8, 10, "Life probability: ");
  refresh();

  form_driver(option_form, REQ_VALIDATION);
  while ((ch = getch()) != 10) { /* 10 - Enter */
    switch (ch) {
      case KEY_DOWN:
        form_driver(option_form, REQ_NEXT_FIELD);
        form_driver(option_form, REQ_END_LINE);
        break;
      case KEY_UP:
        form_driver(option_form, REQ_PREV_FIELD);
        form_driver(option_form, REQ_END_LINE);
        break;
      case KEY_LEFT:
        form_driver(option_form, REQ_PREV_CHAR);
        break;
      case KEY_RIGHT:
        form_driver(option_form, REQ_NEXT_CHAR);
        break;
      case KEY_DC:
        form_driver(option_form, REQ_DEL_CHAR);
        break;
      case KEY_BACKSPACE:
        form_driver(option_form, REQ_PREV_CHAR);
        form_driver(option_form, REQ_DEL_CHAR);
        break;
      default:
        form_driver(option_form, ch);
        form_driver(option_form, REQ_VALIDATION);
        current_option = field_index(current_field(option_form));
        strcpy(form_data[current_option],
               field_buffer(options[current_option], 0));
        refresh();
        break;
    }
  }

  m_width = strtol(form_data[0], NULL, 10);
  m_height = strtol(form_data[1], NULL, 10);
  m_life_probability = strtol(form_data[2], NULL, 10);

  unpost_form(option_form);
  free_form(option_form);
  free_field(options[0]);
  free_field(options[1]);
  free_field(options[2]);
}

};  // namespace game_life
