/*
Caleb Reister
2014-03-11

This is a simple image generator created to test 2d arrays.
It outputs a PPM file with several gradients and a sold square(ish) shape in the
middle.
*/

#include "ImageGenerator.hh"
using namespace std;

int main()
{
    Color image[WIDTH][HEIGHT];
    ofstream ppm;

    drawGradiant(image);
    drawCircle(image);

    ppm.open("GeneratedImage.ppm");

    ppm << "P3" << endl << WIDTH << " " << HEIGHT << " " << 255
         << endl << endl;

    for (int h = 0; h < HEIGHT; h++)
    {
        for (int w = 0; w < WIDTH; w++)
            ppm << image[w][h];
        ppm << endl;
    }

    ppm.close();
}

void drawGradiant(Color img[][HEIGHT])
{
    int w;
    int h;
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < 75; w++)
            img[w][h].r = h;
        for (w = 75; w < 150; w++)
            img[w][h].g = h;
        for (w = 150; w < WIDTH; w++)
            img[w][h].b = h;
    }
}

void drawCircle(Color img[][HEIGHT])
{
    int w;
    int h;
    for (h = 125; h < 175; h++)
        for (w = 88; w < 138; w++)
        {
            img[w][h].r = 255;
            img[w][h].g = 240;
        }
}

