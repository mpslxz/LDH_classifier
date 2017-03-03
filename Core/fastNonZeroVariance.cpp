#include "LDH.h"
#include <numeric>
#include <algorithm>
#include <functional>

void fastNonZeroVariance(const std::shared_ptr<cv::Mat> op, const std::shared_ptr<std::vector<cv::Point>> wedge, std::shared_ptr<float> var)
{
	try
	{
		vector<double> nonZeros;
		for (auto &p : *wedge)
			nonZeros.push_back(op->at<float>(p.x, p.y));
		double sum = std::accumulate(nonZeros.begin(), nonZeros.end(), 0);
		double mean = sum / nonZeros.size();
		double sumSQ = std::inner_product(nonZeros.begin(), nonZeros.end(), nonZeros.begin(), 0);
		double meanSQ = sumSQ / nonZeros.size();
		*var = (float)(meanSQ - mean*mean);
	}
	catch (exception &E)
	{
		cerr << "Error in fastNonZeroVariance()..." << endl;
	}
	
}