#include "block_container.hpp"

BlockContainer::BlockContainer(): length(0) {
    
}

void BlockContainer::createBlock(Player* player, int block_num) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis_pos(-500, 492);
    uniform_int_distribution<int> dis_len(4, 8);
    uniform_int_distribution<int> dis_active(1, 3);

    // 블럭 생성
    for (int i = 0; i < block_num; i++) {
        bool is_active = dis_active(gen) == 1 ? true : false;
        array.push_back(new Block(dis_pos(gen), dis_pos(gen), dis_len(gen), is_active));
    }

    // 플레이어 위치와 겹치지 않도록 생성
    for (int i = 0; i < block_num; i++) {
        if (array[i] -> isOverlap(player -> x, player -> y, player -> width, player -> height)) {
            array.erase(array.begin() + i);
        }
    }
}

void BlockContainer::draw(Display display) {
    for (size_t i = 0; i < array.size(); i++) {
        array[i] -> draw();
    }
}