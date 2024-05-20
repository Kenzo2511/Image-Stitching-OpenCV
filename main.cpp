#include <iostream>
#include <fstream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
using namespace cv;
Stitcher::Mode mode = Stitcher::PANORAMA;

cv::Mat readImage(std::string &path){
    cv::Mat image = imread(path);
    return image;
}

Stitcher::Status stitchImages(vector<cv::Mat> &images, Ptr<Stitcher> &stitcher, cv::Mat &pano){
    Stitcher::Status status = stitcher->stitch(images, pano);
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images\n";
        exit(0);
    }
    return status;
}

std::vector<std::string> getImagePathsFromFolder(const std::string &folderPath){
    std::vector<std::string> imagePaths;
    for (const auto & entry : fs::directory_iterator(folderPath)){
        std::string path = entry.path();
        imagePaths.push_back(path);
    }
    return imagePaths;

}

void saveImage(const std::string &savePath, cv::Mat &image){
    imwrite(savePath, image);
}
 
int main(int argc, char* argv[])
{
    vector<Mat> images;
    const std::string folderPath = argv[1];
    std::vector<std::string> imagePaths = getImagePathsFromFolder(folderPath);
    for (auto &imagePath:imagePaths)
    {
        cv::Mat image = readImage(imagePath);
        images.push_back(image);
    }
     
    Mat stitchedImage;
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitchImages(images, stitcher, stitchedImage);

    const std::string path =  "../result.jpg";
    saveImage( path, stitchedImage);
    imshow("Window Name", stitchedImage); 

    waitKey(0);
    return 0;
}