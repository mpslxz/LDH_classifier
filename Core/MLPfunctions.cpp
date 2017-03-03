#include "MLP.h"
#include <fstream>

#define FEATURES 252
#define HIDDEN 45
#define CLASSES	2
#define SAMPLES 1090

CvANN_MLP createNet()
{
	Mat layers(3, 1, CV_32S);
	layers.at<int>(0, 0) = FEATURES;
	layers.at<int>(1, 0) = HIDDEN;
	layers.at<int>(2, 0) = CLASSES;
	return CvANN_MLP(layers, CvANN_MLP::SIGMOID_SYM, 0.6, 1);
}

void trainNet(CvANN_MLP &net, Mat trainingSet, Mat target)
{
	auto epsilon = 1.0e-6;
	CvANN_MLP_TrainParams params(TermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, 1000, epsilon), CvANN_MLP_TrainParams::BACKPROP, 0.1, 0.1);
	cout << "Training..." << endl;
	auto iteration = net.train(trainingSet, target, Mat(), Mat());
	cout << iteration << endl;
	//cerr << "Error in Training. Check the trainNet() function." << endl;
}

void saveNet(CvANN_MLP net, string path)
{
	path += "trainedNetwork.xml";
	cv::FileStorage storage(path.c_str(), FileStorage::WRITE);
	net.write(*storage, "Lamina");	
}

void readNet(CvANN_MLP& net, string path)
{
	net.load(path.c_str(), "Lamina");
}

bool predict(CvANN_MLP &net, Mat sample)
{
	Mat res;
	net.predict(sample, res);
	return (res.at<float>(0, 0) < res.at<float>(0, 1));
}

void dataReader(Mat &data, Size S, string path)
{
	std::ifstream fin(path);
	auto col = S.width;
	auto row = S.height;

	for (auto i = 0; i < row ; i++)
	{
		for (auto j = 0; j < col; j++)
		{
			float a;
			fin >>  a;
			data.at<float>(i, j) = a;
		}
	}

}

Mat makeFeatureVector(double* vec, int len)
{
	Mat res(1,len,CV_32F);
	for (size_t i = 0; i < len; i++)
	{
		res.at<float>(0, i) = vec[i];
	}
	return res;
}

void help()
{
	cout << "The code loads the network from trainedNetwork.xml file.\nUse dataReader() function to get the input from txt file OR "
		"makeFeatureVector()\nfunction if the input is a double*. The predict() function indicates the classification result." << endl;
}