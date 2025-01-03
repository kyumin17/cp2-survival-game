#pragma once
#include <vector>
#include <cmath>
#include "../component.hpp"
#include "../block/block.hpp"
#include "../enemy/enemy.hpp"

using namespace std;

class Weapon: public Component {
    public:
        int attackTime; //공격 유지 시간 측정
        int cooldown; //쿨타임
        Weapon(int _x, int _y, int _width, int _height, int _cooldown, Cell** _character);
};