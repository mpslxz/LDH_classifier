#ifndef LDH_H
#define	LDH_H
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <math.h>
#include <memory>
using namespace cv;
using namespace std;

extern std::shared_ptr<cv::Mat> loadTransMat(const string path,const int size);
extern std::shared_ptr<cv::Mat> hadamard(const std::shared_ptr<cv::Mat> op, const std::shared_ptr<cv::Mat> tr);
extern std::shared_ptr<cv::Mat> applyWedgeFilter(const std::shared_ptr<cv::Mat> op, const shared_ptr<cv::Mat> filter);
extern void nonZeroVariance(const std::shared_ptr<cv::Mat> op, std::shared_ptr<float> var);
extern std::shared_ptr<std::vector<cv::Point>> loadFilter(const string path);
extern void fastNonZeroVariance(const std::shared_ptr<cv::Mat> op, const std::shared_ptr<std::vector<cv::Point>> wedge, std::shared_ptr<float> var);
extern std::shared_ptr<vector<cv::Mat>> partitionImage(const std::shared_ptr<cv::Mat> img, const int scale);
extern std::shared_ptr<cv::Mat> LDHfeatures(const std::shared_ptr<cv::Mat> image, const std::shared_ptr<vector<cv::Mat>> HadMats, const std::shared_ptr<vector<vector<cv::Point>>> filters, const int SIZE, const int DEC_SCALE);
extern std::shared_ptr<vector<cv::Mat>> initializeHadamardMatrices(const std::string path);
extern std::shared_ptr<vector<vector<cv::Point>>> initializeWedgeFilters(const std::string path);
extern void makeTrainingData(const std::string path);
void print(Mat B);
#endif	/* LDH_H */
