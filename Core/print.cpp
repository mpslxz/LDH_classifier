#include "LDH.h"

void print(Mat b)
{
	for (size_t i = 0; i < b.rows; i++)
	{
		for (size_t j = 0; j < b.cols; j++)
		{
			cout << b.at<float>(i, j) << " ";
		}
		cout << endl;
	}
}