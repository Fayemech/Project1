#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>  
#include <iostream>  

using namespace std;
using namespace cv;

int main()
{
	IplImage * src = cvLoadImage("threshold02.png");
	vector<int> dis;
	for (int theta = 1; theta < 45; theta++) {
		int theta1 = 90 - theta;
		double theta2 = theta1 * 3.141592653 / 180;
		double s = tan(theta2);
		int ylocal = 853 / s;
		vector<int> X ;
		vector<int> Y ;
		vector<int> Y1 ;
		
		int d0;
		for (int y = 1; y < ylocal; y++) {
			int x = s * y;
			X[y] = x;
			Y[y] = y;
		}
		for (int b = 1; b < 628; b++) {
			for (int i = 1; i < ylocal; i++) {
				Y1[i] = Y[i] + b;
			}
			//Y1 = Y + B; 
			vector<int> X1; vector<int> Y2;
			for (int i = 4; i < sizeof(Y1); i++) {
				if (Y1[i] > 628)
				{
					break;
				}
				else
				{
					CvScalar p = cvGet2D(src, Y1[i], X[i]);
					if (p.val[0] == 255) {
						
						X1.push_back(X[i]);
						
						Y2.push_back(Y1[i]);
					}
				}
			}
			int x0 = X1[1];
			int y0 = Y2[1];
			int sz = sizeof(X1);
			int x1 = X1[sz-1];
			int y1 = Y2[sz-1];
			int d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
		}
		for (int b1 = 0; b1 > -ylocal; b1--) {
			for (int i = 1; i < ylocal; i++) {
				Y1[i] = Y[i] + b1;
			}
			//Y1 = Y + b1; 
			vector<int> X1; vector<int> Y2;
			for (int i = sizeof(X); i > 4; i--) {
				if (Y1[i] < 0 || Y1[i]>628) 
				{
					break;
				}
				else 
				{
					CvScalar p = cvGet2D(src, Y1[i], X[i]);
					if (p.val[0] == 255) {
						X1.push_back(X[i]);

						Y2.push_back(Y1[i]);
					}
				}
			}
			int x0 = X1[1];
			int y0 = Y2[1];
			int sz = sizeof(X1);
			int x1 = X1[sz-1];
			int y1 = Y2[sz-1];
			int d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
		}
		dis.push_back(d0);
		d0 = 0;
	}



	for (int theta = 46; theta < 90; theta++) {
		double theta1 = theta * 3.141592653 / 180;
		double s = tan(theta1);
		int xlocal = 628 / s;
		vector<int> X;
		vector<int> Y;
		vector<int> X1;
		int d0;
		for (int x = 1; x < xlocal; x++) {
			int y = s * x;
			X[x] = x;
			Y[x] = y;
		}
		for (int b = 1; b < 854; b++) {
			for (int i = 1; i < xlocal; i++) {
				X1[i] = X[i] + b;
			}
			//X1 = X + b; 
			vector<int> Y1; vector<int> X2;
			for (int i = 4; i < sizeof(Y); i++) {
				if (X1[i] > 854) 
				{
					break;
				}
				else 
				{
					CvScalar p = cvGet2D(src, Y[i], X1[i]);
					if (p.val[0] == 255) {
						Y1.push_back(Y[i]);

						X2.push_back(X1[i]);
					}
				}
			}
			int y0 = Y1[1];
			int x0 = X2[1];
			int sz = sizeof(Y1);
			int y1 = Y1[sz-1];
			int x1 = X2[sz-1];
			int d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
		}
		for (int b1 = 0; b1 > -xlocal; b1--) {
			for (int i = 1; i < xlocal; i++) {
				X1[i] = X[i] + b1;
			}
			//X1 = X + b1; 
			vector<int> Y1; vector<int> X2;
			for (int i = sizeof(Y); i > 4; i--) {
				if (X1[i] <= 0) 
				{
					break;
				}
				else
				{
					CvScalar p = cvGet2D(src, Y[i], X1[i]);
					if (p.val[0] == 255) {
						Y1.push_back(Y[i]);

						X2.push_back(X1[i]);
					}
				}
			}
			int y0 = Y1[1];
			int x0 = X2[1];
			int sz = sizeof(Y1);
			int y1 = Y1[sz-1];
			int x1 = X2[sz-1];
			int d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
		}
		dis.push_back(d0);
		d0 = 0;
	}

	for (int theta = 1; theta < 45; theta++) {
		int theta1 = 90 - theta;
		double theta2 = theta1 * 3.1415926 / 180;
		double s = tan(theta2);
		int ylocal = 854 / s;
		vector<int> X;
		vector<int> Y;
		vector<int> Y1;
		int d0;
		for (int y = 1; y < ylocal; y++) {
			int x = s * y;
			X[y] = x;
			Y[y] = -y;
		}
		for (int b = 1; b < (628 + ylocal); b++) {
			for (int i = 1; i < ylocal; i++) {
				Y1[i] = Y[i] + b;
			}
			//Y1 = Y + b; 
			vector<int> X1; vector<int> Y2;
			for (int i = 4; i < sizeof(X); i++) {
				if (Y1[i] < 0 || Y1[i]>628) 
				{
					break;
				}
				else
				{
					CvScalar p = cvGet2D(src, Y1[i], X[i]);
					if (p.val[0] == 255) {
						X1.push_back(X[i]);

						Y2.push_back(Y1[i]);
					}
				}
			}
			int x0 = X1[1];
			int y0 = Y2[1];
			int sz = sizeof(X1);
			int x1 = X1[sz-1];
			int y1 = Y2[sz-1];
			int d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
        }
		dis.push_back(d0);
		d0 = 0;
	}

	for (int theta = 46; theta < 90; theta++) {
		double theta1 = theta * 3.141592653 / 180;
		double s = tan(theta1);
		int xlocal = 628 / s;
		vector<int> X;
		vector<int> Y;
		vector<int> X1;
		int d0;
		for (int x = 1; x < xlocal; x++) {
			int y = s * x;
			X[x] = x;
			Y[x] = -y+629;
		}
		for (int b = 1; b < 854; b++) {
			for (int i = 1; i < xlocal; i++) {
				X1[i] = X[i] + b;
			}
			//X1 = X + b; 
			vector<int> Y1; vector<int> X2;
			for (int i = 4; i < sizeof(Y); i++) {
				if (X[i] > 854) 
				{
					break;
				}
				else
				{
					CvScalar p = cvGet2D(src, Y[i], X1[i]);
					if (p.val[0] == 255) {
						Y1.push_back(Y[i]);

						X2.push_back(X1[i]);
					}
				}
			}
			int y0 = Y1[1];
			int x0 = X2[1];
			int sz = sizeof(Y1);
			int y1 = Y1[sz-1];
			int x1 = X2[sz-1];
			int d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
		}
		for (int b1 = 0; b1 > -xlocal; b1--) {
			for (int i = 1; i < xlocal; i++) {
				X1[i] = X[i] + b1;
			}
			//X1 = X + b1;  
			vector<int> Y1; vector<int> X2;
			for (int i = sizeof(Y); i > 4; i--) {
				if (X1[i] <= 0) 
				{
					break;
				}
				else
				{
					CvScalar p = cvGet2D(src, Y[i], X1[i]);
					if (p.val[0] == 255) {
						Y1.push_back(Y[i]);

						X2.push_back(X1[i]);
					}
				}
			}
			int y0 = Y1[1];
			int x0 = X2[1];
			int sz = sizeof(Y1);
			int y1 = Y1[sz-1];
			int x1 = X2[sz-1];
			int d = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
			d0 = d0 + d;
		}
		dis.push_back(d0);
		d0 = 0;
	}



	return 0;








}