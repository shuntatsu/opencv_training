#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat I = cv::Mat(cv::Size(128, 128), CV_8UC3, cv::Scalar(0,0,0));
	cv::namedWindow("image"); 

	cv::imshow("image", I);  // 変更前
	cv::waitKey(0); 

	// データが連続的に格納されているかどうか
	if (!I.isContinuous()){
		// 連続的でなければこれ以降のコードは正常動作しないので終了
		std::cout << "Not continuous data" << std::endl;
		return -1;
	}

	for (int iy = 0; iy < I.rows; iy++){
		for (int ix = 0; ix < I.cols; ix++){
			if (iy - ix > 0){
				((unsigned char *)I.data)[iy*I.step + ix * 3] = 255; // channel 0
				((unsigned char *)I.data)[iy*I.step + ix * 3 + 1] = 255; // channel 1
				((unsigned char *)I.data)[iy*I.step + ix * 3 + 2] = 255; // channel 2
			}
		}
	}

	cv::imshow("image", I); // 変更後
	cv::waitKey(0);

	cv::destroyWindow("image");
}

/*
cv::Matのデータ構造
cv::Matは、画像や行列データを格納するための基本的なデータ構造です。
データポインタ (data): 実際のピクセルデータが格納されているメモリブロックへのポインタ。
ステップ (step): 各行のデータが占めるバイト数。行の終端にパディングがある場合も含む。
行数 (rows)と列数 (cols): 行列のサイズ。
チャンネル数 (channels): 画像の色チャンネル数（例：グレースケールは1、カラーは3）。
*/