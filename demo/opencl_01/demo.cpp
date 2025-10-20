#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
//#include <opencl.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/core/ocl.hpp>

#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libswscale/swscale.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    cv::ocl::setUseOpenCL(false);

    bool ret1 = cv::ocl::haveOpenCL();
    bool ret2 = cv::ocl::useOpenCL();
    std::cout<<"has cl:"<<ret1<<std::endl;
    std::cout<<"use cl:"<<ret2<<std::endl;

    // String url = "rtsp://admin:Aa123456@192.168.5.165:554";
    // cv::VideoCapture cap;
    // cap = cv::VideoCapture(url, cv::CAP_FFMPEG);

    // if(cap.isOpened())
    //     std::cout<<"stream open success"<<std::endl;
    // else
    //     std::cout<<"stream open failse"<<std::endl;

    // 修改成从本地摄像头读取
    cv::VideoCapture cap;
    cap.open("/dev/video33");  // 使用默认摄像头，通常设备索引为0

    if (cap.isOpened())
        std::cout << "Camera stream open success" << std::endl;
    else
        std::cout << "Camera stream open failed" << std::endl;

    cv::Mat frame; //= cv::imread("frame_140.png");
    cv::Mat result;
    cv::UMat gpu_frame;
    cv::UMat gpu_result;

    while(1) {
        auto start = std::chrono::high_resolution_clock::now();
        cap.read(gpu_frame);
        if(gpu_frame.empty()) {
            continue;
        }
        cv::resize(gpu_frame, gpu_result, cv::Size(640, 360), cv::INTER_LINEAR);

        cv::imwrite("output_cpp.png", gpu_result);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
        std::cout << "3read_duration seconds:" << duration << std::endl;
        //cv::imshow("ls", gpu_result);
    }
    cap.release();
    cv::ocl::setUseOpenCL(false);
    return 0;
}
