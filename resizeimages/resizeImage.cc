
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <algorithm>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char ** argv) {
  
  if(argc!=2) {
    cout << "Usage: ./resizeImage filename" << endl;
    exit(-1);
  }
  
  Mat imOrig, imResized;
  String filename = argv[1];
  imOrig = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE); //Read file grayscale

  if(!imOrig.data) {
    cout<< "Cannot open or find the image." << endl;
    exit(-1);
  }
  Size originalSize = imOrig.size();
  int width = originalSize.width;
  int height = originalSize.height;
  int max = std::max(width, height);
  double ratio = 128.0/max;
  Size size(128, 128);
  // if(ratio>1) { //enlarge
  //   resize(imOrig, imResized, Size(), ratio, ratio,  CV_INTER_CUBIC);
  // }
  // else {//shrink
  //   resize(imOrig, imResized, Size(), ratio, ratio,  CV_INTER_AREA);
  // }
  // Just gonna do resize 128 x 128 for now 
  resize(imOrig, imResized, size);

  imwrite("resized"+filename, imResized);
  return 0;
}
