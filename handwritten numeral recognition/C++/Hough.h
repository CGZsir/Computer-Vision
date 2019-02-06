#pragma once
#include "CImg.h"
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <fstream>
#include <algorithm>

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

struct votePoint {
	Point p;
	int vote;
	votePoint(Point a, int b):p(a),vote(b) {

	}
};

class Hough {
private:
	CImg<uchar> img; //Original Image
	CImg<uchar> gFiltered;
	CImg<int> houghImage;  //Hough Space
	CImg<uchar> resultImg;
	vector<votePoint> peaks;
	//ֱ�ߵ㼯
	vector< pair< pair<int, int>, pair<int, int> > > lines;
	//�ĸ��ǵ�
	CImg<uchar> gradnum;
	vector<Point> circles;
	vector<Point> center;
	vector<int> circleWeight;
	string fileName;

	int theta = 180;
	double interval = M_PI / 180;
	int min_votes = 300;	//��СͶƱ��
	int min_distance = 500;		//��С����
	int DIFF = 10;
	int gradLimit = 6;
	int Red[3] = { 255, 0, 0 };

public:
	int width, height, max_length;
	vector<Point> points;	//����
	vector< pair<int, int > > vertex;


	Hough(string);
	void Prewitt();
	void houghSpaceTransform();	//����ռ�任
	double distance(double, double);
	void drawLines();		//Ѱ�Ҳ�����ֱ��
	void drawPoints();		//Ѱ�Ҳ���������
	void orderVertexs();	//����
};