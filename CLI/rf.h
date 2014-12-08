#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class RF {
public:
	RF();
	void train(const cv::Mat& trainSamples, const cv::Mat& trainLabels);

	/* True if successful, false otherwise. */
	bool predict(const cv::Mat& testSamples, cv::Mat& predictions);
  private:
	bool trained; // intialized to false
  CvRTrees rf;
};