#include "Beamlet.h"

Mat Beamlet(Mat img, int s, Point& beamBase)
{
    int dim = 4*s - 4;
    vector<Point> border;
    // initialize the matrix border so that elements in border are the ones 
    //lying along the edges of the dyadic square
    initialize(border, s);
    
    //parameters
    double ratio = 0.1;
    double delta = s * sqrt((double)2) * ratio;
    // end of parameters
    
    double Max = 0;
    Mat result = Mat::zeros(Size(s,s),CV_8U);
    vector<Point> Beamlet;
    vector<Point> bestPath;
	Point start, target;			//points that the function calculates 
									//the beamlet coefficient along the
									//line passing through them
	//Point cCntr;
	for(int i = 0; i < dim ; i++){
        for(int j = 0; j < dim ; j++){
            
            
            start = border[i];
            target = border[j];
            // function that returns the Euclidean distance between two points 
            double D = dist(start, target);
			auto slope = (target.y - start.y) / (target.x - start.x + 0.00001);
            if(D > delta && target.x != start.x && slope < 0  && abs(slope) > 0.5){ // vertical beams have been discarded
                //function that returns the vector of points lying on the path 
                //between start and target in image
                vector<Point> path = FindPointsInPath(start,target);
                
                double res = 0;
                for(int l = 0; l < path.size(); l++)
                        res += img.at<uchar>(path[l].x , path[l].y);
                
                double measure = res / D; //SUM(path,img);
                
                if(Max < measure && res>(64*D)){
					//cout<<i<<" "<<j<<endl;
                    /*Beamlet.clear();
                    Beamlet.push_back(start);
                    Beamlet.push_back(target);*/
                    Max = measure;
                    bestPath.clear();
                    bestPath = path;
					//cCntr = start;
					beamBase = bestPath[0];
                }
            }            
        }
    }
	/*for (int i = 0; i < bestPath.size(); i++){
		result.at<uchar>(bestPath[i].x, bestPath[i].y) = 255;
		
	}*/
	/*namedWindow("IT", 0);
	imshow("IT", result);
	waitKey();*/
	
	if (bestPath.size() != 0){
		Point A(bestPath[0].y, bestPath[0].x);
		if (A.x > A.y){
			A.x = bestPath[bestPath.size() - 1].y;
			A.y = bestPath[bestPath.size() - 1].x;
		}
		beamBase = A;
		//circle(result, A, 5, Scalar(255, 255, 255));
	}
	
	/*namedWindow("IT", 0);
	imshow("IT", result);
	waitKey();*/

    return result;
}