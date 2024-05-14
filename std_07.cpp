#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat I = cv::Mat(cv::Size(128, 128), CV_8UC3, cv::Scalar(0,0,0));
	cv::namedWindow("image"); 

	// unsigned charでアクセス
	for (int iy = 0; iy < I.rows; iy++){
		unsigned char *ptr = I.ptr<unsigned char>(iy);
		for (int ix = 0; ix < I.cols; ix++){
			if (iy - ix > 0){
				ptr[3 * ix + 0] = 255;
				ptr[3 * ix + 1] = 255;
				ptr[3 * ix + 2] = 128;
			}
		}
	}
	cv::imshow("image", I);  // unsigned charによる描画
	cv::waitKey(0); 

	// cv::Vec3bでアクセス
	for (int iy = 0; iy < I.rows; iy++){
		cv::Vec3b *ptr = I.ptr<cv::Vec3b>(iy);
		for (int ix = 0; ix < I.cols; ix++){
			if (iy + ix - 128 > 0){
				ptr[ix] = cv::Vec3b(255, 128, 255);
			}
			else{
				ptr[ix] = cv::Vec3b(0, 0, 0);
			}
		}
	}
	cv::imshow("image", I); // cv::Vec3bによる描画
	cv::waitKey(0);

	cv::destroyWindow("image");
}

/*
unsigned char *ptr = I.ptr<unsigned char>(iy);:
-各ピクセルの各チャンネルに直接アクセスするために使用します。
-8ビットの画像データに適しています。
-各ピクセルの各チャンネルを個別に操作できる。。
cv::Vec3b *ptr = I.ptr<cv::Vec3b>(iy);:
-各ピクセルをcv::Vec3b（3つのunsigned charからなるベクトル）として扱います。
-カラー画像（BGR形式）に適しています。
-各ピクセル全体を一度に操作できる。

ptrは「pointer」の略
*/