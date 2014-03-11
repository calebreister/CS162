#include <iostream>
#include <fstream>
#include <iomanip>
#include <cinttypes>

const int WIDTH = 225;
const int HEIGHT = 300;

struct Color
{
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
        //the following overloads for both cout and ofstream
        friend std::ostream& operator<<(std::ostream& out, Color in)
        {
            out.fill('0');
            out.flags(std::ios::internal);
            out << std::setw(3) << static_cast<int>(in.r) << " "
                << std::setw(3) << static_cast<int>(in.g) << " "
                << std::setw(3) << static_cast<int>(in.b) << "    ";
            return out;
        }
};

void drawGradiant(Color img[][HEIGHT]);
void drawCircle(Color img[][HEIGHT]);
