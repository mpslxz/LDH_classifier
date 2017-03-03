#include "Beamlet.h"
#define round(X) floor(X+0.5)
vector<Point> FindPointsInPath(Point start, Point target){
    bool swap = 0;
    if (abs(target.y - start.y) > abs(target.x - start.x)){
        int buffer = target.x;
        target.x = target.y;
        target.y = buffer;
        buffer = start.x;
        start.x = start.y;
        start.y = buffer;
        swap = 1;
    }
    
    vector<Point> set;
    double Num = target.y - start.y;
    double Den = target.x - start.x;
    int step = (Den < 0)? -1 : 1;
    
    Point Next(start.x + step, -1);
    
    while(Next.y != target.y){
        Next.y = round((double) ((Num/Den) * (Next.x - start.x) + start.y ));
        Point newPoint = (swap) ? Point(Next.y,Next.x) : Point(Next.x , Next.y);
        set.push_back(newPoint);
        Next.x += step;
    } 
    return set;
}