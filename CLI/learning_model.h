#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class LearningModel {
	public:
    LearningModel();
		virtual void train(const cv::Mat& trainingSamples, const cv::Mat&trainingLabels, int numLabels) = 0;
		virtual bool predict(const cv::Mat & testSamples, const cv::Mat& testLabels, cv::Mat& results);

  private:
    bool trained;
};
