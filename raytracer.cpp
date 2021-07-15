#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "vec3.h"
#include "color.h"
#include <iostream>
#include <cstring>
#include <stb_image_write.h>

// ppm image renderer, writes to stdout, must pipe output to file to view

int main() {
	//Image
	const int image_width = 520;
	const int image_height = 256;

	unsigned char data[image_width*image_height*3];
	unsigned char *data_ptr = data;

	for (int i = 0; i < image_height; i++) {
		std::cout << "\rRendering Line " << i+1 << " of " << image_height << std::flush;
		for (int j = 0; j < image_width; j++) {

			color pix_col = color(	static_cast<float>((image_height-i))/image_height,
									static_cast<float>((image_width-j))/image_width,
									static_cast<float>(j)/image_width);

			data_ptr = write_color(data_ptr, pix_col);
		}
	}
	std::cout << "\nRender Complete\n";

	stbi_write_jpg("out.jpg", image_width, image_height, 3, data, 100);
}