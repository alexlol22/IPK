#include "canvas.h"

Point Canvas::coord(int i, int j){
    auto lowerLeft = Point(center.x()-width/2, center.y()-height/2);
    return Point(lowerLeft.x()+(width/pixelx)*i, lowerLeft.y()+(height/pixely)*j);
}

void Canvas::write(const string& filename){
    write_pgm(grayscales, filename);
}
