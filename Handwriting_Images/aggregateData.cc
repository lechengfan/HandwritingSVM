#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <sstream> 
#include <stdlib.h>
#include <string>
#include "dirent.h"

#define NUM_FEATURES 128*128

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage: ./aggregateData SymbolDirectory" << endl;
		return -1;
	}
	string outputFile=argv[1];
	FileStorage fs(outputFile+".xml", FileStorage::WRITE);
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
			    Mat imGray, inverted, result;
				imGray = imread(outputFile+"/"+imageFileName, CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
				if(! imGray.data) {
					cout << "Could not open image" << endl;
					continue;
				}
				// normalize(imGray, imGray, 0.0, 1.0, CV_MINMAX, CV_64F);
				//Black pixels become white; white turns to black
				inverted = cv::Scalar::all(255) - imGray;
				Moments mu = moments(inverted, false);
				double x_center = mu.m10/mu.m00;
				double y_center = mu.m01/mu.m00;

				float translate[2][3] = {{1, 0, 64-x_center}, {0,1,64-y_center}};
				Mat translateMat = Mat(2,3, CV_32FC1, &translate);
				warpAffine(inverted, result, translateMat, Size(128,128));
				result = cv::Scalar::all(255) - result;
				normalize(result, result, 0.0, 1.0, CV_MINMAX, CV_64F);
				result.convertTo(result, CV_8UC3, 255.0);

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