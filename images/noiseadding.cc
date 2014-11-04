#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

  if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat imGray;
    imGray = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
    
    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    Mat noise = Mat(imGray.size(),CV_64F);
    normalize(imGray, result, 0.0, 1.0, CV_MINMAX, CV_64F);
    randn(noise, 0, 0.05);
    result = result + noise;
    normalize(result, result, 0.0, 1.0, CV_MINMAX, CV_64F);
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow("OUTPUT",result);

    waitKey(0);                                          // Wait for a keystroke
    //   in the window
    return 0;
}
