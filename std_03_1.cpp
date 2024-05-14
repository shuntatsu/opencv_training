#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>
#include <thread> // for std::this_thread::sleep_for
#include <chrono> // for std::chrono::seconds

int main() {
    // 3x3の行列を作成し、各要素を0で初期化
    cv::Mat m = cv::Mat::zeros(3, 3, CV_64F);

    // 各要素にi*jの値を設定
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            m.at<double>(i, j) = i * j;
        }
    }

    // 行列を表示
    std::cout << "Matrix m:\n" << m << std::endl;

    // 2秒間待機
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}

/*
Matrix m:
[0, 0, 0;
 0, 1, 2;
 0, 2, 4]
 */