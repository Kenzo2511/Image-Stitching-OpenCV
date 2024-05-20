#include <iostream>
#include <fstream>
 
// Include header files from OpenCV directory
// required to stitch images.
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
 
using namespace std;
using namespace cv;
 
// Define mode for stitching as panorama 
// (One out of many functions of Stitcher)
Stitcher::Mode mode = Stitcher::PANORAMA;
 
// Array for pictures
vector<Mat> imgs;
 
int main(int argc, char* argv[])
{
    std::cout<<"Hello OpenCV"<<std::endl;
}