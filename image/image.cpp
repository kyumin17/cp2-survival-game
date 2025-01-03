#include "image.hpp"

Image::Image(const vector<string>& text, int color)
:row(text.size()), col(text[0].size()) {
    data = new Cell*[row];
    for (int i = 0; i < row; i++) {
        data[i] = new Cell[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            data[i][j].value = text[i][j];
            data[i][j].color = color;
        }
    }
}

Image::~Image() {
    for (int i = 0; i < row; i++) {
        delete[] data[i];
    }
    delete[] data;
}