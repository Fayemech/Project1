#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include <math.h>
#include <fstream>

using namespace cv;
using namespace std;

int main()
{
	IplImage *src = cvLoadImage("threshold02.png");
	// w 854,h 628
	ofstream outdata("test.txt");
	for (int theta = 1; theta < 46; theta++) {

		int theta1 = 90 - theta;
		double theta2 = theta1 * 3.141592653 / 180;
		double s = tan(theta2);
		for (int b = -100; b < 300; b++) {

			for (double y = b; y < 300; y++) {
				double x;
				x = (y - b)*s;
				CvScalar p;

			
			}
		}
	}

}