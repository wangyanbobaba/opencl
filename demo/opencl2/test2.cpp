#include <opencv2/core/ocl.hpp>
#include <opencv2/opencv.hpp>
// #include "opencv2/highgui.hpp"
#include<stdio.h>
#include<time.h>
#include<unistd.h>
 
#include<iostream>
using namespace std;
using namespace cv;
int main(int argc,char **argv)
{
    cv::UMat srcImage(3840, 2160, CV_8UC3, Scalar(0, 0, 255));
    cv::UMat dstImage;
    ocl::setUseOpenCL(true);
    bool Is_have_opencl=ocl::haveOpenCL();
    printf("Is_have_opencl:%d\n",Is_have_opencl);
     
    double time_total=0;
    double time_ave=0;
    double time_cost=0;
    int loop_times=10;
   if(2 > argc)
      printf("Error./test_opencv_gpu 1.jpg 10");
    else{
    std::string loop_no=argv[1];
    loop_times=stoi(loop_no);}
   
    int start= 0,endl=0;

    //dstImage.copyTo(udstImage); 
    while(true)
    {
        GaussianBlur(srcImage,dstImage,Size(23,23),0,0);
	medianBlur(dstImage, dstImage, 5);
    }
    
}
