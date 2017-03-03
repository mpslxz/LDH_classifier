
#include <iostream>
#include "MLP.h"
#include <time.h>
#include <stdio.h>
#include <fstream>
#include "LDH.h"

using namespace std;


Mat test(int row, int col)
{
	return Mat(row, col, CV_32F);
}


int main_NN() {

	//help();

	//Mat features(252, 1090, CV_32F);
	//cout << "reading features..." << endl;
	string path = "C:\\Users\\Admin\\Desktop\\LDH\\LDH";
	//dataReader(features, Size(1090,252), path + "\\training_samples\\training_set.txt");
	
	//Mat targets(2, 1090, CV_32F);
	//cout << "reading targets..." << endl;
	//dataReader(targets, Size(1090, 2), path + "\\training_samples\\Training targets.txt");
	
	//cout << "Loading the network..." << endl;
	CvANN_MLP net;// = createNet();
	readNet(net, path + "\\_xml\\LDHtrainedNetwork.xml");
	auto img = imread(path + "\\data\\lamina.jpg", 0);

	auto Hadamards = initializeHadamardMatrices(path + "\\data");
	auto filters = initializeWedgeFilters(path + "\\data");
	auto features = LDHfeatures(make_shared<Mat>(img), Hadamards, filters, 256, 3);

	//
	//Mat sample(252, 1, CV_32F);
	//cout << "reading sample..." << endl;
	//dataReader(sample, Size(1, 252), "sample5.txt");
	////randu(sample, Scalar::all(0), Scalar::all(1));
	//transpose(features, features);
	//transpose(targets, targets);
	//
	transpose(*features, *features);
	////	
	cout << predict(net, *features) << endl;
	//trainNet(net, features, targets);
	//saveNet(net, path + "");
	
	return 0;
}