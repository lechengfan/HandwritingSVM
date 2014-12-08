#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class KNN {
	public:
		KNN();
		void train(const cv::Mat& trainSamples, const cv::Mat& trainLabels);
		bool predict(const cv::Mat& testSamples, cv::Mat& predictions);
	private:
		bool trained;
		CvKNearest knn;
};