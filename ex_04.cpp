#include <Windows.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat gray = cv::imread("opencv/Frog.jpg", 0); // グレイスケール画像として読み込み
	cv::Mat binary;
	LARGE_INTEGER nFreq, nBefore, nAfter;
	double time;

	QueryPerformanceFrequency(&nFreq); // CPUクロック周波数取得
	QueryPerformanceCounter(&nBefore); // 現時点のクロック数取得
	cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY); // 画素値100を閾値として二値化
	QueryPerformanceCounter(&nAfter); // 現時点のクロック数取得

	time = ((nAfter.QuadPart - nBefore.QuadPart) * 1000.0 / nFreq.QuadPart);
	std::cout << "threshold処理時間:" << time << " ms" << std::endl;
	Sleep(1000);
}