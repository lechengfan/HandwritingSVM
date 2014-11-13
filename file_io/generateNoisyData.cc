#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <sstream> 
#include <stdlib.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
	if( argc != 4 )
    {
    	cout <<" Usage: ./generateNoise ImageToLoadAndDisplay howMany outputFileName" << endl;
    	return -1;
    }

    Mat imGray, result;
    imGray = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
    
    if(! imGray.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

	FileStorage fs(argv[3], FileStorage::APPEND); // Filestorage class for writing to files
	fs << "Filename" << argv[1];
	fs << "Data" << "[";
	int n = strtol(argv[2], NULL, 0);
	string name = argv[1];
	for (int i = 0; i < n; i++) {
		Mat noise = Mat(imGray.size(),CV_64F);
		normalize(imGray, result, 0.0, 1.0, CV_MINMAX, CV_64F);
		randn(noise, 0, 0.05);
		result = result + noise;
		normalize(result, result, 0.0, 1.0, CV_MINMAX, CV_64F);
		result.convertTo(result, CV_8UC3, 255.0);
		fs << result;
	}
	fs << "]";
	fs.release();

	return 0;
}
