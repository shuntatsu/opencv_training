#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main() {
    // 画像サイズを設定
    int width = 400;
    int height = 400;

    // 画像を黒で初期化
    cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);

    // 長方形を描画
    for (int y = 50; y < 250; y++) {
        uchar* ptr = image.ptr<uchar>(y);
        for (int x = 50; x < 150; x++) {
            ptr[3 * x + 0] = 255; // 青
            ptr[3 * x + 1] = 0;   // 緑
            ptr[3 * x + 2] = 0;   // 赤
        }
    }

    // 中抜きの四角を描画
    for (int y = 200; y < 300; y++) {
        uchar* ptr = image.ptr<uchar>(y);
        for (int x = 200; x < 300; x++) {
            if ((y >= 200 && y <= 224) || (x >= 200 && x <= 224)  || (y >= 275 && y <= 299) || (x >= 275 && x <= 299)) {
                ptr[3 * x + 0] = 0;   // 青
                ptr[3 * x + 1] = 255; // 緑
                ptr[3 * x + 2] = 0;   // 赤
            } else {
                ptr[3 * x + 0] = 255;   // 青
                ptr[3 * x + 1] = 0; // 緑
                ptr[3 * x + 2] = 255;   // 赤
            }
        }
    }

    // 画像を表示
    cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Image", image);
    cv::waitKey(0);

    return 0;
}