#include "LDH.h"

shared_ptr<std::vector<cv::Point>> loadFilter(const string path)
{
	try
	{
		std::ifstream reader(path);
		int size = 0;
		reader >> size;
		vector<Point> nonZeros; Point P;
		for (auto i = 0; i < size; i++)
		{
			reader >> P.y >> P.x;
			nonZeros.push_back(P);
		}
		return make_shared<vector<Point>>(nonZeros);
	}
	catch (exception &E){
		cerr << "Error in loadFilter()..." << endl;
	}

}