#include "LDH.h"

void makeTrainingData(const std::string path)
{
	auto Hadamards = initializeHadamardMatrices(path + "\\data");
	auto filters = initializeWedgeFilters(path + "\\data");
	ofstream fout(path + "\\training_samples\\training_set.txt");
	Mat inputs = Mat::zeros(252,1,CV_32F);

	cout << "Extracting features from positive samples" << endl;
	for (auto i = 1; i <= 545; i++)
	{
		auto img = imread(path + "\\training_samples\\positive\\img_" + to_string(i) + ".jpg", 0);
		auto features = LDHfeatures(make_shared<Mat>(img), Hadamards, filters, 256, 3);
		hconcat(*features, inputs, inputs);
	}
	cout << "Extracting features from negative samples" << endl;
	for (auto i = 1; i <= 545; i++)
	{
		auto img = imread(path + "\\training_samples\\negative\\IMG_" + to_string(i) + ".jpg", 0);
		auto features = LDHfeatures(make_shared<Mat>(img), Hadamards, filters, 256, 3);
		hconcat(*features, inputs, inputs);
	}
	cout << "Writing the training set to file" << endl;
	for (auto i = 0; i < inputs.rows; i++)
	{
		for (auto j = 1; j < inputs.cols; j++)
		{
			fout << inputs.at<float>(i, j) << " ";
		}
		fout << endl;
	}
	fout.close();
}