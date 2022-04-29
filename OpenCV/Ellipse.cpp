#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <string>
#include <cstring>
using namespace std;
using namespace cv;
Mat image() {
	Mat Image = imread("maxresdefault.jpg");
	//imshow("Исходное изображение", Image);
	return Image;
}
void file(char* dt)
{
	ofstream file;
	file.open("test.txt", ios_base::app);
	unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
	file << milliseconds_since_epoch << " = " << dt << endl;
	file.close();
}
void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		vector<Vec6d> ellipses;
		Mat* pImage = (Mat*)param;
		Mat image = *pImage;
		//circle(image, Point(x, y), 5, Scalar(255, 0, 0), FILLED, 8, 0);
		/*Size axes((int)ellipses[1][2] + (int)ellipses[1][3], (int)ellipses[1][2] + (int)ellipses[1][4]);
		double angle(ellipses[1][5]);
		Scalar color = ellipses[1][2] == 0 ? Scalar(255, 255, 0) : Scalar(0, 255, 0);*/
		//ellipse(image, Point(x, y), (100, 50), 0, 0, 360, Scalar(255, 0, 0), 2, LINE_AA);
		//cv2.ellipse(img, (256, 256), (100, 50), 0, 0, 180, 255, -1)
		ellipse(image, Point(x, y),
			Size(10, 10), 0, 0,
			360, Scalar(0, 255, 255),
			-1, LINE_AA);
	}
}
char* data() {
	// current date/time based on current system
	time_t now = time(0);
	// convert now to string form
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	return dt;
}

int main() {
	char* dt = data();
	file(dt);
	cout << "The local date and time is: " << endl;
	Mat mg = image();
	//my_mouse_callback();
	namedWindow("Кликанье мыши");
	setMouseCallback("Кликанье мыши", my_mouse_callback, &mg);
	while (true)
	{
		imshow("Кликанье мыши", mg);
			waitKey(30);
	}
	//waitKey(0);
	return 0;
}
