#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>
#include <Windows.h>

int main(){
	cv::Mat gray = cv::imread("opencv/Frog.jpg", 0); // グレイスケール画像として読み込み
	cv::Mat binary;
	int M0, Mx, My; // 0次, 1次モーメント
	double CMx, CMy; // 画像重心位置
    double nFreq;  // 利用する型がQuery Perfomance Counterとは異なる点に注意
	int64 nBefore, nAfter; 
	double time;

	cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY); // 画素値100を閾値として二値化

	cv::namedWindow("binary");
	cv::imshow("binary", binary);

    nFreq = cv::getTickFrequency();// CPUクロック周波数取得
	nBefore = cv::getTickCount();// 現時点のクロック数取得
	M0 = Mx = My = 0;
	for (int iy = 0; iy < binary.rows; iy++){
		unsigned char* ptr = binary.ptr<unsigned char>(iy);
		for (int ix = 0; ix < binary.cols; ix++){
			if (ptr[ix] == 0){
				M0++;
				Mx += ix;
				My += iy;
			}
		}
	}
	CMx = (double)Mx / M0;
	CMy = (double)My / M0;
    nAfter = cv::getTickCount();// 現時点のクロック数取得

    time = (double)(nAfter - nBefore)*1000.0 / nFreq;
	std::cout << "threshold処理時間:" << time << " ms" << std::endl;

	std::cout << "Center of Mass:(" << CMx << "," << CMy << ")" << std::endl;

	cv::line(gray, cv::Point(CMx - 20, CMy), cv::Point(CMx + 20, CMy), 0, 3);
	cv::line(gray, cv::Point(CMx, CMy - 20), cv::Point(CMx, CMy + 20), 0, 3);

	cv::namedWindow("DetectedCOM");
	cv::imshow("DetectedCOM", gray);

	cv::waitKey(0);
	cv::destroyAllWindows();
}