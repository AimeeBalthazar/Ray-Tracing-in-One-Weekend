#include "color.h"
#include "vec3.h"

#include <iostream>
#include <fstream>

void write_color(std::ofstream& os, const color& pixel_color) {
    os << static_cast<int>(pixel_color.e[0] * 255) << " " <<
    static_cast<int>(pixel_color.e[1] * 255) << " " <<
    static_cast<int>(pixel_color.e[2] * 255) << " ";
}

int main() {

    //Image

    int image_width = 256;
    int image_height = 256;

     // Create a file stream to output the image data
    std::ofstream file("image2.ppm");

    // Render the image
    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            color pixel_color = color(double (i)/(image_width-1), double(j)/(image_height-1),0);
            write_color(file, pixel_color);
            }
            file << "\n"; // write a newline after each row
        }
    }

