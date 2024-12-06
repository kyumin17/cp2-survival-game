#pragma once
#include "../component/component.hpp"
#include <vector>

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

class BowShape {
    public:
        Cell** bowRight;
        Cell** bowLeft;
        Cell** bowDown;
        Cell** bowUp;
        Cell** arrowRight;
        Cell** arrowLeft;
        Cell** arrowDown;
        Cell** arrowUp;
        BowShape();
};

class PoleShape {
    public:
        Cell** poleRight[5];
        Cell** poleLeft[5];
        PoleShape();
};

class DiskShape {
    public:
        Cell** disk;
        DiskShape();
};