#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat I = cv::Mat(cv::Size(256, 128), CV_8UC3, cv::Scalar(0,0,0));
	cv::namedWindow("image"); 

	// データが連続的に格納されているかどうか
	if (!I.isContinuous()){
		// 連続的でなければこれ以降のコードは正常動作しないので終了
		std::cout << "Not continuous data" << std::endl;
		return -1;
	}

	for (int iy = 0; iy < I.rows; iy++){
		for (int ix = 0; ix < I.cols; ix++){
			((unsigned char *)I.data)[iy*I.step + ix * 3] = 255; // channel 0
			((unsigned char *)I.data)[iy*I.step + ix * 3 + 1] = 255; // channel 1
			((unsigned char *)I.data)[iy*I.step + ix * 3 + 2] = 255; // channel 2
		}
	}

	cv::imshow("image", I); // 変更後
	cv::waitKey(0);

	cv::destroyWindow("image");
}