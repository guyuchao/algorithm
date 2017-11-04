#include <GL/glut.h>  
#include<iostream>
#include"POLYGEN.h"
#include"AETNET.h"
using namespace std;
#include<map>
#include<set>
#include<vector>
#define WIDTH 400
#define HEIGHT 400

/*global*/
unsigned char* pixels;



void draw_pixel(int x, int y) {
	int pianyi = 200;
	x = x + pianyi;
	y = y + pianyi;
	int index = y*WIDTH + x;
	pixels[index * 3 + 0] = 255;
	pixels[index * 3 + 1] = 0;
	pixels[index * 3 + 2] = 0;
}

void draw_line(int x1, int x2, int y) {
	for (int i = x1; i <= x2; i++) {
		draw_pixel(i, y);
	}
}

void polyfill(polygon p) {
	NET net(p);
	AET aet;

	int miny = p.min_y;
	int maxy = p.max_y;

	for (int i = miny; i <= maxy; i++) {
		if (net.New_Edge_T.count(i) != 0) {
			for (auto j : net.New_Edge_T[i]) {
				aet.insert(j);
			}
		}
		int tmp_x_left = 0;
		int tmp_x_right = 0;
		for (auto j : aet.AET_EDGE_T) {
			if (tmp_x_left == 0) {
				tmp_x_left = j.x_min;
			}
			else if (tmp_x_right == 0) {
				tmp_x_right = j.x_min;
				draw_line(tmp_x_left, tmp_x_right, i);
				tmp_x_left = tmp_x_right = 0;
			}
		}
		AET tmp_aet;
		for (auto j : aet.AET_EDGE_T) {
			if (j.y_max > i) {
				ET_NODE tmp_node = j;
				tmp_node.x_min += tmp_node.delta_x;
				tmp_aet.insert(tmp_node);
			}
		}
		aet = tmp_aet;
	}
}
void mydraw() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(WIDTH ,HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}


int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);//
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("�����ɨ��ת��");
	pixels = new unsigned char[WIDTH*HEIGHT * 3];
	polyfill(polygon());
	glutDisplayFunc(&mydraw);
	glutMainLoop();
	system("pause");
	return 0;
}