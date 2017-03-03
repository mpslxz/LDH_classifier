#include "LDH.h"

std::shared_ptr<Mat> loadTransMat(const string path, const int size)
{
	try
	{
		std::ifstream reader(path);
		Mat tran = Mat(size, size, CV_32F);
		int buf;
		for (auto i = 0; i < size*size; i++)
			reader >> tran.at<float>((int)i / size, i % size);
		reader.close();
		return(std::make_shared<Mat>(tran));
	}
	catch (exception &E)
	{
		cerr << "Error in loadTransMat()..." << endl;
	}
}