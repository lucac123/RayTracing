#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <iostream>
#include <cstring>
#include <stb_image_write.h>

// ppm image renderer, writes to stdout, must pipe output to file to view

int main() {
    //Image
    const int image_width = 256;
    const int image_height = 256;

    unsigned char data[image_width*image_height*3];

    for (int i = 0; i < image_height; i++) {
        std::cout << "\rRendering Line " << i+1 << " of " << image_height << std::flush;
        for (int j = 0; j < image_width; j++) {
            int base_adr = (image_width*i+j)*3;
            data[base_adr] = (unsigned char)i;
            data[base_adr+1] = (unsigned char) j;
            data[base_adr+2] = (unsigned char) 125;
        }
    }
    std::cout << "\nRender Complete\n";

    stbi_write_jpg("out.jpg", image_width, image_height, 3, data, 100);
}