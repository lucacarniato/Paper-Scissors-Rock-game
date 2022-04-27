# Assignment 1

## Introduction

The Paper-Scissors-Rock game. The code is documented using Doxygen and consists of a library, the main executable, and unit tests.
CMake is used for the build, see the instructions below for the build.

The main classes are:

 + Hands: A class enum with the hand types (paper, scissors, or rock)
 + Player (abstract): the virtual getHand method gets the hand of the specific player at each round
 + Rules: A class taking as constructor parameter a table of rules. This table is used to determine which hand wins against another.
 Because rules can be configured using a simple table, Rules is not an abstract class. This could be reconsidered in case the getWinner method must also be overwritten.
 + Game: composes the rules and the players, and holds the statistics of the game (how many times a specific player has won, and how many ties)

## Build

The build requirements are:

- CMake 3.19.3 or higher
- A C++17 compatible compiler

Linux

```bash
cmake -S . -B xbuild -G"Unix Makefiles"
cd xbuild
make
```

Windows
```powershell
cmake -S . -B xbuild -G"Visual Studio 16 2019"
cmake --build build
```
