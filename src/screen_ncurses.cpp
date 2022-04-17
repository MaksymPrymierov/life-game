#include <form.h>
#include <screen_ncurses.h>

#include <spdlog/spdlog.h>

#include <cstring>

namespace game_life {

screen_ncurses::screen_ncurses(int w, int h, int life_prob)
    : screen(w, h, life_prob) {}

screen_ncurses::~screen_ncurses() {
  if (delwin(m_game_win_ptr) != 0) {
    spdlog::warn("Delete ncurses windows has been failed.");
  }

  if (endwin() != 0) {
    spdlog::warn("End ncurses windows has been failed.");
  }

  spdlog::info("Ncurses screen has been destroyed.");
}

void screen_ncurses::start() {
  setlocale(LC_ALL, "");

  if (!initscr()) {
    spdlog::warn("Init ncurses screen has been failed.");
  }

  if (cbreak() != 0) {
    spdlog::warn("Terminal ncurses settings has been failed.");
  }

  if (keypad(stdscr, TRUE) != 0) {
    spdlog::warn("Keyboard ncurses settings has been failed.");
  }

  if (noecho() != 0) {
    spdlog::warn("Disable ncurses terminal echo has been failed.");
  }

  if (start_color() != 0) {
    spdlog::warn("Init ncurses colors has been failed.");
  }

  if (init_pair(1, COLOR_RED, COLOR_BLACK) != 0 && init_pair(2, COLOR_WHITE, COLOR_BLACK) != 0) {
    spdlog::warn("Ncurses color settings has been failed.");
  }

  setup_options();

  if (refresh() != 0) {
    spdlog::warn("Refresh ncurses terminal has been failed.");
  }

  alloc_screen_map();
  random_map_set();

  create_window();
}

int screen_ncurses::show() {
  if (!is_valid()) {
    spdlog::error("NCurses screen is invalid.");
    return -1;
  }

  for (int i = 1; i < m_height + 1; ++i) {
    for (int j = 1; j < m_width + 1; ++j) {
      if (m_screen_map.at(i - 1).at(j - 1)) {
        mvwadd_wch(m_game_win_ptr, i, j, reinterpret_cast<const cchar_t*>(m_life.data()));
      } else {
        mvwadd_wch(m_game_win_ptr, i, j, reinterpret_cast<const cchar_t*>(m_dead.data()));
      }
    }
  }

  wrefresh(m_game_win_ptr);

  return 0;
}

void screen_ncurses::print_life_status(size_t life_status, size_t dead_status) {
  wprintw(m_game_win_ptr, "   Life status: [%lu], Dead status [%lu]", life_status,
          dead_status);
}

void screen_ncurses::create_window() {
  m_game_win_ptr = newwin(m_height + 2, m_width + 4, (LINES - m_height) / 2,
                          (COLS - m_width) / 2);
  wattron(m_game_win_ptr, COLOR_PAIR(1));

  box(m_game_win_ptr, 0, 0);
  wrefresh(m_game_win_ptr);
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
