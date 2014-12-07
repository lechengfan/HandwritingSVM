#include "data_store.h"
#include <iostream>
#include <dirent.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <string>

using namespace std;

// Prototypes
size_t getCommand();
void printDataDirContents();
bool loadFile(cv::Mat& trainingExamples, cv::Mat& trainingLabels, int label, string fileName);
bool getAndOpenFile(cv::FileStorage& fs, string fileName);
void loadMatrix(cv::FileNode& src, cv::Mat& dst, cv::Mat& labels, int value);

// Handles the 5 routines
void loadData(DataStore& ds);

// Directory
const string DATA_DIR = "../Handwriting_Images/Train/";

// Executes the main loop-execute routine
int main() {
  DataStore ds();

  while(true) {
    size_t command = getCommand();

    switch(command) {
      case 1: // load data
        loadData(ds);
        break;
      case 2: // partition data
        break;
      case 3: // train all algorithms
        break;
      case 4: // test all algorithms
        break;
      case 5: // analyze routine
        break;
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
    " >> " ;
    cin >> n;
  } while(n < 1 || n > 5);
  return n;
}

void loadData(DataStore& ds) {
  printDataDirContents();
  cout << "Please list the files you would like to import, " <<
    "separated by a space between each file's name" << endl;

  vector<string> fileNames;
  string input;
  while(cin >> input) {
    fileNames.push_back(input);
  }

  size_t numFiles = fileNames.size();
  bool success;
  for(size_t m = 0; m < numFiles; m++) {
    cv::Mat trainingSamples;
    cv::Mat trainingLabels;
    int label = m;
    string fileName = fileNames[m];

    success = loadFile(trainingSamples, trainingLabels, label, fileName);
    if(!success) {
      ds.clear();
      cout << "Incorrect file name: " << fileName << endl;
      break;
    }
  }
}

// fs - file to put the data in 
// label - the number of the label
bool loadFile(cv::Mat& trainingExamples, cv::Mat& trainingLabels, int label, string fileName) {
  cv::FileStorage fs;
  if (!getAndOpenFile(fs)) return false;
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
bool getAndOpenFile(FileStorage& fs, string fileName) {
  if (fileName == "Q" || fileName == "q" || fileName == "Quit" || fileName == "quit") return false;
  if (!fs.open(DATA_DIR +  fileName, FileStorage::READ)) {
    cout << "Invalid file names. Try again:" << endl;
  } else break;
}

// Loads training examples from src in to dst, labels according to value
void loadMatrix(cv::FileNode& src, cv::Mat& dst, cv::Mat& labels, int value) {
  cv::Mat bufMat;
  for (FileNodeIterator it = src.begin(); it != src.end(); ++it) {
    (*it) >> bufMat;
    dst.push_back(bufMat);
    labels.push_back(value);
  }
}