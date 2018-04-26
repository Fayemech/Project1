#include<iostream>    
#include <opencv2/core/core.hpp>      
#include <opencv2/highgui/highgui.hpp>   
#include<imgproc/imgproc.hpp>    

using namespace std;
using namespace cv;

int main() {

	Mat image = imread("04.jpg");
	Mat grayImage;
	cvtColor(image, grayImage, CV_BGR2GRAY);
	//转换为二值图    
	Mat binaryImage;
	threshold(grayImage, binaryImage, 90, 255, CV_THRESH_BINARY);

	//二值图 这里进行了像素反转，因为一般我们用255白色表示前景（物体），用0黑色表示背景    
	Mat reverseBinaryImage;
	bitwise_not(binaryImage, reverseBinaryImage);

	vector <vector<Point>>contours;
	findContours(reverseBinaryImage,
		contours,   //轮廓的数组  
		CV_RETR_EXTERNAL,   //获取外轮廓  
		CV_CHAIN_APPROX_NONE);  //获取每个轮廓的每个像素  
								//在白色图像上绘制黑色轮廓  
	Mat result(reverseBinaryImage.size(), CV_8U, Scalar(255));
	drawContours(result, contours,
		-1, //绘制所有轮廓  
		Scalar(0),  //颜色为黑色  
		2); //轮廓线的绘制宽度为2  

	namedWindow("contours");
	imshow("contours", result);

	//移除过长或过短的轮廓  
	int cmin = 100; //最小轮廓长度  
	int cmax = 1000;    //最大轮廓  
	vector<vector<Point>>::const_iterator itc = contours.begin();
	while (itc != contours.end())
	{
		if (itc->size() < cmin || itc->size() > cmax)
			itc = contours.erase(itc);
		else
			++itc;
	}

	//在白色图像上绘制黑色轮廓  
	Mat result_erase(binaryImage.size(), CV_8U, Scalar(255));
	drawContours(result_erase, contours,
		-1, //绘制所有轮廓  
		Scalar(0),  //颜色为黑色  
		2); //轮廓线的绘制宽度为2  

	namedWindow("contours_erase",CV_WINDOW_NORMAL);
	imshow("contours_erase", result_erase);
	waitKey(0);
	return 0;
}