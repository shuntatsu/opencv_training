#include <Windows.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat gray = cv::imread("opencv/Frog.jpg", 0); // グレイスケール画像として読み込み
	cv::Mat binary;
	double nFreq;  // 利用する型がQuery Perfomance Counterとは異なる点に注意
	int64 nBefore, nAfter; 
	double time, nTime[100];
    nTime[0] = 0;

    for(int i = 0; i<100; i++){
	    nFreq = cv::getTickFrequency();// CPUクロック周波数取得
	    nBefore = cv::getTickCount();// 現時点のクロック数取得
	    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY); // 画素値100を閾値として二値化
	    nAfter = cv::getTickCount();// 現時点のクロック数取得
	    nTime[i] = nAfter - nBefore;
        nTime[0] += nTime[i];
    }
    
	time = (double) nTime[0]*1000.0 / nFreq / 100;
	std::cout << "avg-threshold処理時間:" << time << " ms" << std::endl;
	Sleep(1000);
}