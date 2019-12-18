#include "Decorator.h"
#include "image.h"

Decorator::Decorator(Image *image): image{image} {}

Decorator::~Decorator() {
	if (image) delete image;
}

