#include "LDH.h"

std::shared_ptr<vector<cv::Mat>> partitionImage(const std::shared_ptr<cv::Mat> img, const int scale)
{
	vector<Mat> partitionedImg;
	Size S(img->rows, img->cols);
	int stepSize = img->rows / pow((double)2, (double)scale) - 1;
	for (auto i = 0; i<S.height; i = i + 1 + stepSize)
	{
		for (auto j = 0; j<S.width; j = j + 1 + stepSize)
		{
			auto subImg = (*img)(Rect(Point(j, i), Size(stepSize + 1, stepSize + 1)));
			auto k = subImg.rows;
			partitionedImg.push_back(subImg);
		}
	}
	return (make_shared<vector<Mat>>(partitionedImg));
}