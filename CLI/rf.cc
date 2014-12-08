#include "rf.h"

using namespace std;
using namespace cv;

RF::RF() {
	trained = false;	
}

void RF::train(const cv::Mat& trainSamples, const cv::Mat& trainLabels) {
	rf.train(trainSamples, CV_ROW_SAMPLE, trainLabels, Mat(), Mat(), Mat(), Mat(), CvRTParams());
	trained = true;
}

bool RF::predict(const cv::Mat& testSamples, cv::Mat& predictions) {
	Mat _predictions;
	for (int i = 0; i < testSamples.rows; i++) {
		_predictions.push_back(rf.predict(testSamples.row(i)));
	}
	predictions = _predictions;
	return !testSamples.empty();
}
