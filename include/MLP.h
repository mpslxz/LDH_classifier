#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>
#include <memory>

using namespace cv;
using namespace std;

extern CvANN_MLP createNet();
extern void trainNet(CvANN_MLP& net, Mat trainingSet, Mat targets);
extern void saveNet(CvANN_MLP net, string path);
extern void readNet(CvANN_MLP& net, string path);
extern bool predict(CvANN_MLP& net, Mat sample);
extern void dataReader(Mat& data, Size s, string path);
extern Mat makeFeatureVector(double* vec, int len);
extern void help();
