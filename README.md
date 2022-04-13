# Life Game

[![CMake](https://github.com/MaksymPrymierov/life-game/actions/workflows/cmake.yml/badge.svg)](https://github.com/MaksymPrymierov/life-game/actions/workflows/cmake.yml)
[![Softacheck](https://softacheck.com/app/repository/MaksymPrymierov/life-game/badge)](https://softacheck.com/app/repository/MaksymPrymierov/life-game/issues)

## Install

### Install conan
`pip install conan`

### Building steps
* Clone the repository `git clone git@github.com:MaksymPrymierov/life-game.git`
* `cd life-game`
* `mkdir build && cd build`
* `conan install .. --install-folder cmake-build-release --build=missing`
* `cmake ..`
* `cmake --build .`

## Start the game
After the buiding just start the binary:
`./GameLife`

## Start unit tests
* `cd life-game/build`
* `ctest`
