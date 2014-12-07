#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class LearningModel {
	public:
		virtual void train(const cv::Mat& trainingSamples, const cv::Mat&trainingLabels, int numLabels);
		virtual void predict(const cv::Mat & testSamples, const cv::Mat& testLabels, cv::Mat& results);
};
