#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include <math.h>
#include <fstream>

using namespace cv;
using namespace std;

int main()
{
	vector<int> poi;
	int a;
	for (a = 1; a < 10; a++) {
		poi.push_back(a);
	}
	for (int b = 1; b < 10; b++) {
		cout << b << poi[b-1] << endl;
	}
	cin.get();
	return 0;
}
