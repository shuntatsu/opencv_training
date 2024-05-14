#include <Windows.h>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
	std::cout << "hoge" << std::endl;

	Sleep(2000);
}

/*
std::cout は標準出力。std::endl は改行。
Sleep は Windows の機能で、プログラムの実行を2000ミリ秒(2秒)停止。
*/