# Stitching Image
This is a small C++ script that uses the OpenCV library to perform image stitching on Ubuntu.
# Installation
- [CMake]
```
sudo apt-get install cmake
```
- [OpenCV]
```
sudo apt install libopencv-dev
```
# Using Docker
```
cd Stitch_Image_OpenCV/docker
docker build -f Dockerfile -t stitching_image ..
docker run -it stitching_image
```
# Usage
```
cd Stitch_Image_OpenCV
mkdir build
cd build
cmake ..
make -j10
./ProcessImage path_to_your_folder
```
# Output
The image after stitching will be saved at Stitch_Image_OpenCV/result.jpg

**Thank you for accessing my repository. I wish you success.**