
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

  if( argc != 2 )
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }
	ostringstream strm;

    Mat imGray, inverted, result;
    imGray = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
    
    if(! imGray.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	string name = argv[1];
	// normalize(imGray, imGray, 0.0, 1.0, CV_MINMAX, CV_64F);
	//Black pixels become white; white turns to black
	inverted = cv::Scalar::all(255) - imGray;
	Moments mu = moments(inverted, false);
	double x_center = mu.m10/mu.m00;
	double y_center = mu.m01/mu.m00;
	cout << "X center " << x_center << endl;
	cout << "Y center " << y_center << endl;

	float translate[2][3] = {{1, 0, 64-x_center}, {0,1,64-y_center}};
	Mat translateMat = Mat(2,3, CV_32FC1, &translate);
	warpAffine(imGray, result, translateMat, Size(128,128));
	normalize(result, result, 0.0, 1.0, CV_MINMAX, CV_64F);
	//namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
	//imshow("OUTPUT",result);

	//waitKey(0);
	result.convertTo(result, CV_8UC3, 255.0);
	// strm.str("");
	// strm << i;
	name = name.substr(0, name.rfind("."));
	imwrite(name+"_centered.png", result);
    return 0;
}
