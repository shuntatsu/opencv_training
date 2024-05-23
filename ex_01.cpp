#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat I = cv::imread("opencv/Frog.jpg");
	cv::Mat gray, hsv, half_I, half_hsv;
	
	//cv::namedWindow("original");
	//cv::imshow("original", I);

	cv::cvtColor(I, gray, cv::COLOR_BGR2GRAY); // BGR --> GRAY
	//cv::namedWindow("gray");
	//cv::imshow("gray", gray);

    // HSVはH（色相），S（彩度）:0?100%，V（明度）:0?100%
	cv::cvtColor(I, hsv, cv::COLOR_BGR2HSV); // BGR --> HSV
	//cv::namedWindow("hsv");
	//cv::imshow("hsv", hsv);

    // 画像のチャンネル数を取得
    int channels = gray.channels();
    // チャンネル数を出力
    std::cout << "画像のチャンネル数: " << channels << std::endl;

    I.convertTo(half_I, -1, 0.5, 0);
    cv::cvtColor(I, half_hsv, cv::COLOR_BGR2HSV); // BGR --> HSV/2
	cv::namedWindow("hsv");
	cv::imshow("hsv", hsv);

    // 元の画像とHの値を比較
    for (int i = 0; i < I.rows; i++) {
        for (int j = 0; j < I.cols; j++) {
            int h_original = hsv.at<cv::Vec3b>(i, j)[0];
            int h_half_intensity = half_hsv.at<cv::Vec3b>(i, j)[0];

            // Hの値の差を計算
            int diff = std::abs(h_original - h_half_intensity);

            // Hの値がほぼ変化しないことを確認
            if (diff > 5) {
                std::cout << "Hの値が大きく変化しました。" << std::endl;
                return -1;
            } 
        }
    }

	cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
HSV色空間において、Hはカラー情報を表し、SとVはそれぞれ彩度と明度を表します。
BGRの画素値を一律に半分にすると、明度（V）は変化しますが、色相（H）と彩度（S）は変化しません。
これは、BGRの各チャンネルの値を同じ割合で変化させても、色の種類（色相）と色の鮮やかさ（彩度）は維持されるためです。
一方、明度は全体的な明るさを表すため、BGRの値を半分にすると明度は下がります。
*/