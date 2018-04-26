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
	//ת��Ϊ��ֵͼ    
	Mat binaryImage;
	threshold(grayImage, binaryImage, 90, 255, CV_THRESH_BINARY);

	//��ֵͼ ������������ط�ת����Ϊһ��������255��ɫ��ʾǰ�������壩����0��ɫ��ʾ����    
	Mat reverseBinaryImage;
	bitwise_not(binaryImage, reverseBinaryImage);

	vector <vector<Point>>contours;
	findContours(reverseBinaryImage,
		contours,   //����������  
		CV_RETR_EXTERNAL,   //��ȡ������  
		CV_CHAIN_APPROX_NONE);  //��ȡÿ��������ÿ������  
								//�ڰ�ɫͼ���ϻ��ƺ�ɫ����  
	Mat result(reverseBinaryImage.size(), CV_8U, Scalar(255));
	drawContours(result, contours,
		-1, //������������  
		Scalar(0),  //��ɫΪ��ɫ  
		2); //�����ߵĻ��ƿ��Ϊ2  

	namedWindow("contours");
	imshow("contours", result);

	//�Ƴ���������̵�����  
	int cmin = 100; //��С��������  
	int cmax = 1000;    //�������  
	vector<vector<Point>>::const_iterator itc = contours.begin();
	while (itc != contours.end())
	{
		if (itc->size() < cmin || itc->size() > cmax)
			itc = contours.erase(itc);
		else
			++itc;
	}

	//�ڰ�ɫͼ���ϻ��ƺ�ɫ����  
	Mat result_erase(binaryImage.size(), CV_8U, Scalar(255));
	drawContours(result_erase, contours,
		-1, //������������  
		Scalar(0),  //��ɫΪ��ɫ  
		2); //�����ߵĻ��ƿ��Ϊ2  

	namedWindow("contours_erase",CV_WINDOW_NORMAL);
	imshow("contours_erase", result_erase);
	waitKey(0);
	return 0;
}