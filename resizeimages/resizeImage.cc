
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
  imOrig.convertTo(imOrig, CV_32F);
  Size originalSize = imOrig.size();
  // cout << imOrig << endl;
  int maxX=0, minX=originalSize.width, maxY = 0, minY=originalSize.height;
  for(int i=0; i<originalSize.width; i++) {
    for(int j=0; j<originalSize.height; j++) {
      float value = imOrig.at<float>(i,j);
      if(value<241) {
        maxX = max(maxX, i);
        minX = min(minX, i);
        maxY = max(maxY, j);
        minY = min(minY, j);
      }
    }
  }  
  

  int width = maxX-minX;
  int height = maxY-minY;
  float translate[2][3] = {{1, 0, 64-(maxX+minX)/2}, {0,1,64-(maxY+minY)/2}};
  Mat translateMat = Mat(2,3, CV_32FC1, &translate);
  warpAffine(imOrig, imResized, translateMat, Size(128,128));

  // int max = std::max(width, height);
  // double ratio = 128.0/max;
  // Size size(128, 128);
  // if(ratio>1) { //enlarge
  //   resize(imOrig, imResized, Size(), ratio, ratio,  CV_INTER_CUBIC);
  // }
  // else {//shrink
  //   resize(imOrig, imResized, Size(), ratio, ratio,  CV_INTER_AREA);
  // }
  // Just gonna do resize 128 x 128 for now 
  // resize(imOrig, imResized, size);

  imwrite("resized"+filename, imResized);
  return 0;
}
