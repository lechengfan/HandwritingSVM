
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

  if( argc != 3)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay n" << endl;
     return -1;
    }
	ostringstream strm;

    Mat imGray, result;
    imGray = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
    
    if(! imGray.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	int n = strtol(argv[2], NULL, 0);
	string name = argv[1];
	for (int i = 0; i < n; i++) {
		Mat noise = Mat(imGray.size(),CV_64F);
		normalize(imGray, result, 0.0, 1.0, CV_MINMAX, CV_64F);
		randn(noise, 0, 0.05);
		result = result + noise;
		normalize(result, result, 0.0, 1.0, CV_MINMAX, CV_64F);
		//namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
		//imshow("OUTPUT",result);

		//waitKey(0);                                          // Wait for a keystroke
		//   in the window
		result.convertTo(result, CV_8UC3, 255.0);
		strm.str("");
		strm << i;
		imwrite(strm.str() + name, result);
	}
    return 0;
}
