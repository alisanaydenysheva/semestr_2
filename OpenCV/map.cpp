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

using namespace cv;
using namespace std;

void my_mouse_callback(int event, int x, int y, int flags, void* param);
void reading(string Filename, string imagename, double wl, double hl, double wr, double hr);
void file();

int main(int argc, char** argv) {
	// устанавливаем русскую локализацию для консоли
	setlocale(LC_ALL, "Russian");
	//file();

	const char* imagename = "Screenshot_1.png";
	const char* traectory_file = "coordinat.txt";
	double wl = 40.76037518622534;
	double hl = -73.97920428221069;
	double wr = 40.75762878179911;
	double hr = -73.97475857062399;

	string check;
	cout << "read or enter" << endl;
	cin >> check;
	if (check == "read") {
		reading("coordinat.txt", "Screenshot_1.png", wl, hl, wr, hr);
	}
	else if (check == "enter") {
		Mat image = imread("Screenshot_1.png");
		namedWindow("modernGoogle");
		setMouseCallback("modernGoogle", my_mouse_callback, &image);
		while (true) {
			imshow("modernGoogle", image);
			waitKey(30);
		}
	}
	else {
		cout << "Ошибка ввода" << endl;
		waitKey(30);
	}
	return(0);
}

void file()
{
	ofstream file;
	file.open("test.txt", ios_base::app);
	unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
	file << milliseconds_since_epoch << endl;
	file.close();
	Mat image = imread("Screenshot_1.png");
	namedWindow("modernGoogle");
	setMouseCallback("modernGoogle", my_mouse_callback, &image);
	while (true) {
		imshow("modernGoogle", image);
		waitKey(30);
	}
}

void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		Mat* pImage = (Mat*)param;
		Mat image = *pImage;
		Point trackBox;
		trackBox = Point(x, y);


		ellipse(image, Point(x, y), Size(10, 2), -10, 20, 100, Scalar(255), 40, 8, 0);

		//circle(image, Point(x, y), 5, Scalar(255, 0, 0), FILLED, 8, 0);

		ofstream file;
		file.open("coordinat.txt", ios_base::app);
		unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
		file << milliseconds_since_epoch << " " << x << " " << y << endl;
		file.close();
	}
}

void reading(string Filename, string imagename, double wl, double hl, double wr, double hr)
{
	string File = Filename;
	int x, y, xm, ym;
	unsigned long t, tt;
	long double shirota, dolgota;

	ifstream f(File);
	if (!(f.is_open()))  cout << "Ошибка открытия файла" << File;
	else
	{
		Mat img = imread(imagename);
		cout << "Размер изображения: " << endl;
		cout << "Ширина: " << img.size().width << endl;
		cout << "Высота: " << img.size().height << endl;
		//вычисляем коэффициент масштабирования
		long double koef_mashtabW, koef_mashtabH;
		koef_mashtabW = (wl - wr) / img.size().width;
		koef_mashtabH = (hr - hl) / img.size().height;
		cout << koef_mashtabW << koef_mashtabH << endl;

		f >> t >> x >> y;

		cout << "Ваш путь пролегает по следующему  маршруту: " << endl;
		while (!f.eof())
		{
			f >> tt >> xm >> ym;

			shirota = koef_mashtabW * (img.size().width - x) + wr;
			dolgota = koef_mashtabH * (img.size().height - y) + hl;
			cout << "Метка времени: " << t << " широта: " << shirota << " долгота: " << dolgota << endl;

			ellipse(img, Point(x, y), Size(10, 2), -10, 20, 100, Scalar(255), 40, 8, 0);

			x = xm;
			y = ym;
			imshow("route", img);
			waitKey(tt - t);
			t = tt;
		}
	}
	f.close();
	cout << endl;
}
