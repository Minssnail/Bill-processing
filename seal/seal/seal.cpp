/*
功能：得到红色签章
*/
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;



int main()
{

	Mat src = imread("seal.jpg");
	//resize(src, src, Size(700, 500));
	Mat gray;
	cvtColor(src, gray, CV_RGB2GRAY);
	if (src.empty())
	{
		printf("fail to open image!\n");
		return -1;
	}

	// 全局二值化
	int th = 180; //阈值要根据实际情况调整
	Mat binary;
	threshold(gray, binary, th, 255, CV_THRESH_BINARY);


	vector<Mat> channels;
	split(src, channels);
	Mat red = channels[2];
	Mat blue = channels[0];
	Mat green = channels[1];
	
	Mat red_binary;//分割红色通道并二值化的图像
	threshold(red, red_binary, th, 255, CV_THRESH_BINARY);


	Mat outputImage;
	channels[0]=0;
	channels[1]=0;
	merge(channels, outputImage);

	imshow("src", src);
	imshow("outputImage", outputImage);
	//imshow("gray", gray);
	//imshow("binary", binary);
	imshow("red channel", red);
	imshow("blue channel", blue);
	imshow("green channel", green);
	//imshow("red+binary", red_binary);

	waitKey();


	return 0;
}
