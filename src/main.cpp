#include <config.h>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <game.h>
#include <screen/factory.h>

void help() {
  fmt::print(fg(fmt::color::yellow), "Usage: ./GameLife [options]\n");
  fmt::print("Options:\n");
  fmt::print(
      "  -c --cli\tStart the game with default command line interface\n");
  fmt::print("  -h --help\tPrint the help page\n");
  fmt::print(
      "  -n --ncurses\tStart the game with ncurses command line interface\n");
  fmt::print("  -s --sdl\tStart the game with sdl graphic library\n");
  fmt::print("  -v --version\tPrint version\n");

  fmt::print(
      "\nReport bugs to "
      "<https://github.com/MaksymPrymierov/life-game/issues>\n");
}

int main(int argc, char *argv[]) {
  game_life::screen *screen;
  game_life::game *game;
  game_life::screen_factory scr_factory;
  std::vector<std::string> args;
  bool is_game_screen = false;

  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  if (argc == 1) {
    screen = scr_factory.get("sdl");
    is_game_screen = true;
  }

  for (const auto &i : args) {
    if (i == "--help" || i == "-h") {
      help();
    } else if (i == "--cli" || i == "-c") {
      if (!is_game_screen) {
        is_game_screen = true;
        screen = scr_factory.get("cli");
      } else {
        fmt::print(fg(fmt::color::red),
                   "Error: You can choose only one game screen\n");
        return -1;
      }
    } else if (i == "--ncurses" || i == "-n") {
      if (!is_game_screen) {
        is_game_screen = true;
        screen = scr_factory.get("ncurses");
      } else {
        fmt::print(fg(fmt::color::red),
                   "Error: You can choose only one game screen\n");
        return -1;
      }
    } else if (i == "--sdl" || i == "-s") {
      if (!is_game_screen) {
        is_game_screen = true;
        screen = scr_factory.get("sdl");
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

  delete screen;

  return 0;
}
