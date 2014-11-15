#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;
using namespace cv;

int main (int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Usage: SVM positiveFile negativeFile" << endl;
		return -1;
	}

	FileStorage posFs(argv[1], FileStorage::READ);
	FileStorage negFs(argv[2], FileStorage::READ); // lol no error checking but i think it throws an exception anyway
	
	int numPos, numNeg, numFeatures; // read in these values from the data file
	posFs["NumExamples"] >> numPos;
	negFs["NumExamples"] >> numNeg;
	posFs["NumFeatures"] >> numFeatures;

	cout << "Number of positive examples: " << numPos << endl;
	cout << "Number of negative examples: " << numNeg << endl;
	cout << "Number of features: " << numFeatures << endl;

	FileNode posData = posFs["Data"]; // File node is stored under this name
	FileNode negData = negFs["Data"];

	Mat trainingExamples;
	Mat trainingDataFinal;

	Mat yMat(0, 0, CV_64F); // Vector of training labels

	Mat bufMat;

	for (FileNodeIterator it = negData.begin(); it != negData.end(); ++it) {
		(*it) >> bufMat;
		trainingExamples.push_back(bufMat);
		yMat.push_back(-1);
	}

	// read in positive training examples
	for (FileNodeIterator it = posData.begin(); it != posData.end(); ++it) {
		(*it) >> bufMat;
		trainingExamples.push_back(bufMat); // concatenate new row
		yMat.push_back(1);
	}

	trainingExamples.convertTo(trainingExamples, CV_32F);
	yMat.convertTo(yMat, CV_32F);
	cout << trainingExamples.rows << endl;
	cout << trainingExamples.cols << endl;
	// Train SVM
	CvSVMParams params;
	params.svm_type = CvSVM::C_SVC;
	params.kernel_type = CvSVM::LINEAR;
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6); // No idea what this is but documentation does it
    CvSVM svm;
    svm.train(trainingExamples, yMat);

	return 0;
}





