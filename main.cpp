#include <vector>
#include <cmath>
#include "tgaimage.h"
#include "model.h"
#include "geometry.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
Model *model = NULL;
const int width  = 800;
const int height = 800;


void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor colour) {
    bool steep = false;

    if (abs(x0 - x1 < abs(y0 - y1))) {
        std::swap(x0, y0);
            std::swap(x1, y1);
            steep = true;

    }


        // make the line left to right

            if (x0 > x1){
                std::swap(x0, x1);
                std::swap(y0, y1);

        }


            for (int x = x0; x <= x1; x++) {
                int t = (x - x0) / (x1 - x0);
                int y = y0 * (1 - t) + y1 * t;
                // if the image is transposed, de transpose it
                if (steep) {
                    image.set(y, x, colour);
                }
                else {
                    image.set(x, y, colour);
                    
                }
                    
            }


}
    

int main(int argc, char** argv) {
    
    TGAImage image(width, height, TGAImage::RGB);

    line(0, 0, width, height, image, red);

    image.flip_vertically(); // we want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    delete model;
    return 0;
}



