#include "LDH.h"
#include <time.h>

void main_LDH()
{
	string path = "C:\\Users\\Admin\\Desktop\\LDH\\LDH";
	makeTrainingData(path);
	/*auto img = imread(path + "\\lamina.jpg", 0);
		
	auto Hadamards = initializeHadamardMatrices(path);
	auto filters = initializeWedgeFilters(path);

	clock_t t;
	t = clock();
	auto features = LDHfeatures(make_shared<Mat>(img), Hadamards, filters, 256, 3);	
	t = clock() - t;
	
	cout << "Total run time : " << (float)t / CLOCKS_PER_SEC << endl;*/
	
}