#include <Windows.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	cv::Mat m = cv::Mat::zeros(cv::Size(2, 2), CV_64F);

	std::cout << m << std::endl;

	Sleep(2000);
}

/*
cv::Mat::zeros 関数を使って、2x2の行列 m を作成し、全ての要素を0で初期化。CV_64F は、行列の要素が倍精度浮動小数点数（double型）.

cv::Mat mat = cv::Mat::zeros(rows, cols, type);
rows: 作成する行列の行数
cols: 作成する行列の列数
type: 作成する行列の要素の型。
    例えば、CV_8UC1 (8ビット符号なし整数・1チャンネル)
         , CV_32FC3 (32ビット浮動小数点数・3チャンネル)

行列の要素を1で初期化: cv::Mat::ones(rows, cols, type)
単位行列を作成: cv::Mat::eye(rows, cols, type)
指定した定数で初期化: cv::Mat(rows, cols, type, cv::Scalar(value))
    ---
    cv::Mat mat(2, 2, CV_8UC3, cv::Scalar(0, 255, 255)); 
    ---
    [0, 255, 255, 0, 255, 255;
     0, 255, 255, 0, 255, 255]\
    2x2の8ビット符号なし整数型3チャンネル(CV_8UC3)の行列を作成し、全ての要素を(B, G, R) = (0, 255, 255)の色で初期化
乱数で初期化: cv::randu(mat, low, high), cv::randn(mat, mean, stddev)
    ---
    cv::Mat mat(3, 3, CV_8UC1);
    cv::randu(mat, cv::Scalar::all(0), cv::Scalar::all(255));
    std::cout << "mat (randu):\n" << mat << std::endl;

    cv::randn(mat, cv::Scalar::all(128), cv::Scalar::all(10));  
    std::cout << "mat (randn):\n" << mat << std::endl;
    ---
    mat (randu):
    [123, 234, 53;
     192, 103, 5;
     28, 6, 210]

    mat (randn):
    [132, 130, 127;
     125, 135, 123;
     131, 126, 133]\
    cv::randu は、指定された範囲(ここでは0から255)の一様分布乱数で行列を初期化。


    cv::randn は、指定された平均(ここでは128)と標準偏差(ここでは10)の正規分布乱数で行列を初期化。
*/