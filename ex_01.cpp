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

    // HSV��H�i�F���j�CS�i�ʓx�j:0?100%�CV�i���x�j:0?100%
	cv::cvtColor(I, hsv, cv::COLOR_BGR2HSV); // BGR --> HSV
	//cv::namedWindow("hsv");
	//cv::imshow("hsv", hsv);

    // �摜�̃`�����l�������擾
    int channels = gray.channels();
    // �`�����l�������o��
    std::cout << "�摜�̃`�����l����: " << channels << std::endl;

    I.convertTo(half_I, -1, 0.5, 0);
    cv::cvtColor(I, half_hsv, cv::COLOR_BGR2HSV); // BGR --> HSV/2
	cv::namedWindow("hsv");
	cv::imshow("hsv", hsv);

    // ���̉摜��H�̒l���r
    for (int i = 0; i < I.rows; i++) {
        for (int j = 0; j < I.cols; j++) {
            int h_original = hsv.at<cv::Vec3b>(i, j)[0];
            int h_half_intensity = half_hsv.at<cv::Vec3b>(i, j)[0];

            // H�̒l�̍����v�Z
            int diff = std::abs(h_original - h_half_intensity);

            // H�̒l���قڕω����Ȃ����Ƃ��m�F
            if (diff > 5) {
                std::cout << "H�̒l���傫���ω����܂����B" << std::endl;
                return -1;
            } 
        }
    }

	cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
HSV�F��Ԃɂ����āAH�̓J���[����\���AS��V�͂��ꂼ��ʓx�Ɩ��x��\���܂��B
BGR�̉�f�l���ꗥ�ɔ����ɂ���ƁA���x�iV�j�͕ω����܂����A�F���iH�j�ƍʓx�iS�j�͕ω����܂���B
����́ABGR�̊e�`�����l���̒l�𓯂������ŕω������Ă��A�F�̎�ށi�F���j�ƐF�̑N�₩���i�ʓx�j�͈ێ�����邽�߂ł��B
����A���x�͑S�̓I�Ȗ��邳��\�����߁ABGR�̒l�𔼕��ɂ���Ɩ��x�͉�����܂��B
*/