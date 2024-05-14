#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat I = cv::Mat(cv::Size(128, 128), CV_8UC3, cv::Scalar(0,0,0));
	cv::namedWindow("image"); 

	cv::imshow("image", I);  // 変更前
	cv::waitKey(0); 

	for (int iy = 0; iy < I.rows; iy++){
		for (int ix = 0; ix < I.cols; ix++){
			if (  iy - ix > 0 )
				// at メソッドによるアクセス．
				// 処理速度が遅いので多くの画素にアクセスするのには向かない
				// つまりこのサンプルは悪い例
				I.at<cv::Vec3b>(iy, ix) = cv::Vec3b(255, 255, 255);
		}
	}

	cv::imshow("image", I); // 変更後
	cv::waitKey(0);

	cv::destroyWindow("image");
}

/*
atは「access at」の略
*/