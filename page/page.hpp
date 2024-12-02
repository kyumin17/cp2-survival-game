#pragma once
#include <ncurses.h>
#include <unistd.h>
#include <random>
#include "../component/player.hpp"
#include "../component/enemy.hpp"
#include "../component/bullet.hpp"
#include "../component/block.hpp"
#include "../etc/character.hpp"

int startPage();

int selectStagePage();

void stage1Page();

void stage2Page();

void stage3Page();

void endingPage();

int checkQuitPage();