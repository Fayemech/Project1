#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include <math.h>
#include <fstream>

using namespace cv;
using namespace std;

int main()
{
	IplImage * src = cvLoadImage("threshold02.png");
	
	int a = 400;
	int i, x0, y0,xx;
	
	//Mat dis(180, 1, CV_32FC1);
	//vector<double> dis(180);
	ofstream outdata("data.txt");	
	for (xx = src->width-400; xx > 0; xx--){
		for (i = 1; i <= 180; i++) {

			double i1 = i * 3.1415926 / 180;
			double x1, y1, x2, y2;
			x1 = xx + cos(i1)*a;
			x2 = xx - cos(i1)*a;
			y1 = 364 + sin(i1)*a;
			y2 = 364 - sin(i1)*a;
			Point p1((263 + cos(i1)*a), (364 + sin(i1)*a));
			Point p2((263 - cos(i1)*a), (364 - sin(i1)*a));

			//line(src, p1, p2, Scalar(255, 0, 0));

			//s = tan(i1);

			for (x0 = 0; x0 < src->width; ++x0) {

				for (y0 = 0; y0 < src->height; ++y0) {

					CvScalar s;
					s = cvGet2D(src, y0, x0);
					if (s.val[0] == 255) {

						d = pow(((y2 - y1)*x0 - (x2 - x1)*y0 + x2 * y1 - y2 * x1), 2) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
						d0 = d0 + d;
					}
				}
			}
			dis[i - 1] = d0;


			d0 = 0;


			outdata << i << "\t" << dis[i - 1] << "\n";
			//data.seekg(0, ios::end);
		}
	
     }
	
	//cvShowImage("test", src);
	//waitKey(0);
	//cin.get();


	return 0;

}