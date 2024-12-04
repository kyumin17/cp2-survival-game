#pragma once
#include <ncurses.h>
#include <unistd.h>
#include "../component/player.hpp"
#include "../component/enemy.hpp"
#include "../component/weapon.hpp"
#include "../component/block.hpp"
#include "../etc/character.hpp"

int startPage();

int playPage();

int selectWeaponPage();

int endPage();

int checkQuitPage();