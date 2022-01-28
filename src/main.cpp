#include <config.h>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <game.h>
#include <screen_cli.h>
#include <screen_ncurses.h>

void help() {
  fmt::print(fg(fmt::color::yellow), "Usage: ./GameLife [options]\n");
  fmt::print("Options:\n");
  fmt::print(
      "  -c --cli\tStart the game with default command line interface\n");
  fmt::print("  -h --help\tPrint the help page\n");
  fmt::print(
      "  -n --ncurses\tStart the game with ncurses command line interface\n");
  fmt::print("  -v --version\tPrint version\n");

  fmt::print(
      "\nReport bugs to "
      "<https://github.com/MaksymPrymierov/life-game/issues>\n");
}

int main(int argc, char *argv[]) {
  game_life::screen *screen;
  game_life::game *game;
  std::vector<std::string> args;
  bool is_game_screen = false;

  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  if (argc == 1) {
    screen = new game_life::screen_ncurses;
    is_game_screen = true;
  }

  for (const auto &i : args) {
    if (i == "--help" || i == "-h") {
      help();
    } else if (i == "--cli" || i == "-c") {
      if (!is_game_screen) {
        is_game_screen = true;
        screen = new game_life::screen_cli;
      } else {
        fmt::print(fg(fmt::color::red),
                   "Error: You can choose only one game screen\n");
        return -1;
      }
    } else if (i == "--ncurses" || i == "-n") {
      if (!is_game_screen) {
        is_game_screen = true;
        screen = new game_life::screen_ncurses;
      } else {
        fmt::print(fg(fmt::color::red),
                   "Error: You can choose only one game screen\n");
        return -1;
      }
    } else if (i == "--version" || i == "-v") {
      fmt::print("Game Life Version: {}.{}\n", GameLife_VERSION_MAJOR,
                 GameLife_VERSION_MINOR);
    } else {
      fmt::print(fg(fmt::color::red),
                 "Error: Unknow argument {}. Try to use --help argument.\n", i);
    }
  }

  if (!is_game_screen) {
    return 0;
  }

  screen->start();
  game = new game_life::game(screen);
  game->start();

  return 0;
}
