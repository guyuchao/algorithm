#include <GL/glut.h>  
#include<iostream>
#include<cmath>
using namespace std;

int width = 200;
int height = 200;

unsigned char* pixels;

void set_pixel(int x, int y) {
	int index = y*width + x;
	pixels[index * 3 + 0] = 255;
	pixels[index * 3 + 1] = 0;
	pixels[index * 3 + 2] = 0;
}


void DDL_init_x(int x1, int y1, int x2, int y2) {
	int index;
	double k = (y2 - y1) *1.0 / (x2 - x1);
	double now_y = y1;
	for (int x = x1; x <= x2; x++) {
		int y = int(now_y + 0.5);
		//cout << x << " " << y << endl;
		set_pixel(x, y);
		now_y += k;
	}

}
void DDL_init_y(int x1, int y1, int x2, int y2) {
	int index;
	double k = (x2 - x1) *1.0 / (y2 - y1);
	double now_x = x1;
	for (int y = y1; y <= y2; y++) {
		int x = int(now_x + 0.5);
		//cout << x << " " << y << endl;
		set_pixel(x, y);
		now_x += k;
	}
}
void DDL_init(int x1, int y1, int x2, int y2) {
	double k= (y2 - y1) *1.0 / (x2 - x1);
	if (fabs(k) <= 1) {
		if (x1 < x2) {
			DDL_init_x(x1, y1, x2, y2);
		}
		else {
			DDL_init_x(x2, y2, x1, y1);
		}
	}
	else {
		if (y1 < y2) {
			DDL_init_y(x1, y1, x2, y2);
		}
		else {
			DDL_init_y(x2, y2, x1, y1);
		}
	}
}
void mydraw() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}


int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);//
	glutInitWindowSize(width, height);
	glutCreateWindow("DDL画线");


	pixels = new unsigned char[width*height * 3];
	int x1, y1, x2, y2;
	cout << "请输入两个点坐标：  ";
	cin >> x1 >> y1 >> x2 >> y2;
	DDL_init(x1, y1, x2, y2);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}