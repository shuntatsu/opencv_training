#include <Windows.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

#define _USE_MATH_DEFINES   // math.hの定数(M_PI)を利用する
#include <math.h>

int main(){
	// PI/6の回転行列
	cv::Mat m = (cv::Mat_<double>(2, 2) << cos(M_PI/6), -sin(M_PI/6), sin(M_PI/6), cos(M_PI/6) );

	std::cout << m << std::endl;

	Sleep(2000);
}

/*
cv::Mat_<double>(2, 2) は、2行2列の double 型行列を作成します。Mat_ は Mat クラスのテンプレート版.
*/