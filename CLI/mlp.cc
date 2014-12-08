#include "mlp.h"

using namespace std;

MLP::MLP() {
  trained = false;
}

void MLP::train(const cv::Mat& trainSamples, const cv::Mat& trainLabels, int numLabels) {
  int numfeatures = trainSamples.size().width;
  cv::Mat layers(4, 1, CV_32S);
  layers.at<int>(0, 0) = 128 * 128 ; // input layer
  layers.at<int>(1, 0) = 8; // hidden layer
  layers.at<int>(2, 0) = 8;
  layers.at<int>(3, 0) = numLabels; // output layer
  mlp.create(layers, CvANN_MLP::SIGMOID_SYM, 0.6, 1);

  CvANN_MLP_TrainParams mlpParams(  cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 1000, 0.000001),
                                    CvANN_MLP_TrainParams::BACKPROP,
                                    0.1,
                                    0.1);
  // MLP require output data in a different format.
  // For example, if we had a trainLabels of [1; 2; 0], the corresponding
  // mlpLabels would be:
  /*
      0 1 2
    [ 0 1 0;
      0 0 1;
      1 0 0 ]
  */
  int numSamples = trainLabels.size().height;
  cv::Mat mlpLabels(numSamples, numLabels, cv::DataType<float>::type);
  for(int m = 0; m < numSamples; m++) {
    int yVal = trainLabels.at<float>(m, 0);
    for(int n = 0; n < numLabels; n++) {
      if(yVal == n) {
        mlpLabels.at<float>(m, n) = 1.0;
      } else {
        mlpLabels.at<float>(m, n) = 0.0;
      }
    }
  }
  mlp.train(trainSamples, mlpLabels, cv::Mat(), cv::Mat(), mlpParams);

  trained = true;
}

bool MLP::predict(const cv::Mat& testSamples, cv::Mat& predictions, int numLabels) {
  if(!trained) return false;

  testSamples.convertTo(testSamples, CV_32F);
  int numSamples = testSamples.size().height;
  int numClasses = numLabels;

  // source: http://www.nithinrajs.in/ocr-artificial-neural-network-opencv-part-3final-preprocessing/

  cv::Mat _predictions;
  for(int i = 0; i < numSamples; i++) {
    cv::Mat classificationResult(1, numClasses, CV_32F);
    mlp.predict(testSamples.row(i), classificationResult);
    
    // find the class with the maximum weightage, which indicates
    // the predicted class
    int maxIndex = 0;
    float value = 0.0f;
    float maxValue = classificationResult.at<float>(0,0);
    for (int m = 0; m < numClasses; m++) {
      value = classificationResult.at<float>(0, m);
      if (value > maxValue) {
        maxValue = value;
        maxIndex = m;
      }
    }
    _predictions.push_back(maxIndex);
  }

  predictions = _predictions;
}