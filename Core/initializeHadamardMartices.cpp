#include "LDH.h"

std::shared_ptr<vector<cv::Mat>> initializeHadamardMatrices(const std::string path)
{
	
	auto _128 = loadTransMat(path + "\\HM_128.bin", 128);
	auto _64 =	loadTransMat(path + "\\HM_64.bin",	64);
	auto _32 =	loadTransMat(path + "\\HM_32.bin",	32);

	vector<Mat> mats;
	mats.push_back(*_128);
	mats.push_back(*_64);
	mats.push_back(*_32);
	return make_shared<vector<Mat>>(mats);

}