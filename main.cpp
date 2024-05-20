#include <iostream>
#include <fstream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
using namespace cv;

class StitcherImages{
    public:
        StitcherImages(std::string folderPath_) {
            folderPath = folderPath_;
            stitcher = Stitcher::create(mode);

            for (const auto & entry : fs::directory_iterator(folderPath)){
                std::string imagePath = entry.path();
                cv::Mat image = readImage(imagePath);
                images.push_back(image);
            }
        }

        cv::Mat readImage(std::string &path){
            cv::Mat image = imread(path);
            return image;
        }

        Stitcher::Status stitchImages(cv::Mat &stitchedImage){
            Stitcher::Status status = stitcher->stitch(images, stitchedImage);
            if (status != Stitcher::OK)
            {
                cout << "Can't stitch images\n";
                exit(0);
            }
            return status;
        }

        void saveImage(const std::string &savePath, cv::Mat &image){
            imwrite(savePath, image);
        }

    private:
        Ptr<Stitcher> stitcher;
        vector<cv::Mat> images;
        std::string folderPath;
        Stitcher::Mode mode = Stitcher::PANORAMA;
};

int main(int argc, char* argv[])
{
    std::string folder = argv[1];
    StitcherImages stitcher(folder);
     
    Mat stitchedImage;
    stitcher.stitchImages(stitchedImage);

    const std::string savedPath =  "../result.jpg";
    stitcher.saveImage(savedPath, stitchedImage);

    return 0;
}