#include <fstream>
//Would have used uint8_t under <cstdint> but
//the compiler could not resolve the type

const int WIDTH = 200;
const int HEIGHT = 300;

struct Color
{
        unsigned char r, g, b;
};

void drawGradiant(Color img[][HEIGHT]);
void drawCircle(Color img[][HEIGHT]);
