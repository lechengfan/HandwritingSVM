#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <dirent.h>
#include <vector>

#define NUM_FEATURES = 128*128
using namespace std;
using namespace cv;

const string data_dir = "../data/"; // Global directory for xml data

CvSVM svm; // Global svm
bool SVMtrained = false;

// Get the user's desired action
size_t getCommand() {
	size_t n;
	do {
		cout <<
		"Please choose the number of a command:" << endl <<
		"1. SVM: Train your model" << endl <<
		"2. SVM: Make a prediction" << endl <<
		"3. Exit" << endl <<
		" >> " ;
		cin >> n;
	} while(n < 1 && n > 3);
	return n;
}

// Lists the contents of data_dir
void printDataDirContents() {
	vector<string> v;
	DIR *dpdf;
	struct dirent *epdf;	
	dpdf = opendir(data_dir.c_str());
	if (dpdf != NULL) {
		while(epdf = readdir(dpdf)) {
			if (strcmp(epdf->d_name, ".") && strcmp(epdf->d_name, ".."))
				v.push_back(string(epdf->d_name));
		}
	}
	sort(v.begin(), v.end());
	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << "\t" << *it << endl;
	}
}


// Loads training examples from src in to dst, labels according to value
void loadMatrix(FileNode& src, Mat& dst, Mat& labels, int value) {
	Mat bufMat;
	for (FileNodeIterator it = src.begin(); it != src.end(); ++it) {
		(*it) >> bufMat;
		dst.push_back(bufMat);
		labels.push_back(value);
	}
}

// Get and open FileStorage
bool getAndOpenFile(FileStorage& f) {
	string fileName;
	while(true) {
		printDataDirContents();
		cout << ">> ";
		cin >> fileName;
		if (fileName == "Q" || fileName == "q" || fileName == "Quit" || fileName == "quit") return false;
		if (!f.open(data_dir + fileName, FileStorage::READ)) {
			cout << "Invalid file name. Try again:" << endl;
		} else break;
	}
	return true;
}

void trainSVM() {
	FileStorage posFs;
	FileStorage negFs;

	Mat trainingExamples;
	Mat yMat;
	Mat bufMat;

	int numFeatures, numPos, numNeg;

	cout << "Please select a positive training file: " << endl;
	// Get positive examples
	if (!getAndOpenFile(posFs)) return;

	cout << "Please select a negative training file: " << endl;
	// Get negative examples
	if (!getAndOpenFile(negFs)) return;

	// Loop over both files to get data into single two mats
	FileNode posData = posFs["Data"];
	FileNode negData = negFs["Data"];

	loadMatrix(posData, trainingExamples, yMat, 1);
	loadMatrix(negData, trainingExamples, yMat, -1);

	// Train the svm
	trainingExamples.convertTo(trainingExamples, CV_32F);
	yMat.convertTo(yMat, CV_32F);

	CvSVMParams params;
	params.svm_type = CvSVM::C_SVC;
	params.kernel_type = CvSVM::LINEAR;

	svm.train(trainingExamples, yMat, Mat(), Mat(), params);
	cout << "Should be trained now!" << endl;
	SVMtrained = true;
}

pair<int, int> testAllSVM(Mat& testExamples, Mat& expected) {
	int total = 0;
	int wrong = 0;
	for (int i = 0; i < testExamples.rows; i++) {
		// if ( svm.predict(testExamples.row(i)) != expected.row(i)) {
		// 	wrong++;
		// }
		// total++;
		cout << svm.predict(testExamples.row(i)) << endl;
	}
	// Eventually makign this a pair to get the error
	return pair<int, int>(total, wrong);
}

void predictSVM() {
	string cont;
	if (!SVMtrained) {
		cout << "SVM model not trained yet!" << endl;
		return;
	}
	do {
		FileStorage testFs;	
		Mat testExamples;
		cout << "Please select a file to test on: " << endl;
		if (!getAndOpenFile(testFs)) break;

		FileNode data = testFs["Data"];
		Mat empty;
		loadMatrix(data, testExamples, empty, 1);
		testExamples.convertTo(testExamples, CV_32F);
		testAllSVM(testExamples, empty);
		do {
			cout << "Predict again? Y/N ";
			cin >> cont;
		} while (cont != "Y" && cont != "N");
	} while (cont == "Y");
}

int main() {
	// Print out prompt
	cout << "Welcome to HandwritingSVM" << endl;
	while(true) {
		int n = getCommand();
		if (n == 1) {
			// Train
			trainSVM();
		} else if (n == 2) {
			// Predict
			predictSVM();
		} else {
			break;
		}
	}
}