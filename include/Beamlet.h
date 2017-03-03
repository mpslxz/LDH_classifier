/* 
 * File:   Beamlet.h
 * Author: Admin
 *
 * Created on March 26, 2014, 5:35 PM
 */

#ifndef BEAMLET_H
#define	BEAMLET_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;

extern void initialize(vector<Point> &border, int s);
extern vector<Point> FindPointsInPath(Point start, Point target);
extern double SUM(vector<Point> path , Mat img);
extern double dist(Point P1, Point P2);
extern Mat Beamlet(Mat img, int s, Point& beamBase);
extern vector<Mat> partition(Mat img, int scale);
extern Mat merge(vector<Mat> splitted);
#endif	/* BEAMLET_H */

