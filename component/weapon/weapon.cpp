#include "weapon.hpp"

Weapon::Weapon(int _x, int _y, int _width, int _height, int _cooldown, Cell** _character)
: Component(_x, _y, _width, _height, _character) {
    cooldown = _cooldown;
    attack_time = 0;
}