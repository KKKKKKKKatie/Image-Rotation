#include "Sepia.h"
#include <vector>
using namespace std;

Sepia::Sepia(Image *image): Decorator{image} {}

void Sepia::render(PPM &ppm) {
	image->render(ppm);
	vector<Pixel> p = ppm.getPixels();
	vector<Pixel> np = ppm.getPixels();
	for (int i=0; i < p.size(); i++) {
		np[i].r = p[i].r * 0.393 + p[i].g * 0.769 + p[i].b * 0.189;
		np[i].g = p[i].r * 0.349 + p[i].g * 0.686 + p[i].b * 0.168;
		np[i].b = p[i].r * 0.272 + p[i].g * 0.534 + p[i].b * 0.131;
		if (np[i].r > colourMax) np[i].r = 255;
		if (np[i].g > colourMax) np[i].g = 255;
		if (np[i].b > colourMax) np[i].b = 255;
	}
	ppm.getPixels() = np;
}

