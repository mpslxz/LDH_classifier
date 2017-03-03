#include "Beamlet.h"

double SUM(vector<Point> path , Mat img){
    double res = 0;
    for(int i = 0; i < path.size(); i++)
        res += img.at<uchar>(path[i].x , path[i].y);
    return res;
}