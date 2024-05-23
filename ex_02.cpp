#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat gray = cv::imread("opencv/Frog.jpg", 0); // グレイスケール画像として読み込み
	cv::Mat binary;
	
	cv::namedWindow("original");
	cv::imshow("original", gray);

    // threshold:しきい値,画素値の範囲を2つのグループに分割するための境界値を指します。
	cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY); // 画素値100を閾値として二値化

	cv::namedWindow("binary");
	cv::imshow("binary", binary);

    cv::Mat image = cv::imread("opencv/Frog.jpg");
    // HSV色空間に変換
    cv::Mat hsv;
    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);

    // Hmin, Hmaxの初期値を設定
    int hmin = 0, hmax = 255;

    // Hmin, Hmaxを調整するためのトラックバーを作成
    cv::namedWindow("Binary Image");
    cv::createTrackbar("Hmin", "Binary Image", &hmin, 255);
    cv::createTrackbar("Hmax", "Binary Image", &hmax, 255);

    while (true) {
        // 二値化された画像を格納する行列を作成
        cv::Mat binary;

        // Hチャンネルを抽出
        std::vector<cv::Mat> hsv_channels;
        cv::split(hsv, hsv_channels);
        cv::Mat h = hsv_channels[0];

        // Hの値に基づいて二値化
        cv::inRange(h, cv::Scalar(hmin), cv::Scalar(hmax), binary);

        // 結果を表示
        cv::imshow("Original Image", image);
        cv::imshow("Binary Image", binary);

        // 'q'キーが押されたら終了
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

	cv::waitKey(0);
	cv::destroyAllWindows();
}