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
	//��ʾԭʼͼ��
	cvNamedWindow("img_src", CV_WINDOW_AUTOSIZE);
	cvShowImage("img_src", img_src);

	IplImage* img_dst = cvCreateImage(cvGetSize(img_src), IPL_DEPTH_8U, 1);
	cvSet(img_dst, cvScalar(0));
	//------------������ֵͼ�е�������������������ɾ�����С��ĳ����ֵminarea������-------------//
	CvScalar color = cvScalar(255);//CV_RGB(128,0,0);
	CvContourScanner scanner = NULL;
	//��ʼ������ɨ����
	scanner = cvStartFindContours(img_src, storage, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));
	//��ʼ����������
	while (contour = cvFindNextContour(scanner))
	{
		//tmparea = ;
		if (fabs(cvContourArea(contour))>tmparea)
		{
			tmp = contour;
			tmparea = cvContourArea(contour);
			//cvSubstituteContour(scanner,NULL);//ɾ����ǰ������
		}
	}

	//���������������������������ĸ��ڵ�
	//contour = cvEndFindContours(&scanner);

	//���ƾ���ɾ��������ͼ����ʣ�µ�����
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
