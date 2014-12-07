#pragma once

#include "learning_model.h"

class MLP : public LearningModel {
	public:
		MLP();
		void train(const cv::Mat& trainSamples, const cv::Mat& testLabels, int numLabels);
		void predict(const cv::Mat& testSamples, const cv::Mat& testLabels, cv::Mat& results);
  private:
    bool trained; // intialized to false
};