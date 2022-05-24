#include <Contour.h>

int main(int argc, char **argv)
{

    Contour contour("./你好.jpg");
    contour.findContours();
    contour.show();
    contour.save();
    return 0;
}
