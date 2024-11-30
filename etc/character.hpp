#pragma once
#include "../component/component.hpp"

class PlayerCharacter {
    public:
        Cell** left;
        Cell** right;
        Cell** back;
        Cell** front;
        PlayerCharacter();
};

class EnemyCharacter {
    public:
        Cell** front;
        EnemyCharacter();
};

class BulletShape {
    public:
        Cell** bullet;
        BulletShape();
};