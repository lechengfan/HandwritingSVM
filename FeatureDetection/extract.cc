#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <sstream> 
#include <string>
#include <stdlib.h>

using namespace std;
using namespace cv;

const int kMaxCorners = 7;

void printPrompt() {
	cout << "Select a feature selection technique: " << endl;
	cout 	<< "1. Edges" << endl
	     	<< "2. Corners" << endl
	     	<< "3. Blobs" << endl;
}

int getInt(int min, int max) {
	int result;
	do {
		cout << "Please enter a number between " << min << " and " << max << ": ";
		string input;
		getline(cin, input);
		result = atoi(input.c_str());
	} while (result < min || result > max);
}

void getImage(Mat& output) {
	string filename;
	do {
		cout << "Please enter an image path: ";
		getline(cin, filename);
		output = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	} while (!output.data && cout << "Invalid image. ");
}

void getCorners(Mat& input, Mat& output) {
	// Using the harris detector
	goodFeaturesToTrack(input, output, kMaxCorners, 0.02, 1, /*mask=*/Mat(), /*blockSize=*/3, true, /*k=*/0.04);
	cout << output << endl;
}

int main() {
	int opt;
	Mat img;
	Mat greyImg;
	Mat output;
	while (true) {
		getImage(img); 
		getCorners(img, output);
	}
}








