#include "Flip.h"
#include <vector>
using namespace std;

Flip::Flip(Image *image): Decorator{image} {}

void Flip::render(PPM &ppm) {
	image->render(ppm);
	vector<Pixel> p = ppm.getPixels();
	vector<Pixel> newPixel = ppm.getPixels();
	int h = ppm.getHeight();
	int w = ppm.getWidth();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			newPixel[j+i*w] = p[i*w+w-j-1];
		}
	}
	ppm.getPixels() = newPixel;
}

