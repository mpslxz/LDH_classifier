#include <iostream>
#include "Beamlet.h"
#include <time.h>
#include <stdio.h>

using namespace std;

int main_BT() {
	
	    clock_t t;
		for (int j = 1; j <= 575; j++)
		{ 
		
			string path = "C:\\Users\\Admin\\Desktop\\Ultrasound\\lamina\\img_" + to_string(j) + ".jpg";

			Mat img = imread(path, 0);
			int M = 256;
			resize(img, img, Size(M, M));
			//namedWindow("test", CV_WINDOW_AUTOSIZE);
			//namedWindow("orig", CV_WINDOW_AUTOSIZE);
			t = clock();


			vector<Mat> subImg = partition(img, 2);
			vector<Mat> beams;
			vector<Point> LFs;

			for (int i = 0; i < subImg.size(); i++){
				Point base;
				beams.push_back(Beamlet(subImg[i], subImg[i].rows, base));
				if (base.x != base.y &&  base.y > 0){
					Point LF(M / 4 * (ceil(i / 4)) + 1 + base.x, M / 4 * (i % 4) + base.y);

					LFs.push_back(LF);
				}
			}
			Mat out = merge(beams);
			t = clock() - t;

			cout << "Total run time for IMG " << j<< " : " << (float)t / CLOCKS_PER_SEC << endl;
			//resize(out,out,Size(4*M,4*M));
			//resize(img,img,Size(4*M,4*M));
			//    int a = subImg.size();
			//    for(int i=0 ; i<a;i++)
			//    {
			//        imshow("orig",subImg[i]);
			//        out = Beamlet(subImg[i],subImg[i].rows);
			//        imshow("test",out);
			//        
			//        waitKey(0);
			//    }

			//    Mat smp = merge(subImg);

			//imshow("orig", img);
			//Mat smp;
			//resize(out, smp, Size(484, 364));
			//imwrite("output3.jpg",255-smp);
			out = out + img;
			for (auto i = 0; i < LFs.size(); i++)
			{
				if (dist(LFs[i],Point(128,128)) < 64)
					circle(out, LFs[i], 5, Scalar(255, 255, 255));
			}
			resize(out, out, Size(484, 364));

			//imshow("test", out);
			string path2 = "C:\\Users\\Admin\\Desktop\\Ultrasound\\lamina\\segmented\\img_" + to_string(j) + ".jpg";
			imwrite(path2, out);
			waitKey(3);
		}
    
    return 0;
}

