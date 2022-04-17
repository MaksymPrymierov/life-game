#include <config.h>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <game.h>
#include <screen/factory.h>

#include <spdlog/spdlog.h>

#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

int main(int argc, char *argv[]) {
  std::unique_ptr<game_life::screen> screen;
  std::unique_ptr<game_life::game> game;
  game_life::screen_factory scr_factory;

  po::variables_map vm;
  po::options_description desc("Usage: ./GameLife [options]");
  std::string screen_type = "sdl";

  desc.add_options()("help,h", "Show the help page")(
      "screen,s", po::value<std::string>(&screen_type),
      "Select the game screen: cli, ncurses, sdl (default sdl)")(
      "version,v", "Print program version");

  po::parsed_options parsed = po::command_line_parser(argc, argv)
                                  .options(desc)
                                  .allow_unregistered()
                                  .run();
  po::store(parsed, vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << std::endl;
    fmt::print(
        "\nReport bugs to "
        "<https://github.com/MaksymPrymierov/life-game/issues>\n");
    return 0;
  }

  if (vm.count("version")) {
    fmt::print("Game Life Version: {}.{}\n", GameLife_VERSION_MAJOR,
               GameLife_VERSION_MINOR);
    return 0;
  }

  screen = std::move(scr_factory.get(screen_type));
  screen->start();
  game = std::make_unique<game_life::game>(screen);

  if (game->start()) {
    spdlog::error("Game of Life has been failed.");
    return -1;
  }

  return 0;
}
