#pragma once
#include "block.hpp"
#include "../player/player.hpp"
#include <vector>
#include <random>

using namespace std;

class BlockContainer {
    public:
        int length;
        vector<Block*> array;
        BlockContainer();
        void createBlock(Player* player, int block_num);
        void draw();
};