#include "Beamlet.h"

double dist(Point P1, Point P2){
    return (sqrt( pow(double(P1.x - P2.x),double(2)) + pow(double(P1.y - P2.y),(double)2) ));
}
