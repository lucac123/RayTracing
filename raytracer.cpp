#include <iostream>

// ppm image renderer, writes to stdout, must pipe output to file to view

int main() {
    //Image
    const int image_width = 256;
    const int image_height = 256;

    std::cout << "P3" << std::endl << image_width << ' ' << image_height << std::endl << 255 << std::endl;

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            std::cout << i << '\t' << j << '\t' << (i+j)/2 << std::endl;
        }
    }
}