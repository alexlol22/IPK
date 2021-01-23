#include <array>
#include <math.h>

using namespace std;

template<typename Coord=double, int dim=3>
class Point{
    public:
        using Coordinate = Coord; // in der aufgabe stand export; das soll doch never etwas mit dem c++-keyword zu tun haben???
        Point(){coords=array<Coordinate, dim>();};
        Point(array<Coordinate, dim> arrayToCopyFrom):
            coords{arrayToCopyFrom}{};
        static const int dimension = dim;
        
    private:
        array<Coord, dim> coords;
        
    public:
        Coord norm(){
            Coord underroot = 0;
            for (size_t i=0; i<dim; i++){
                underroot += pow(coords[i], 2);
            }
            return sqrt(underroot);
        }

        Coord& operator[](int i){return coords[i];};

        const Coord& operator[](int i) const{return coords[i];};
};
