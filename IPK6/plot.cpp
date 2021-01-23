#include "point.h"
#include "iostream"
#include "canvas.h"
#include <math.h>


int main(){
    int xsize = 4000;
    int ysize = 3000;
    auto c = Canvas(Point(), 4, 3, xsize, ysize);
    int grayval = 0;
    for (int x=0; x<xsize; x++){
        for (int y=0; y<ysize; y++){
            grayval = 100*(sin(double(x)/30)+sin(double(y)/30)+1);
            c.setBrightness(x, y, max(0, grayval));
        }
    }
    c.write("ThanksIHateIt.pgm");
}