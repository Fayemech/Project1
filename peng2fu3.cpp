#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>  
#include <iostream>  


using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("06.png");
	namedWindow("image");
	namedWindow("after");
	imshow("image", image);
	Mat element = getStructuringElement(MORPH_RECT, Size(6, 6));
	Mat out;
	erode(image, out, element);
    dilate(out, out, element);
	erode(image, out, element);
	dilate(out, out, element);
	erode(image, out, element);
	imshow("after", out);
	waitKey(0);

	return 0;
}