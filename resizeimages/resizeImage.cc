
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
  
  Mat imOrig, imResized, inverted;
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
  int resize_width = maxX-minX;
  int resize_height = maxY-minY;
  Rect cropped(minY, minX, resize_height, resize_width);
  Mat croppedMat = imOrig(cropped);

  resize(croppedMat, imResized, Size(128,128), (float) originalSize.width/resize_width, (float) originalSize.height/resize_height,  CV_INTER_CUBIC);
  imwrite("resized"+filename, imResized);
  return 0;
}
