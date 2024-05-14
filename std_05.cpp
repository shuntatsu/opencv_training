#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/world.hpp>

int main(){
	// 適当な画像ファイルをカレントディレクトリに置き，その名前を指定する
	// カレントディレクトリはデフォルトだと以下の場所のはず
	// VisualStudioのprojectディレクトリ/プロジェクト名
	cv::Mat I = cv::imread("opencv/Frog.jpg"); // 画像ファイルを読み込む

	cv::namedWindow("image"); // 画像表示用のウィンドウを生成
	cv::imshow("image", I); // 生成したウィンドウに画像を表示 
	cv::waitKey(0); // 一定時間動作を停止する．引数に0を指定すると，キー入力があるまで無限に待つ
	cv::destroyWindow("image"); // 画像表示用ウィンドウを破棄
}
