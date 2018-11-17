#pragma once
#include "CImg.h"
#include <string>
#include <vector>
#include <iostream>
#include <time.h>

using namespace cimg_library;
using namespace std;
typedef unsigned char uchar;

#define M_PI acos(-1.0)

struct Point {
	int x, y;
	Point(int a, int b) {
		x = a;
		y = b;
	}
};

struct Line {
	double k, b;
	Line(double x, double y) {
		k = x;
		b = y;
	}
};

class Hough {
private:
	CImg<uchar> img; //Original Image
	CImg<uchar> gFiltered;
	CImg<int> houghImage;  //Hough Space
	CImg<float> result;
	vector<Point> peaks;
	vector<Line> lines;
	vector<Point> points;	//����
	CImg<double> gradnum;
	vector<Point> circles;
	vector<Point> center;
	vector<int> circleWeight;
	int width, height, max_length;


	int theta = 360;
	double interval = M_PI / 180;
	int min_votes = 200;	//��СͶƱ��
	int min_distance = 200;		//��С����
	int gradLimit = 4;		//�ݶȷ�ֵ

	//Բ
	double minRadius = 200;
	int minR = 150, maxR = 300;
	int rLimit = 80;		//ɸѡ�뾶
	int voteLimit = 40;		//ɸѡԲ��

public:
	Hough(string);
	void sobel();	//Sobel filtering
	void Prewitt();
	void houghSpaceTransform();	//����ռ�任
	void houghLinesDetect();		//����ֱ�߼��
	double distance(double, double);
	void drawLines();		//Ѱ�Ҳ�����ֱ��
	void drawPoints();		//Ѱ�Ҳ���������
	void houghCircleTransform();	//����Բ�任
	void houghCirclesDetect();
	void drawCircle(int r);
};