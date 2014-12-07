#pragma once

#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <vector>

class DataStore {
  public:
    DataStore();

    // Clients can only add data to DataStore. Necessary for keeping labels consistent.
    void add(cv::Mat& data);
    void clear();

    /* Returns true if the partitionw was updated. False otherwise. */
    bool partitionData(int trainingSamples, int testSamples);
    bool partitionDataForTraining(int numTrainingSamples);
    bool partitionDataForTesting(int numTestSamples);

    cv::Mat& getTrainingSamples();
    cv::Mat& getTrainingLabels();
    cv::Mat& getTestSamples();
    cv::Mat& getTestLabels();

  private:
    size_t numTrainingSamplesPerSymbol;
    size_t numTestingSamplesPerSymbol;
    std::vector<cv::Mat> data;
    cv::Mat trainingSamples;
    cv::Mat trainingLabels;
    cv::Mat testSamples;
    cv::Mat testLabels;

    /* Returns the fewest number of symbols in a single symbol*/
    size_t getSmallestSampleSize();
};
