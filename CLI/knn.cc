#include "knn.h"

using namespace std;
using namespace cv;

KNN::KNN() {
	trained = false;
}

void KNN::train(const cv::Mat& trainSamples, const cv::Mat& trainLabels) {
	knn.train(trainSamples, trainLabels, Mat(), false, 10, false);
	trained = true;
}

bool KNN::predict(const cv::Mat& testSamples, cv::Mat& predictions) {
	int numSamples = testSamples.size().height;
	if(!trained) return false;
	for(int i=0; i< numSamples; i++) {
		float predictedLabel = knn.find_nearest(testSamples.row(i), 10, 0, 0, 0, 0);
		predictions.push_back(predictedLabel);
	}
	return true;
}