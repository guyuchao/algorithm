#include <GL/glut.h>  
#include<iostream>
using namespace std;

int width = 200;
int height = 200;

unsigned char* pixels;



void DDL_init(int x1,int y1,int x2,int y2){
	int index;
	double k = (y2 - y1) *1.0/ (x2 - x1);
	double now_y = y1;
	for (int x = x1; x <= x2; x++) {
		int y = int(now_y + 0.5);
		//cout << x << " " << y << endl;
		index = y*width + x;
		pixels[index * 3 + 0] = 255;
		pixels[index * 3 + 1] = 0;
		pixels[index * 3 + 2] = 0;
		now_y += k;
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
	glutCreateWindow("DDL����");

	
	pixels = new unsigned char[width*height * 3];
	int x1, y1, x2, y2;
	cout << "���������������꣺  ";
	cin >> x1 >> y1 >> x2 >> y2;
	DDL_init(x1,y1,x2,y2);
	glutDisplayFunc(&mydraw);		
	
	glutMainLoop();
	return 0;
}