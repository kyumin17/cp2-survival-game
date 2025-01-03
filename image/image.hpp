#pragma once
#include "../component/component.hpp"
#include <vector>
#include <string>

using namespace std;

class Image {
    public:
        int row;
        int col;
        Cell** data;
        Image() {};
        Image(const vector<string>& text, int color);
        ~Image();
};