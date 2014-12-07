// REFERENCE: 
// http://docs.opencv.org/trunk/doc/py_tutorials/py_ml/py_svm/py_svm_opencv/py_svm_opencv.html


#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <dirent.h>
#include <vector>

using namespace std;
using namespace cv;

void HoG(Mat& input, Mat& output) {
	Mat gx, gy;
	Mat mag, angle
	Sobel(input, gx, CV_32F, 1, 0);
	Sobel(input, gy, CV_32F, 0, 1);
	cartToPolar(gx, gy, mag, angle);
}

int main() {

}