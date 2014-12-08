#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class MLP {
	public:
    MLP();
		void train(const cv::Mat& trainSamples, const cv::Mat& trainLabels, int numLabels);

    /* True if successful, false otherwise. */
		bool predict(const cv::Mat& testSamples, cv::Mat& predictions, int numLabels);
  private:
    bool trained; // intialized to false
    CvANN_MLP mlp;
};