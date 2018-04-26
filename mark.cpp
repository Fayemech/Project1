#include <iostream>
#include <opencv\cv.h>
#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	Mat src;
	Mat midimg, secimg, gray, blur, thiimg,furimg,fifimg;
	src = imread("04.jpg");
	cvtColor(src, gray, CV_BGR2GRAY);
	GaussianBlur(gray, blur,Size(9,9),5,5);
	Mat gradx, grady, absgradx, absgrady;
	Sobel(blur, gradx, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	Sobel(blur, grady, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(gradx, absgradx);
	convertScaleAbs(grady, absgrady);
	addWeighted(absgradx, 5, absgrady, 2, 0, midimg);
	GaussianBlur(midimg, secimg, Size(9, 9), 5, 5);
	threshold(secimg, thiimg, 60, 255, CV_THRESH_BINARY);
	Mat elementRect;
	elementRect = getStructuringElement(MORPH_RECT, Size(10, 10));
	morphologyEx(thiimg, furimg, MORPH_OPEN, elementRect);
	vector<Vec4i> hierarchy;
	vector<vector<Point>> contours;
	Mat contoursImg = src.clone();
	findContours(furimg, contours, hierarchy, CV_RETR_EXTERNAL, CHAIN_APPROX_NONE);
	double maxarea = 0;
	int maxAreaIdx = 0;
	for (int index = contours.size() - 1; index >= 0; index--)
	{
		double tmparea = fabs(contourArea(contours[index]));
		if (tmparea>maxarea)
		{
			maxarea = tmparea;
			maxAreaIdx = index;//记录最大轮廓的索引号  
		}
	}
	Rect r = boundingRect(Mat(contours[maxAreaIdx]));
	rectangle(contoursImg, r, Scalar(255), 2);

	















#if 0
    RNG rng(12345);
	for (int i = 0; i<contours.size(); i++) {
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), 255);
		drawContours(contoursImg, contours, i, color, 2, 8, hierarchy);
	}
#endif // 0

	
	
#if 0
    Mat abssobelx, abssobely;
	convertScaleAbs(gradx, abssobelx);
	convertScaleAbs(grady, abssobely);
	addWeighted(abssobelx, 5, abssobely, 5, 0, midimg);
#endif // 2

	
	namedWindow("mid", WINDOW_NORMAL);
	imshow("mid", secimg);
	
	namedWindow("display", WINDOW_NORMAL);
	imshow("display", contoursImg);
	waitKey(0);

	return 0;

}