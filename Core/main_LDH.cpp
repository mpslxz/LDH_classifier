#include "/home/mehran/git/LDH_classifier/include/LDH.h"
#include <time.h>

int main()
{
  string path = "/home/mehran/git/LDH_classifier/data/";
  /*	makeTrainingData(path);
	return 0;*/
        auto img = imread(path + "lamina.jpg", 0);
		
	auto Hadamards = initializeHadamardMatrices(path);
	auto filters = initializeWedgeFilters(path);

	clock_t t;
	t = clock();
	auto features = LDHfeatures(make_shared<Mat>(img), Hadamards, filters, 256, 3);	
	t = clock() - t;
	
	cout << "Total run time : " << (float)t / CLOCKS_PER_SEC << endl;
	
}
