#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;
using namespace cv;

int main (int argc, char *argv[]) {
	if (argc != 4) {
		cout << "Usage: SVM positiveFile negativeFile testFile" << endl; // assumes testFile has only positive examples
		return -1;
	}

	FileStorage posFs(argv[1], FileStorage::READ);
	FileStorage negFs(argv[2], FileStorage::READ); // lol no error checking but i think it throws an exception anyway
	FileStorage testFs(argv[3], FileStorage::READ);
	
	int numPos, numNeg, numFeatures, numTests; // read in these values from the data file
	posFs["NumExamples"] >> numPos;
	negFs["NumExamples"] >> numNeg;
	posFs["NumFeatures"] >> numFeatures;
	testFs["NumExamples"] >> numTests;

	cout << "Number of positive examples: " << numPos << endl;
	cout << "Number of negative examples: " << numNeg << endl;
	cout << "Number of features: " << numFeatures << endl;
	cout << "Number of test points: " << numTests << endl;

	FileNode posData = posFs["Data"]; // File node is stored under this name
	FileNode negData = negFs["Data"];
	FileNode testData = testFs["Data"];

	Mat trainingExamples;
	Mat testMat;

	Mat yMat;
	Mat testLabels;

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

	for (FileNodeIterator it = testData.begin(); it != testData.end(); ++it) {
		(*it) >> bufMat;	
		testMat.push_back(bufMat);
	}

	trainingExamples.convertTo(trainingExamples, CV_32F);
	yMat.convertTo(yMat, CV_32F);
	testMat.convertTo(testMat, CV_32F);
	testLabels.convertTo(testLabels, CV_32F);

	cout << testMat.size() << endl;
	cout << testLabels.size() << endl;

	// Train SVM
	CvSVMParams params;
	params.svm_type = CvSVM::C_SVC;
	params.kernel_type = CvSVM::LINEAR; // Just a standard dot product for now
	// params.Cvalue = 1000;
    // params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6); // No idea what this is but documentation does it
    CvSVM svm;
    bool x = svm.train(trainingExamples, yMat, Mat(), Mat(), params);
   	cout << "Trained? " << x << endl; 
    // svm.predict(testMat, testLabels);
    // for (int i = 0; i < testLabels.rows; i++) {
    // 	cout << testLabels.row(i) << endl;
    // }
    for (int i = 0; i < testMat.rows; i++) {
    	cout << svm.predict(testMat.row(i)) << endl;
    }

	return 0;
}





