#include "point.h"
#include <vector>
#include <string.h>
#include "pgm.h"

using namespace std;

class Canvas{
    public:
        const Point center;
        const double width;
        const double height;
        const size_t pixelx;
        const int pixely;

        vector<vector<int>> grayscales{pixelx,{vector<int>(pixely, {})}};

        Canvas(const Point& center, double width, double height,
               size_t horPixels, int vertPixels): 
               center(center), width{width}, height{height},
               pixelx{horPixels}, pixely{vertPixels}{};
        
        int brightness(int i, int j){ return grayscales[i][j];}
        void setBrightness(int i, int j, int brightness) {grayscales[i][j] = brightness;}
        Point coord(int i, int j);
        void write(const string& filename);
};