#include "Beamlet.h"

vector<Mat> partition(Mat img, int scale)
{
    vector<Mat> partitionedImg;
    Size S(img.rows,img.cols);// = (Size) img.size;
	
    if(pow((double)2,(double)scale) >= img.rows) cerr <<"Scale = 2^"<<scale<<" should be less than the image size\n";
    int stepSize = img.rows / pow((double)2,(double)scale) -1;
    for(int i=0;i<S.height;i = i+1+stepSize)
    {
        for(int j=0; j<S.width; j = j+1+stepSize)
        {
            Mat subImg = img(Rect(Point(i,j), Size(stepSize+1,stepSize+1)));
            int k = subImg.rows;
            partitionedImg.push_back(subImg);
        }
    }
    return partitionedImg;
}