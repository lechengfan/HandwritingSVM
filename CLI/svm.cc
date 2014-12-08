#include "svm.h"

using namespace std;
using namespace cv;

SVM_MTQ::SVM_MTQ () {
	trained = false;
}

void SVM_MTQ::train(const cv::Mat& trainSamples, const cv::Mat& trainLabels) {
	// Define the params
	CvSVMParams svmParams;
	svmParams.svm_type = CvSVM::C_SVC;
	svmParams.kernel_type = CvSVM::LINEAR;

	// Train the SVM
	svm.train(trainSamples, trainLabels, Mat(), Mat(), svmParams);
	trained = true;
}

bool SVM_MTQ::predict(const cv::Mat& testSamples, cv::Mat& predictions) {
	if (!trained) return false;

	Mat _predictions;
	svm.predict(testSamples, _predictions);
	if (_predictions.empty()) return false;
	predictions = _predictions;
	return true;
}