#include <Windows.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	// 8bit 1チャンネルの行列
	cv::Mat A = cv::Mat::eye(cv::Size(2, 2), CV_8UC1);
	// 8bit 2チャンネルの行列
	cv::Mat B = cv::Mat::eye(cv::Size(2, 2), CV_8UC2);
	// 8bit 3チャンネルの行列
	cv::Mat C = cv::Mat::eye(cv::Size(2, 2), CV_8UC3);


	std::cout << "1 channel:" << std::endl << A << std::endl << std::endl;
	std::cout << "2 channel:" << std::endl << B << std::endl << std::endl;
	std::cout << "3 channel:" << std::endl << C << std::endl << std::endl;


	Sleep(2000);
}