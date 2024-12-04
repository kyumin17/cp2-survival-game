#include "image-processing.hpp"

#define COLOR_DEPTH 8

using namespace std;

Image::Image(const char* _filename) {
	filename = _filename;
}

void Image::readImage() {
	/* initialize */
	FILE *fp = fopen(filename, "rb");
	png_structp png_ptr;
	png_infop info_ptr;

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	info_ptr = png_create_info_struct(png_ptr);

	png_init_io(png_ptr, fp);
	png_read_info(png_ptr, info_ptr);

	/* get image information */
	width = png_get_image_width(png_ptr, info_ptr);
	height = png_get_image_height(png_ptr, info_ptr);

	png_read_update_info(png_ptr, info_ptr);

	png_bytep* row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);
	for (int row  = 0; row < height; row++) {
		row_pointers[row] = (png_bytep)malloc(png_get_rowbytes(png_ptr, info_ptr));
	}

	png_read_image(png_ptr, row_pointers);

	/* get image_info */
	image = new Pixel*[height];
	for (int row = 0; row < height; row++) {
		image[row] = new Pixel[width];
	}

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			image[row][col].r = (int)row_pointers[row][col * 4];
			image[row][col].g = (int)row_pointers[row][col * 4 + 1];
			image[row][col].b = (int)row_pointers[row][col * 4 + 2];
			image[row][col].a = (int)row_pointers[row][col * 4 + 3];
		}
	}

	/* free memory */
	for (int row = 0; row < height; row++) {
		delete[] row_pointers[row];
	}
	delete[] row_pointers;

	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);
}

int Image::getColor(int r, int g, int b) {
	int colorValue[9][3] = {{0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {255, 255, 0}, {0, 0, 255}, {255, 0, 255}, {0, 255, 255}, 
	{255, 255, 255}, {0, 0, 0}};
	int minDiff = 255 * 255 * 3;
	int minDiffColor = -1;

	for (int i = 1; i < 9; i++) {
		int diff = pow(r - colorValue[i][0], 2) + pow(g - colorValue[i][1], 2) + pow(b - colorValue[i][2], 2);
		if (diff < minDiff) {
			minDiff = diff;
			minDiffColor = i;
		}
	}

	return minDiffColor;
}

void Image::getComponentImage(Cell**& character, int& newHeight, int& newWidth, char value) {
	readImage(); //read image
	float scale = (float)newHeight / height;
	newWidth = width * scale * 2;

	character = new Cell*[newHeight];
	for (int row = 0; row < newHeight; row++) {
		character[row] = new Cell[newWidth];
	}

	for (int row = 0; row < newHeight; row++) {
		for (int col = 0; col < newWidth; col++) {
			int img_row = (int)((float)row / scale);
			int img_col = (int)((float)col / (scale * 2));
			if (image[img_row][img_col].a == 0) {
				character[row][col].value = ' ';
			} else {
				character[row][col].value = value;
			}
			character[row][col].color = getColor(image[img_row][img_col].r, image[img_row][img_col].g, image[img_row][img_col].b);
		}
	}
}