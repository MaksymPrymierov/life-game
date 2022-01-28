# Life Game

[![CMake](https://github.com/MaksymPrymierov/life-game/actions/workflows/cmake.yml/badge.svg)](https://github.com/MaksymPrymierov/life-game/actions/workflows/cmake.yml)

## Install

### Prepare before building
**Ubuntu:** `sudo apt install cmake make gcc libfmt-dev libboost1.67-all-dev`

**Manjaro:** `pamac install cmake fmt boost`

### Building steps
* Clone the repository `git clone git@github.com:MaksymPrymierov/life-game.git`
* `cd life-game`
* `mkdir build && cd build`
* `cmake ..`
* `cmake --build .`

## Start the game
After the buiding just start the binary:
`./GameLife`
