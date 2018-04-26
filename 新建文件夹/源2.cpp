#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	IplImage *img = cvLoadImage("lena.png", 0);
	IplImage* img_temp = cvCreateImage(cvGetSize(img), 8, 1);
	cvThreshold(img, img, 128, 255, CV_THRESH_BINARY);
	CvMemStorage* mem_storage = cvCreateMemStorage(0);
	CvSeq *first_contour = NULL, *c = NULL;
	cvNamedWindow("contour1");
	cvCopy(img, img_temp);
	double t = (double)cvGetTickCount();
	cvFindContours(img_temp, mem_storage, &first_contour);
	cvZero(img_temp);
	cvDrawContours(
		img_temp,
		first_contour,
		cvScalar(100),
		cvScalar(100),
		1
	);
	t = (double)cvGetTickCount() - t;
	cvShowImage("contour1", img_temp);

	printf("run1 = %gms\n", t / (cvGetTickFrequency()*1000.));

	cvClearMemStorage(mem_storage);
	cvWaitKey(0);
}
	//////////////////////////////////////////////////////////////////////////    
	// 