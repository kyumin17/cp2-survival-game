#pragma once
#include <png.h>
#include <cmath>
#include <ncurses.h>
#include <stdlib.h>
#include "../component/component.hpp"

struct Pixel {
	png_byte r, g, b, a;
};

class Image {
	public:
		const char* filename;
		int width;
		int height;
		Pixel** image;
		Image(const char* _filename);
		void readImage();
		int getColor(int r, int g, int b);
		void getComponentImage(Cell**& character, int& newHeight, int& newWidth, char value);
};