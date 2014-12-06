#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <dirent.h>
#include <vector>

#define NUM_FEATURES 128*128
using namespace std;
using namespace cv;

const string train_data_dir = "../Handwriting_Images/Train/"; // Global directory for xml data
// const string test_data_dir = "../data/";

const string test_data_dir = "../Handwriting_Images/Test/";

CvSVM svm; // Global svm object
CvKNearest knn; // Global nearest neighbors object
CvRTrees rt; // Global random trees object
CvANN_MLP mlp; // Global multi-layer perceptron
bool trained = false;

// Get the user's desired action
size_t getCommand() {
	size_t n;
	do {
		cout <<
		"Please choose the number of a command:" << endl <<
		"1. Train all models" << endl <<
		"2. Make a prediction" << endl <<
		"3. Exit" << endl <<
		" >> " ;
		cin >> n;
	} while(n < 1 && n > 3);
	return n;
}

// Lists the contents of data_dir
void printDataDirContents(bool train) {
	vector<string> v;
	DIR *dpdf;
	struct dirent *epdf;	
	dpdf = opendir(train? train_data_dir.c_str() : test_data_dir.c_str());
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
bool getAndOpenFile(FileStorage& f, bool train) {
	string fileName;
	while(true) {
		printDataDirContents(train);
		cout << ">> ";
		cin >> fileName;
		if (fileName == "Q" || fileName == "q" || fileName == "Quit" || fileName == "quit") return false;
		if (!f.open((train ? train_data_dir : test_data_dir) + fileName, FileStorage::READ)) {
			cout << "Invalid file name. Try again:" << endl;
		} else break;
	}
	return true;
}

// fs - file to put the data in 
// label - the number of the label
bool loadTrainingFile(Mat& trainingExamples, Mat& yMat, int label) {
	cout << "Please select a training file (these training examples will be labeled " << label << "): " << endl;
	FileStorage fs;
	if (!getAndOpenFile(fs, true)) return false;
	FileNode data = fs["Data"];
	loadMatrix(data, trainingExamples, yMat, label);
	return true;
}

void trainAll() {

	Mat trainingExamples;
	Mat yMat;

	int numFeatures, numPos, numNeg;

	int i;
	cout << "Number of labels? " << endl;
	cin >> i;

	for (int j = 0; j < i; j++) {
		loadTrainingFile(trainingExamples, yMat, j);
	}

	// Train the svm
	trainingExamples.convertTo(trainingExamples, CV_32F);
	yMat.convertTo(yMat, CV_32F);

	CvSVMParams svmParams;
	svmParams.svm_type = CvSVM::C_SVC;
	svmParams.kernel_type = CvSVM::LINEAR;

	// Trianing parameters for MLP
	CvANN_MLP_TrainParams mlpParams( 	cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 1000, 0.000001),
																		CvANN_MLP_TrainParams::BACKPROP,
																		0.1,
																		0.1);

	CvRTParams rtParams;

	svm.train(trainingExamples, yMat, Mat(), Mat(), svmParams);
	knn.train(trainingExamples, yMat, Mat(), false, 10, false);
	rt.train(trainingExamples, CV_ROW_SAMPLE, yMat, Mat(), Mat(), Mat(), Mat(), CvRTParams());
	mlp.train(trainingExamples, yMat, Mat(), Mat(), mlpParams);

	cout << "Should be trained now!" << endl;
	trained = true;
}

pair<int, int> testAll(Mat& testExamples, Mat& expected, char flag) {
	int total = 0;
	int wrong = 0;
	// Storage for mlp
	Mat output;
	for (int i = 0; i < testExamples.rows; i++) {
		int prediction;
		switch (flag) {
			case('1'):
				prediction = svm.predict(testExamples.row(i));
				break;
			case('2'):
				prediction = knn.find_nearest(testExamples.row(i), 10, 0, 0, 0, 0);
				break;
			case('3'):
				prediction = rt.predict(testExamples.row(i));
				break;
			case('4'):
			  // source: http://www.nithinrajs.in/ocr-artificial-neural-network-opencv-part-3final-preprocessing/
				int numClasses = 3;
				Mat classificationResult(1, numClasses, CV_32F);
				mlp.predict(testExamples.row(i), classificationResult);
				
				// find the class with the maximum weightage, which indicates
				// the predicted class
				int maxIndex = 0;
				float value = 0.0f;
				float maxValue = classificationResult.at<float>(0,0);
				for (int m = 1; m < numClasses; m++) {
					value = classificationResult.at<float>(0, m);
					if (value > maxValue) {
						maxValue = value;
						maxIndex = m;
					}
				}
				prediction = maxIndex;
				break;
			default:
				return pair<int, int>(-1, -1);
		}
		cout << prediction << endl;
		if (prediction != expected.at<int>(i, 0)) wrong++;
		total++;
	}
	cout << "total: " << total << " wrong: " << wrong << endl;
	// Eventually making this a pair to get the error
	return pair<int, int>(total, wrong);
}

void predictAll() {
	if (!trained) {
		cout << "Model not trained yet!" << endl;	
		return;
	}
	string cont;
	char opt;
	cout << "Please select a model to predict with: " << endl
		 << "1. Support Vector Machine" << endl
		 << "2. K-Nearest-Neighbors" << endl
		 << "3. Random Trees" << endl
		 << "4. MLP Neural Nets" << endl;
	cout << " >> ";
	cin >> opt; 
	do {
		FileStorage testFs;	
		Mat testExamples;
		cout << "Please select a file to test on: " << endl;
		if (!getAndOpenFile(testFs, false)) break;

		cout << "What is the expected label? "; 
		int y;
		cin >> y;

		FileNode data = testFs["Data"];
		Mat labels;
		loadMatrix(data, testExamples, labels, y);
		testExamples.convertTo(testExamples, CV_32F);

		// Test everything!
		pair<int, int> results;
		results = testAll(testExamples, labels, opt);

		if (results.first == -1) {
			cout << "Invalid option." << endl;
			return;
		}
		cout << "Error: " << ((float)results.second)/results.first * 100 << "%" << endl;
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
			trainAll();
		} else if (n == 2) {
			// Predict
			predictAll();
		} else {
			break;
		}
	}
}