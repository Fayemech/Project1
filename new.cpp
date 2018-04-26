#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include <math.h>
#include <fstream>

using namespace cv;
using namespace std;
//struct point{
//	int i, j;
//};
int main() {
	int theta;
	vector<double> dis(180);
	//vector <int> n;
	//point points;
	int x0, x1, y0, y1;
	double d0 = 0;
	int x, b, y;
	double theta1, theta2, s;
	vector<double> poix;
	vector<double> poiy;
	IplImage * src = cvLoadImage("threshold02.png");
	// w 854,h 628
	ofstream outdata("test.txt");
	for (theta = 1; theta < 46; theta++) {
		theta1 = 90 - theta;
		theta2 = theta1 * 3.1415926 / 180;
		s = tan(theta2);
		//x/y=s, x=s*y, 
		for (b = -100; b < 300; b++) {
			
			for (y = b; y < 200; y++) {
				x = (y - b)*s;
				if (x < src->width && y < src->height && x > 0 && y > 0) {
					CvScalar p;
					p = cvGet2D(src, y, x);
					if (p.val[0] == 255) {
						
						poix.push_back(x);
						poiy.push_back(y);
					
					}
				
				}
			
			}
			x0 = poix[0];
			y0 = poiy[0];
			int l = poix.size();
			cout << "l" << x << endl;
			x1 = poix[l - 1];
			y1 = poiy[l - 1];
			double d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
				
		}
		dis[theta - 1] = d0;
		d0 = 0;
		outdata << theta << "\t" << dis[theta - 1] << "\n";

	}

	return 0;
}