#include "data_store.h"
#include <iostream>
#include <dirent.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include "mlp.h"
#include "svm.h"
#include "rf.h"
#include "knn.h"

using namespace std;

// Prototypes
size_t getCommand();
void printDataDirContents();
bool loadFile(cv::Mat& trainingExamples, cv::Mat& trainingLabels, int label, string fileName);
bool getAndOpenFile(cv::FileStorage& fs, string fileName);
void loadMatrix(cv::FileNode& src, cv::Mat& dst, cv::Mat& labels, int value);

// Handles the 5 routines
void loadData(DataStore& ds);
void partitionData(DataStore& ds);
void train(DataStore& ds);
void predict(DataStore& ds);

// Globals
MLP mlp;
SVM_MTQ svm;
RF rf;
KNN knn;

// Directory
const string DATA_DIR = "../Handwriting_Images/AllData/";

// Executes the main loop-execute routine
int main() {
  DataStore ds;

  while(true) {
    size_t command = getCommand();

    switch(command) {
      case 1: // load data
        loadData(ds);
        break;
      case 2: // partition data
        partitionData(ds);
        break;
      case 3: // train all algorithms
        train(ds);
        break;
      case 4: // test all algorithms
        predict(ds);
        break;
      case 5: // analyze routine
        break;
      case 6: // exit
        return 0;
      default:
        cout << "Did not recognize command, please try again." << endl;
    }
  }
}

// Gets a command from the user for the main loop
size_t getCommand() {
  size_t n;
  do {
    cout <<
    "Please choose the number of a command:" << endl <<
    "1. Load data" << endl <<
    "2. Partition data" << endl <<
    "3. Train all algorithms" << endl <<
    "4. Test all algorithms" << endl <<
    "5. Analyze Routine" << endl <<
    "6. Exit" << endl <<
    " >> " ;
    string userInput;
    getline(cin, userInput);
    stringstream(userInput) >> n;

  } while(n < 1 || n > 6);
  return n;
}

void loadData(DataStore& ds) {
  printDataDirContents();

  cout << "Please list the files you would like to import, " <<
    "separated by a space between each file's name" << endl;

  // Gets the user's input to the command line and puts each
  // file name, separated by spaces, into a vector fileNames
  string userInput;
  getline(cin, userInput);
  stringstream ss;
  ss << userInput;
  vector<string> fileNames;
  while(true) {
    string fileName;
    ss >> fileName;
    fileNames.push_back(fileName);
    if(ss.eof()) break;
  }

  size_t numFiles = fileNames.size();
  bool success;
  for(size_t m = 0; m < numFiles; m++) {
    cv::Mat trainingSamples;
    cv::Mat trainingLabels;
    int label = m;
    string fileName = fileNames[m];

    success = loadFile(trainingSamples, trainingLabels, label, fileName);

    if(success) {
      ds.add(trainingSamples);
    } else {
      ds.clear();
      cout << "Incorrect file name: " << fileName << endl;
      break;
    }
  }
}

void partitionData(DataStore& ds) {
  cout << "Please enter the number of training samples and testing samples" <<
    " you would like on one line, separated by a space." << endl;

  string userInput;
  getline(cin, userInput);
  stringstream ss;
  ss << userInput;
  size_t numTrainingSamples;
  size_t numTestingSamples;
  ss >> numTrainingSamples;
  ss >> numTestingSamples;

  bool success = ds.partitionDataForTraining(numTrainingSamples);
  if(!success) cout << "You can't have that many training samples" << endl;
  success = ds.partitionDataForTesting(numTestingSamples);
  if(!success) cout << "You can't have that many testing samples" << endl;
}

void train(DataStore& ds) {
  mlp.train(ds.getTrainingSamples(), ds.getTrainingLabels(), ds.getNumLabels());
  svm.train(ds.getTrainingSamples(), ds.getTrainingLabels());
  rf.train(ds.getTrainingSamples(), ds.getTrainingLabels());
  knn.train(ds.getTrainingSamples(), ds.getTrainingLabels());
}

void predict(DataStore& ds) {
  cout << "Which algorithm?" << endl <<
  "1. Neural Nets (MLP)" << endl <<
  "2. SVM " << endl <<
  "3. RF" << endl <<
  "4. KNN" << endl;

  int n;
  cin >> n;
  cv::Mat predictions;
  switch(n) {
    case 1: {
      mlp.predict(ds.getTestSamples(), predictions, ds.getNumLabels());
      break;
    }
    case 2: {
      svm.predict(ds.getTestSamples(), predictions);
      break;
    }
    case 3: {
      rf.predict(ds.getTestSamples(), predictions);
      break;
    }
    case 4: {
      knn.predict(ds.getTestSamples(), predictions);
      break;
    }
    default:
      cout << "Not a valid choice. Try again" << endl;
  }

  size_t numRight = 0;
  size_t numWrong = 0;
  for(size_t m = 0; m < predictions.size().height; m++) {
    (predictions.at<int>(m) == ds.getTestLabels().at<int>(m)) ? numRight++ : numWrong++;
  }

  cout << "Error: " << numWrong / (numRight + 0.0 + numWrong) << endl;
}

void analyze(DataStore& ds) {

}

// fs - file to put the data in 
// label - the number of the label
bool loadFile(cv::Mat& trainingExamples, cv::Mat& trainingLabels, int label, string fileName) {
  cv::FileStorage fs;
  if (!getAndOpenFile(fs, fileName)) return false;
  cv::FileNode data = fs["Data"];
  loadMatrix(data, trainingExamples, trainingLabels, label);
  return true;
}

void printDataDirContents() {
  vector<string> v;
  DIR *dpdf;
  struct dirent *epdf;  
  dpdf = opendir(DATA_DIR.c_str());
  if (dpdf != NULL) {
    while(epdf = readdir(dpdf)) {
      if (strcmp(epdf->d_name, ".") && strcmp(epdf->d_name, ".."))
        v.push_back(string(epdf->d_name));
    }
  }
  sort(v.begin(), v.end());
  for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << "\t" << *it << endl;
  }
}

// Get and open FileStorage
bool getAndOpenFile(cv::FileStorage& fs, string fileName) {
  if (fileName == "Q" || fileName == "q" || fileName == "Quit" || fileName == "quit") return false;
  if (!fs.open(DATA_DIR + fileName, cv::FileStorage::READ)) {
    cout << "Invalid file names. Try again:" << endl;
    return false;
  }
  return true;
}

// Loads training examples from src in to dst, labels according to value
void loadMatrix(cv::FileNode& src, cv::Mat& dst, cv::Mat& labels, int value) {
  cv::Mat bufMat;
  for (cv::FileNodeIterator it = src.begin(); it != src.end(); ++it) {
    (*it) >> bufMat;
    dst.push_back(bufMat);
    labels.push_back(value);
  }
}