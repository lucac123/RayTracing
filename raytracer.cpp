#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>
#include <stb_image_write.h>

color ray_color(const ray& r) {

	//t value between 0 and 1 depending on height of ray, higher value higher up on viewport
	float t = 0.5f*(r.direction().y()+1.0f);

	//fade out from white and into blue
	return (1.0f-t) * color(1.0f, 1.0f, 1.0f) + t * color(0.5f, 0.5f, 0.9f);
}

int main() {
	//Image Configuration
	const float aspect_ratio = 16.0f/9.0f;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width/aspect_ratio);

	//Camera
	float viewport_height = 2.0f;
	float viewport_width = viewport_height * aspect_ratio;
	float focal_length = 1.0f;

	point3 origin = point3();
	vec3 horizontal = vec3(viewport_width, 0, 0);
	vec3 vertical = vec3(0, viewport_height, 0);
	vec3 lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

	//Render
	unsigned char data[image_width*image_height*3];
	unsigned char *data_ptr = data;

	for (int i = image_height-1; i >= 0; i--) {
		std::cout << "\rRendering Line " << (image_height-i) << " of " << image_height << std::flush;
		for (int j = 0; j < image_width; j++) {
			ray cur_ray(origin, lower_left_corner + 
						horizontal * (static_cast<float>(j)/(image_width-1)) + 
						vertical * (static_cast<float>(i)/(image_height-1)) -
						origin);

			data_ptr = write_color(data_ptr, ray_color(cur_ray));
		}
	}
	stbi_write_jpg("out.jpg", image_width, image_height, 3, data, 100);

	std::cout << "\nRender Complete\n";
}