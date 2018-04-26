#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include <math.h>
#include <fstream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("threshold01.png");

	int a = 300;
	int i, x0, y0;
	double d;
	double d0 = 0;
	//Mat dis(180, 1, CV_32FC1);
	//vector<double> dis(180);
	//ofstream outdata("data");
	    i =174;
		double i1 = i * 3.14 / 180;
		double x1, y1, x2, y2;
		x1 = 263 + cos(i1)*a;
		x2 = 263 - cos(i1)*a;
		y1 = 364 + sin(i1)*a;
		y2 = 364 - sin(i1)*a;
		Point p1((263 + cos(i1)*a), (364 + sin(i1)*a));
		Point p2((263 - cos(i1)*a), (364 - sin(i1)*a));

		line(src, p1, p2, Scalar(255, 0, 0));

		
	imshow("test", src);

	//cvShowImage("test", src);
	waitKey(0);
	//cin.get();


	return 0;

}