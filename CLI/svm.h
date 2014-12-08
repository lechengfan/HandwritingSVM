#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class SVM_MTQ {
public:
	SVM_MTQ();
	void train(const cv::Mat& trainSamples, const cv::Mat& trainLabels);

	/* True if successful, false otherwise. */
	bool predict(const cv::Mat& testSamples, cv::Mat& predictions);
  private:
	bool trained; // intialized to false
  CvSVM svm;
};