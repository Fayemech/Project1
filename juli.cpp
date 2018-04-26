#include "core/core.hpp"    
#include "highgui/highgui.hpp"    
#include "imgproc/imgproc.hpp"    
#include "iostream"  

using namespace std;
using namespace cv;

int main()
{
	IplImage * src;
	src = cvLoadImage("12.jpg");
	IplImage * dst = cvCreateImage(cvGetSize(src), 8, 1);
	IplImage * color_dst = cvCreateImage(cvGetSize(src), 8, 3);
	CvMemStorage *storage = cvCreateMemStorage(0);
	CvSeq* lines = 0;
	int i;
	IplImage * src1 = cvCreateImage(CvSize(src->width, src->height), IPL_DEPTH_8U, 1);
	cvCvtColor(src, src1, CV_BGR2GRAY);
	cvCanny(src1, dst, 50, 200, 3);
	cvCvtColor(dst, color_dst, CV_GRAY2BGR);
	lines = cvHoughLines2(dst, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI / 180, 80, 30, 10);
	for (i = 0; i < lines->total; i++) {
		CvPoint* line = (CvPoint*)cvGetSeqElem(lines, i);
		cvLine(color_dst, line[0], line[1], CV_RGB(255, 255, 0), 3, 8);
		double k = (double)(line[1].y - line[0].y) / (double)(line[1].x - line[0].x);
		double d = line[0].y - line[0].x*k;
		printf("This is the %d line, this line is y = %.2f x + %.2f \n", i + 1, k, d);
	}
	cvNamedWindow("Source", CV_WINDOW_NORMAL);
	cvShowImage("Source", src);
	cvNamedWindow("Hough", CV_WINDOW_NORMAL);
	cvShowImage("Hough", color_dst);
	cvWaitKey(0);


	return 0;
}






