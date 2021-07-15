#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

void write_color(std::ostream& out, color pixel_color) {
	out << static_cast<int>(pixel_color.x())
		<< static_cast<int>(pixel_color.y())
		<< static_cast<int>(pixel_color.z());
}

#endif