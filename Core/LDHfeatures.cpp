#include "LDH.h"


std::shared_ptr<cv::Mat> LDHfeatures(const std::shared_ptr<cv::Mat> image, const std::shared_ptr<vector<cv::Mat>> HadMats, const std::shared_ptr<vector<vector<cv::Point>>> filters, const int SIZE, const int DEC_SCALE)
{
	resize(*image, *image, Size(SIZE, SIZE));
	normalize(*image, *image, 0, 1, NORM_MINMAX, CV_32F);
	auto featureVectorLength = 0;
	for (auto i = 0; i < DEC_SCALE; i++)
		featureVectorLength += pow(4, i) * 12;
	Mat featureVector(featureVectorLength, 1, CV_32F);
	shared_ptr<float> Variance(new float);
	auto ind = 0;
	for (auto i = 1; i <= DEC_SCALE; i++)
	{		
		auto patch = partitionImage(image, i);
		for (auto &p : *patch)
		{
			auto transformedImage = hadamard(make_shared<Mat>(p), make_shared<Mat>((*HadMats)[i-1]));
			for (auto j = 3 * i - 3; j < 3 * i; j++)
			{
				fastNonZeroVariance(transformedImage, make_shared<vector<Point>>((*filters)[j]), Variance);
				featureVector.at<float>(ind++, 0) = *Variance;
			}
		}
	}
	
	return make_shared<Mat>(featureVector);
}