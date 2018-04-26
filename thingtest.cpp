#include "core/core.hpp"    
#include "highgui/highgui.hpp"    
#include "imgproc/imgproc.hpp"    
#include "iostream"  

using namespace std;
using namespace cv;






int Findn(IplImage* img, int i, int j)
{
	CvScalar s1 = cvGet2D(img, i, j);
	CvScalar s2 = cvGet2D(img, i - 1, j);
	CvScalar s3 = cvGet2D(img, i - 1, j + 1);
	CvScalar s4 = cvGet2D(img, i, j + 1);
	CvScalar s5 = cvGet2D(img, i + 1, j + 1);
	CvScalar s6 = cvGet2D(img, i + 1, j);
	CvScalar s7 = cvGet2D(img, i + 1, j - 1);
	CvScalar s8 = cvGet2D(img, i, j - 1);
	CvScalar s9 = cvGet2D(img, i - 1, j - 1);
	int a = s1.val[0];
	int b = s2.val[0];
	int c = s3.val[0];
	int d = s4.val[0];
	int e = s5.val[0];
	int f = s6.val[0];
	int g = s7.val[0];
	int h = s8.val[0];
	int l = s9.val[0];
	int find[] = { a, b, c, d, e, f, g, h, l };//按8领域顺序定义数组，方便操作
	int n = 0;
	for (int x = 2; x < 9; ++x)
	{
		if (find[x] == 0 && find[x + 1] == 255)
		{
			n = n + 1;
		}
	}
	return n;
}



IplImage* ThinImage(IplImage* img, int k) //确保输入的是二值图像
{   
	int condition = 0;//满足的条件个数
	int mark = 0;//成功的标志位
	int firstN = 0;//第一个条件黑点的个数
	CvScalar s;
	for (int n = 0; n < k; ++n)
	{
		for (int i = 1; i < img->height - 1; ++i)
		{
			for (int j = 1; j < img->width - 1; ++j)
			{//开始过程1的寻找
				condition = 0;//初始化条件满足数
							  //cout << "1" << endl;
				s = cvGet2D(img, i, j);
				if (s.val[0] == 255)//如果这是前景点，即边缘
				{
					//cout << "2" << endl;
					//*************************第一过程****************************
					//*************************step1****************************
					firstN = 0;
					for (int ii = -1; ii < 1; ++ii)
					{
						for (int jj = -1; jj < 1; ++jj)
						{
							s = cvGet2D(img, i + ii, j + jj);
							if (s.val[0] == 255)
							{
								firstN = firstN + 1;
							}
						}
					}
					if (firstN < 3 || firstN > 7)
					{
						continue;
					}
					else
					{
						condition = condition + 1;
					}
					//****************************************************************
					//*************************step2*********************************
					if (Findn(img, i, j) != 1)
					{
						continue;
					}
					else
					{
						condition = condition + 1;
					}
					//****************************************************************
					//*************************step3*********************************
					CvScalar s1 = cvGet2D(img, i - 1, j);
					CvScalar s2 = cvGet2D(img, i, j + 1);
					CvScalar s3 = cvGet2D(img, i + 1, j);
					CvScalar s4 = cvGet2D(img, i, j - 1);
					int a = s1.val[0];//2
					int b = s2.val[0];//4
					int c = s3.val[0];//6
					int d = s4.val[0];//8
					if (a * b * c != 0)
					{
						continue;
					}
					else
					{
						condition = condition + 1;
					}
					//*********************************************************************
					//******************************step4**********************************
					if (b * c * d != 0)
					{
						continue;
					}
					else
					{
						condition = condition + 1;
					}
					//*********************************************************************
					//第一过程的结果操作
					if (condition == 4)
					{
						mark = 1;
						//((char *)(img->imageData + img->widthStep * (i)))[j] = 0;
						CvScalar p;
						p.val[0] = 0;
						cvSet2D(img, i, j, p);
						//cout << "11111111111111111111111111111111111" << endl;
					}
				}
			}
		}
		//****************************过程2**************************
		for (int i = 1; i < img->height - 1; ++i)
		{
			for (int j = 1; j < img->width - 1; ++j)
			{//开始过程1的寻找
				condition = 0;//初始化条件满足数
							  //cout << "1" << endl;
				s = cvGet2D(img, i, j);
				if (s.val[0] == 255)//如果这是前景点，即边缘
				{
					//cout << "2" << endl;
					//*************************第一过程****************************
					//*************************step1****************************
					firstN = 0;
					for (int ii = -1; ii < 1; ++ii)
					{
						for (int jj = -1; jj < 1; ++jj)
						{
							s = cvGet2D(img, i + ii, j + jj);
							if (s.val[0] == 255)
							{
								firstN = firstN + 1;
							}
						}
					}
					if (firstN < 3 || firstN > 7)
					{
						continue;
					}
					else
					{
						condition = condition + 1;
					}
					//****************************************************************
					//*************************step2*********************************
					if (Findn(img, i, j) != 1)
					{
						continue;
					}
					else
					{
						condition = condition + 1;
					}
					//****************************************************************
					//*************************step3*********************************
					CvScalar s1 = cvGet2D(img, i - 1, j);
					CvScalar s2 = cvGet2D(img, i, j + 1);
					CvScalar s3 = cvGet2D(img, i + 1, j);
					CvScalar s4 = cvGet2D(img, i, j - 1);
					int a = s1.val[0];//2
					int b = s2.val[0];//4
					int c = s3.val[0];//6
					int d = s4.val[0];//8
					if (a * b * d != 0)
					{
						continue;
					}
					else
					{
						condition = condition + 1;
					}
					//*********************************************************************
					//******************************step4**********************************
					if (a * c * d != 0)
					{
						continue;
					}
					else
					{
						condition = condition + 1;
					}
					//*********************************************************************
					//第一过程的结果操作
					if (condition == 4)
					{
						mark = 1;
						//((char *)(img->imageData + img->widthStep * (i)))[j] = 0;
						CvScalar p;
						p.val[0] = 0;
						cvSet2D(img, i, j, p);
						//cout << "222222222222222222222222" << endl;
					}
				}
			}
		}
		//cout << " end " << endl;
	}
	return img;
}


int main()
{
	IplImage * src = cvLoadImage("11.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	if (!src)
	{
		std::cout << "read file failed!";
		return -1;
	}
	namedWindow("pre", CV_WINDOW_NORMAL);
	cvShowImage("pre", src);
	IplImage *pTemp = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	cvThreshold(src, pTemp, 128, 1, CV_THRESH_BINARY_INV);
	ThinImage(pTemp, 5);
	namedWindow("after", CV_WINDOW_NORMAL);
	cvShowImage("after", ThinImage);

	return 0;
}