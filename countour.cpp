#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include <math.h>
#include <fstream>

using namespace cv;
using namespace std;

int main() {
	int theta;
	
	vector<double>x0, y0, x1, y1;
	IplImage * src = cvLoadImage("threshold02.png");
	theta = 78;
	double theta1 = theta * 3.1415926 / 180;
	double s = tan(theta1);
	int x, b, y;
	for (b = 1; b < 300; b++) {
		typedef vector<pair<int, int> > vpoint;
		vpoint poi;
		for (x = b; x < 550; x++) {
			y = s * (x - b);
			if (y < src->width&&y < src->height) {
				CvScalar p;
				p = cvGet2D(src, x, y);
				if (p.val[0] == 255) {
					poi.push_back(vpoint::value_type(x, y));

				}
			}
			//x0.push_back(poi[1].first);
			//y0.push_back(poi[1].second);
			//int l = poi.size();
			//cout << "l" << x << endl;
			//x1.push_back(poi[l - 1].first);
			//y1.push_back(poi[l - 1].second);
		}
		//for (int i1 = 1; i1 < x0.size(); i1++) {
		//	Point(x0[i1], y0[i1]);
		//}
		//for (int i2 = 1; i2 < x1.size(); i2++) {
		//	Point(x1[i2], y1[i2]);
		//}



	}

	return 0;
}