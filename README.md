# Life Game

[![CMake](https://github.com/MaksymPrymierov/life-game/actions/workflows/cmake.yml/badge.svg)](https://github.com/MaksymPrymierov/life-game/actions/workflows/cmake.yml)
[![Softacheck](https://softacheck.com/app/repository/MaksymPrymierov/life-game/badge)](https://softacheck.com/app/repository/MaksymPrymierov/life-game/issues)

## Install

### Prepare before building
**Ubuntu:** `sudo apt install cmake make gcc-10 g++-10 libfmt-dev libboost1.67-all-dev libsdl2-dev libsdl2-2.0-0`

**Manjaro:** `pamac install cmake fmt boost sdl2 gcc-10 python-pip`

`pip install conan`

### Building steps
* Clone the repository `git clone git@github.com:MaksymPrymierov/life-game.git`
* `cd life-game`
* `mkdir build && cd build`
* `sudo -v`
* `cmake -DCMAKE_CXX_COMPILER=g++-10 -DCMAKE_C_COMPILER=gcc-10 -DCMAKE_BUILD_TYPE=Release ..`
* `cmake --build .`

## Start the game
After the buiding just start the binary:
`./GameLife`
