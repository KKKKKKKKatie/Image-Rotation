#include "Rotate.h"
#include <vector>
using namespace std;

Rotate::Rotate(Image *image): Decorator{image} {}

void Rotate::render(PPM &ppm) {
	image->render(ppm);
	vector<Pixel> p = ppm.getPixels();
	vector<Pixel> newPixel = ppm.getPixels();
	int h = ppm.getHeight();
	int w = ppm.getWidth();
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			newPixel[i*h+j] = p[w*(h-j-1)+i];
		}
	}
	ppm.getWidth() = h;
	ppm.getHeight() = w;
	ppm.getPixels() = newPixel;
}

