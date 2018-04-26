#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include <math.h>
#include <fstream>

using namespace cv;
using namespace std;

int main() {
	int theta;
	typedef vector<pair<int, int> > vpoint;
	vpoint poi;
	vector<double>dis(90);
	int x0, x1, y0, y1;
	double d0 = 0;
	int x, b, y;
	double theta1, s;
	IplImage * src = cvLoadImage("threshold02.png");
	// w 854,h 628
	ofstream outdata("test.txt");
	for (theta = 1; theta < 90; theta++) {
		 theta1 = theta * 3.1415926 / 180;
		 s = tan(theta1);
		for (b = 0; b < 300; ++b) {
			for (x = 0; x < 300; ++x) {
				y = s * (x - b);
				CvScalar p;
				p = cvGet2D(src, y, x);
				if (p.val[0] == 255) {
					poi.push_back(vpoint::value_type(x, y));
				}
			}
			x0 = poi[0].first;
			y0 = poi[0].second;
			int n = poi.size();
			x1 = poi[n].first;
			y1 = poi[n].second;
			double d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
		}
		dis[theta - 1] = d0;
		outdata << theta << "\t" << dis[theta - 1] << "\n";
		d0 = 0;
	}
	
	//cvShowImage("test", src);
	//waitKey(0);
	return 0;
}