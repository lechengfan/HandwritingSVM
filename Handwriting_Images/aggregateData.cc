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
			    Mat imGray;
				imGray = imread(outputFile+"/"+imageFileName, CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
				if(! imGray.data) {
					cout << "Could not open image" << endl;
					continue;
				}
				Mat vectorized = imGray.reshape(1,1);
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