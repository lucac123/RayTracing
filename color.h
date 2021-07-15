#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>
#include <cstring>

unsigned char *write_color(unsigned char *buf, color pixel_color) {
	buf[0] = static_cast<int>(pixel_color.x() * 255.999f);
	buf[1] = static_cast<int>(pixel_color.y() * 255.999f);
	buf[2] = static_cast<int>(pixel_color.z() * 255.999f);

	return buf+3;
}

#endif