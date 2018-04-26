#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv/cv.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;
using namespace std;
Mat src;
Mat src_gray;
int thresh = 30;
int max_thresh = 255;

int main()
{
	src = imread( "C:\\Users\\Administrator\\source\\repos\\Project1\\Project1\\threshold01.png", CV_LOAD_IMAGE_COLOR);    //ע��·���û����Լ���  
	cvtColor(src, src_gray, CV_BGR2GRAY);//�ҶȻ�      
	GaussianBlur(src, src, Size(3, 3), 0.1, 0, BORDER_DEFAULT);
	blur(src_gray, src_gray, Size(3, 3)); //�˲�       
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", src);
	moveWindow("image", 20, 20);
	//����Canny��Ե���ͼ��       
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	//����canny�㷨����Ե       
	Canny(src_gray, canny_output, thresh, thresh * 3, 3);
	namedWindow("canny", CV_WINDOW_AUTOSIZE);
	imshow("canny", canny_output);
	moveWindow("canny", 550, 20);
	//��������    
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	//����������       
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}
	//��������������     
	vector<Point2f> mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2d(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}
	//�������������Ĳ���ʾ      
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(255, 0, 0);
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 5, Scalar(0, 0, 255), -1, 8, 0);
		rectangle(drawing, boundingRect(contours.at(i)), cvScalar(0, 255, 0));
		char tam[100];
		sprintf_s(tam, "(%0.0f,%0.0f)", mc[i].x, mc[i].y);
		putText(drawing, tam, Point(mc[i].x, mc[i].y), FONT_HERSHEY_SIMPLEX, 0.4, cvScalar(255, 0, 255), 1);
	}
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);
	moveWindow("Contours", 1100, 20);
	waitKey(0);
	src.release();
	src_gray.release();
	return 0;
}