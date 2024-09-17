# Todo List

- [ ] Structure the file directory.
- [ ] Create a function to be able to clean the screen independently of the OS.
- [ ] Prestige system and how it will influence history.
- [ ] Write the general script of the story.
- [ ] Make the visual art for the card game.
- [ ] Create the menu system and the TUI to interact with the game.

- [x] Create a bash script to automate the process of compiling and running the game in C++.

# Development Guide

## Variable Naming
Variables should follow the `snake_case` style. Here are some examples:

```c++
int player_score;
string game_title;
bool is_game_over;
```

## File Naming
Files should follow the `kebab-case.cpp` style. Here are some examples:

```
player-score.cpp;
game-title.txt;
is-game-over.hpp;
```

## Commits
For commits, we follow the [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) philosophy. Here are some examples:

```
feat(engine): add collision detection
fix(player): correct health decrement bug
chore(tests): add unit tests for new game feature
docs(readme): update setup instructions
```

## Branching
Never push directly to `main`. Always create a new branch to implement features or make changes. Branches should follow the `type/description` style. Here are some examples:

```
feature/add-new-level
fix/correct-score-calculation
refactor/update-variable-names
chore/update-build-script
```
Once you've finished working on your branch, you can merge it into `main`.

# Project Structure

The main game is executed from `main.cpp` in the project root. This file links to the `.hpp` and other `.cpp` files in other directories.

For example:

```c++
#include "engine/game_engine.hpp"
#include "player/player.h"
```
Please make sure to maintain this structure when adding new features or making changes to existing code.

# Game Mechanics

## Card System
The game is based on a card system. The specific gameplay has not yet been decided, so a detailed description of how it works will be provided in a future update.

## Prestige
Prestige is a key metric in the game. Winning or losing matches will grant you different amounts of prestige. Prestige influences various aspects of the game, as detailed below.

## Events
Depending on your prestige level, you can experience different events. For example, if you have 100 prestige, you can experience one of 5 different events. If in one of those events you gain 50 prestige, you can now experience a different set of 5 events. Events can overlap based on the required prestige levels.
It's important to keep your prestige above 0, as reaching 0 will result in a game over.

## Story Blocks
The game is structured into story blocks. These are segments of the game that you must go through to progress. Each story block has random events that can occur, and the randomness of these events is based on %$@$%!$*&&.

Please keep these mechanics in mind when developing and testing new features for the game.
