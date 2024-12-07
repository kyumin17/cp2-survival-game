#pragma once
#include <ncurses.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include "../component/player.hpp"
#include "../component/enemy.hpp"
#include "../component/bullet.hpp"
#include "../component/block.hpp"
#include "../etc/character.hpp"

int startPage();

int selectStagePage();

void stage1Page();

int endingPage();

int checkQuitPage();

int checkQuitStage();

int checkQuitStart();