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
	vector<double>dis(90);
	//vector <int> n;
	//point points;
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
		for (b = 1; b < 300; b++) {
			typedef vector<pair<int, int> > vpoint;
			vpoint poi;
			for (x = b; x < 550; x++) {
				y = s * (x - b);
				if (y < src->height&&x< src->width) {
					CvScalar p;
					p = cvGet2D(src, x, y);
					if (p.val[0] == 255) {
						poi.push_back(vpoint::value_type(x, y));

					}
				}
			}
			x0 = poi[1].first;
			y0 = poi[1].second;
			int l = poi.size();
			//cout << "l" << x << endl;
			x1 = poi[l - 1].first;
			y1 = poi[l - 1].second;
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