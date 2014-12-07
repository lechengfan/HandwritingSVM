#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <sstream> 
#include <stdlib.h>
#include <string>
#include "dirent.h"

const int NUM_FEATURES = 128*128;
const int numCorners = 7;
const double qualityLevel = 0.00000000000001;

using namespace std;
using namespace cv;

void resizeAndStretch(Mat& imOrig, Mat& imResized);
void findCentroidAndCenter (Mat& imGray, Mat& result);

void resizeAndStretch(Mat& imOrig, Mat& imResized) {
	  imOrig.convertTo(imOrig, CV_32F);
	  Size originalSize = imOrig.size();
	  int maxX=0, minX=originalSize.width, maxY = 0, minY=originalSize.height;
	  for(int i=0; i<originalSize.width; i++) {
	    for(int j=0; j<originalSize.height; j++) {
	      float value = imOrig.at<float>(i,j);
	      if(value<241) {
	        maxX = max(maxX, i);
	        minX = min(minX, i);
	        maxY = max(maxY, j);
	        minY = min(minY, j);
	      }
	    }
	  }  
	  int resize_width = maxX-minX;
	  int resize_height = maxY-minY;
	  Rect cropped(minY, minX, resize_height, resize_width);
	  Mat croppedMat = imOrig(cropped);

	  resize(croppedMat, imResized, Size(128,128), (float) originalSize.width/resize_width, (float) originalSize.height/resize_height,  CV_INTER_CUBIC);
}

void findCentroidAndCenter (Mat& imGray, Mat& result) {
//Black pixels become white; white turns to black
	Mat inverted = cv::Scalar::all(255) - imGray;
	Moments mu = moments(inverted, false);
	double x_center = mu.m10/mu.m00;
	double y_center = mu.m01/mu.m00;

	float translate[2][3] = {{1, 0, 64-x_center}, {0,1,64-y_center}};
	Mat translateMat = Mat(2,3, CV_32FC1, &translate);
	warpAffine(inverted, result, translateMat, Size(128,128));
	result = cv::Scalar::all(255) - result;
	normalize(result, result, 0.0, 1.0, CV_MINMAX, CV_64F);
	result.convertTo(result, CV_8UC3, 255.0);	
}


int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage: ./aggregateData SymbolDirectory" << endl;
		return -1;
	}
	string outputFile=argv[1];
	FileStorage fs(outputFile + "_corner7_center" +".xml", FileStorage::WRITE);
	fs << "NumFeatures" << NUM_FEATURES;
	fs << "Data" << "[";
	DIR *dpdf;
	struct dirent *epdf;	
	dpdf = opendir(argv[1]);
	if (dpdf != NULL) {
		int nExamples=0;
		while(epdf = readdir(dpdf)) {
			if (strcmp(epdf->d_name, ".") && strcmp(epdf->d_name, "..") && strcmp(epdf->d_name, ".xml")) {
				string imageFileName = (string(epdf->d_name));
				cout << imageFileName << endl;
			    Mat imGray, result;
				imGray = imread(outputFile+"/"+imageFileName, CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
				if(! imGray.data) {
					cout << "Could not open image" << endl;
					continue;
				}
				normalize(imGray, imGray, 0.0, 1.0, CV_MINMAX, CV_64F);

				// resizeAndStretch(imGray, result);
				findCentroidAndCenter(imGray, result);
				goodFeaturesToTrack(result, result, numCorners, qualityLevel, 1);
				Mat vectorized = result.reshape(1,1);
				fs << vectorized;
				nExamples++;
			}
		}
		fs << "]";
		fs << "NumExamples" << nExamples;
		fs.release();
		return 0;
	}
	else {
		cout << "Folder not found" << endl;
		return -1;
	}
}