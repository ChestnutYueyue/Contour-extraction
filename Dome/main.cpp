#include <Contour.h>

int main(int argc, char **argv)
{

    Contour contour("./corridor.jpg");
    contour.findContours();
    contour.show();
    contour.save();
    return 0;
}
