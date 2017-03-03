#include "Beamlet.h"

Mat merge(vector<Mat> splitted)
{
    int M = splitted[0].rows;
    Mat res(M*sqrt((double)splitted.size()),M*sqrt((double)splitted.size()),CV_8U);
    int stepSize = M;
    int count = 0;
    for(int i=0;i<res.rows;i = i+stepSize)
    {
        for(int j=0;j<res.cols;j = j+stepSize)
        {
            splitted[count].copyTo(Mat(res,Rect(Point(i,j),Size(M,M))));
            count++;
        }
    }
    return res;
}