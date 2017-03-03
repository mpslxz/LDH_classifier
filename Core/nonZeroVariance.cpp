#include "LDH.h"
#include <numeric>
#include <algorithm>
#include <functional>

void nonZeroVariance(const std::shared_ptr<Mat> op, std::shared_ptr<float> var)
{
	try
	{
		Mat nonZeroCoordinates;
		vector<double> nonZeros;
		Mat buff = *op;
		buff.convertTo(buff, CV_8UC1);
		print(*op);
		findNonZero(buff, nonZeroCoordinates);
		for (auto i = 0; i < nonZeroCoordinates.total(); i++)
			nonZeros.push_back(op->at<float>(nonZeroCoordinates.at<Point>(i).x, nonZeroCoordinates.at<Point>(i).y));
		double sum = std::accumulate(nonZeros.begin(), nonZeros.end(), 0);
		double mean = sum / nonZeros.size();
		double sumSQ = std::inner_product(nonZeros.begin(), nonZeros.end(), nonZeros.begin(), 0);
		double meanSQ = sumSQ / nonZeros.size();
		*var = (float)(meanSQ - mean*mean);
	}
	catch (exception &E){
		cerr << "Error in nonZeroVariance()..." << endl;
	}
	
}