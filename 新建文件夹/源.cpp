#include<opencv2\opencv.hpp> 
#include <iostream>  
#include <opencv2\highgui\highgui.hpp>  
#include <opencv2\core\core.hpp>  
#include <opencv2\imgproc\imgproc.hpp>  

using namespace std;
using namespace cv;

int main()
{
	Mat img, res, res1,res2;
	
	
	string imgpath = "03.jpg";  
	

	img = imread(imgpath, 1);
	int spatialRad = 10;  //空间窗口大小  
	int colorRad = 10;   //色彩窗口大小  
	int maxPyrLevel = 2;  //金字塔层数  
	pyrMeanShiftFiltering(img, res, spatialRad, colorRad, maxPyrLevel);
    cvtColor(res, res1, COLOR_BGR2GRAY);
	//threshold(res1, res2, 55,255, CV_THRESH_BINARY);;
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;
	Sobel(res1, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT );
	convertScaleAbs(grad_x, abs_grad_x);
	Sobel(res1, grad_y, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT );
	convertScaleAbs(grad_y, abs_grad_y);
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
	
	
	
	
	// 检测线条
	vector<Vec2f> lines;//定义一个矢量结构lines用于存放得到的线段矢量集合  
	HoughLines(dst, lines, 1, CV_PI / 180, 150, 0, 0);
	// draw line in pic
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(res1, pt1, pt2, Scalar(55, 100, 195), 1, CV_AA);
	}
	imshow("soble", res1);
		//result = img.clone );
		//threshold(img, result, 30, 200.0, CV_THRESH_BINARY);
		//namedWindow("二值化图像");
		//imshow("二值化图像", result);
		
		//RNG rng = theRNG();
		//Mat mask(res.rows + 2, res.cols + 2, CV_8UC1, Scalar::all(0));  //掩模  
		//for (int y = 0; y < res.rows; y++)
		//{
		//	for (int x = 0; x < res.cols; x++)
		//	{
		//		if (mask.at<uchar>(y + 1, x + 1) == 0)  //非0处即为1，表示已经经过填充，不再处理  
		//		{
		//			Scalar newVal(rng(256), rng(256), rng(256));
		//	floodFill(res, mask, Point(x, y), newVal, 0, Scalar::all(5), Scalar::all(5)); //执行漫水填充  
		//}
		//
		//
		//show("meanShift图像分割", res);
		//imshow("soble", dst);
		imshow("res", res);
		
	waitKey(0);
	return 0;
}					