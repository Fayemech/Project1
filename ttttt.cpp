#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>  

using namespace std;
using namespace cv;

int main()
{   
	vector<int> A;
	for (int i = 1; i < 10; i++) {
		
		A.push_back(i);
		cout << A[i - 1] << endl;
	}
	A[3] = 33;
	cin.get();
	for (int i = 1; i < 10; i++) {
		cout << A[i - 1] << endl;
	}
	    cin.get();
	 	return 0;
}