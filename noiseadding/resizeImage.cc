#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <algorithm>

using namespace cv;
using namespace std;

int main(int argc, char ** argv) {
  
  if(argc!=2) {
    cout<< "Usage: display_image" << endl;
    exit(-1);
  }
  
  Mat imOrig, imResized;
  imOrig = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE); //Read file grayscale

  if(! imGray.data) {
    cout<< "Cannot open or find the image." << endl;
    exit(-1);
  }
  Size originalSize = imOrig.size();
  int width = originalSize.width;
  int height = originalSize.height;
  int max = max(width, height);
  double ratio = 128.0/max;
  //Size size(128, 128);
  resize(imOrig, imResized, Size(), ratio, CV_INTER_AREA);
  
  
