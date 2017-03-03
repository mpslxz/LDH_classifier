#include "Beamlet.h"

void initialize(vector<Point> &border , int s){
    int dim = 4*s - 4;
    for(int i=0;i<dim;i++)
    {
        Point p;
        if(i/(s-1) == 0) p = Point(0,i);
        if(i/(s-1) == 1) p = Point(i%(s-1),s-1);
        if(i/(s-1) == 2) p = Point(s-1,s-1-(i%(s-1)));
        if(i/(s-1) == 3) p = Point(s-1-(i%(s-1)),0);
                
        border.push_back(p);		
    }	
}