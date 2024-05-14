#include <Windows.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat m = cv::Mat::zeros(cv::Size(2, 2), CV_64F);
	std::cout << "zeros;\n" <<m << std::endl;

    cv::Mat v = cv::Mat::ones(cv::Size(2, 2), CV_16F);
	std::cout << "ones;\n" <<v << std::endl;

    cv::Mat p = cv::Mat::eye(cv::Size(2, 2), CV_16F);
	std::cout << "eye;\n" <<p << std::endl;

	Sleep(2000);
}

/*
zeros;
[0, 0;
 0, 0]
ones;
[1, 1;
 1, 1]
eye;
[1, 0;
 0, 1]
*/