#include "cv.h"
#include "cxcore.h"
#include "highgui.h"



void main()
{
	CvSeq* contour = NULL;
	CvSeq* tmp = NULL;
	double tmparea = 0.0;
	CvMemStorage* storage = cvCreateMemStorage(0);
	IplImage* img_src = cvLoadImage("1.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	//显示原始图像
	cvNamedWindow("img_src", CV_WINDOW_AUTOSIZE);
	cvShowImage("img_src", img_src);

	IplImage* img_dst = cvCreateImage(cvGetSize(img_src), IPL_DEPTH_8U, 1);
	cvSet(img_dst, cvScalar(0));
	//------------搜索二值图中的轮廓，并从轮廓树中删除面积小于某个阈值minarea的轮廓-------------//
	CvScalar color = cvScalar(255);//CV_RGB(128,0,0);
	CvContourScanner scanner = NULL;
	//初始化轮廓扫描器
	scanner = cvStartFindContours(img_src, storage, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));
	//开始遍历轮廓树
	while (contour = cvFindNextContour(scanner))
	{
		//tmparea = ;
		if (fabs(cvContourArea(contour))>tmparea)
		{
			tmp = contour;
			tmparea = cvContourArea(contour);
			//cvSubstituteContour(scanner,NULL);//删除当前的轮廓
		}
	}

	//结束轮廓搜索，并返回轮廓树的根节点
	//contour = cvEndFindContours(&scanner);

	//绘制经过删除操作后图像中剩下的轮廓
	//cvZero(img_dst);
	cvDrawContours(img_dst, tmp, color, color, 0, CV_FILLED, 8, cvPoint(0, 0));

	cvNamedWindow("dst_contour", CV_WINDOW_AUTOSIZE);
	cvShowImage("dst_contour", img_dst);
	cvSaveImage("dst_contour.jpg", img_dst);
	cvWaitKey(0);

	cvReleaseMemStorage(&storage);
	cvReleaseImage(&img_src);
	cvReleaseImage(&img_dst);

	cvDestroyAllWindows();
}
