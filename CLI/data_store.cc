#include "data_store.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace std;

DataStore::DataStore() {
  numTrainingSamplesPerSymbol = 0;
  numTestingSamplesPerSymbol = 0;
  numLabels = 0;
}

void DataStore::add(cv::Mat& newData) {
  cv::Mat copy = newData.clone();
  data.push_back(copy);
  numLabels++;
}

void DataStore::clear() {
  data.clear();
  numLabels = 0;
}

bool DataStore::partitionDataForTraining(int numTrainingSamples) {
  if(numTrainingSamples > getSmallestSampleSize() - numTestingSamplesPerSymbol) return false;
  numTrainingSamplesPerSymbol = numTrainingSamples; // set private instance variable
  trainingSamples.release();
  trainingLabels.release();


  size_t numSymbols = data.size();
  // loop through all symbols
  for(size_t m = 0; m < numSymbols; m++) {
    trainingSamples.push_back(data[m].rowRange(0, numTrainingSamplesPerSymbol));
    for(size_t n = 0; n < numTrainingSamplesPerSymbol; n++) {
      trainingLabels.push_back((int)m);
    }
  }
  trainingSamples.convertTo(trainingSamples, CV_32F);
  trainingLabels.convertTo(trainingLabels, CV_32F);
  return true;
}

bool DataStore::partitionDataForTesting(int numTestSamples) {
  if(numTestSamples > getSmallestSampleSize() - numTrainingSamplesPerSymbol) return false;
  numTestingSamplesPerSymbol = numTestSamples;
  testSamples.release();
  testLabels.release();

  size_t numSymbols = data.size();
  // loop through all symbols
  for(size_t m = 0; m < numSymbols; m++) {
    size_t numSamples = data[m].size().height;
    cv::Mat row = data[m].rowRange(numSamples - 1 - numTestSamples, numSamples - 1);
    testSamples.push_back(row);
    for(size_t n = 0; n < numTestSamples; n++) {
      testLabels.push_back((int)m);
    }
  }

  testSamples.convertTo(testSamples, CV_32F);
  testLabels.convertTo(testLabels, CV_32F);
  return true;
}

cv::Mat& DataStore::getTrainingSamples() {
  return trainingSamples;
}

cv::Mat& DataStore::getTrainingLabels() {
  return trainingLabels;
}

cv::Mat& DataStore::getTestSamples() {
  return testSamples;
}

cv::Mat& DataStore::getTestLabels() {
  return testLabels;
}

size_t DataStore::getNumLabels() {
  return numLabels;
}

size_t DataStore::getSmallestSampleSize() {
  size_t numSymbols = data.size();
  size_t smallestSampleSize = (size_t) -1;
  for (size_t m = 0; m < numSymbols; m++) {
    size_t curSampleSize = data[m].size().height;
    if (curSampleSize < smallestSampleSize) {
      smallestSampleSize = curSampleSize;
    }
  }
  return smallestSampleSize;
}