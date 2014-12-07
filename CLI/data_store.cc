#include "data_store.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace std;

DataStore::DataStore() {
  numTrainingSamplesPerSymbol = 0;
  numTestingSamplesPerSymbol = 0;
}

void DataStore::add(cv::Mat& data) {
  cv::Mat copy = data.clone();
  data.push_back(copy);
}

void DataStore::clear() {
  data.clear();
}

bool DataStore::partitionData(int trainingSamples, int testSamples) {
  // Error checking
  size_t smallestSampleSize = getSmallestSampleSize();
  if (trainingSamples + testSamples > smallestSampleSize) {
    return false;
  }

  if(!partitionDataForTraining(trainingSamples)) return false;
  if(!partitionDataForTesting(testSamples)) return false;
}

bool DataStore::partitionDataForTraining(int numTrainingSamples) {
  if(numTrainingSamples > getSmallestSampleSize() - numTestingSamplesPerSymbol) return false;

  size_t numSymbols = data.size();
  // loop through all symbols
  for(size_t m = 0; m < numSymbols; m++) {
    trainingSamples.push_back(data[m].rowRange(0, m));
  }
  numTrainingSamplesPerSymbol = numTrainingSamples;
  return true;
}

bool DataStore::partitionDataForTesting(int numTestSamples) {
  if(numTestSamples > getSmallestSampleSize() - numTrainingSamplesPerSymbol) return false;

  size_t numSymbols = data.size();
  // loop through all symbols
  testSamples.release();
  for(size_t m = 0; m < numSymbols; m++) {
    testSamples.push_back(data[m].rowRange(numSymbols - 1 - numTestSamples, numSymbols - 1));
  }
  numTestingSamplesPerSymbol = numTestSamples;
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