#include<iostream>
using namespace std;
class matrix {
public:
	int x11, x12;
	int x21, x22;
	matrix(int tmp_x11, int tmp_x12, int tmp_x21, int tmp_x22) {
		this->x11 = tmp_x11;
		this->x12 = tmp_x12;
		this->x21 = tmp_x21;
		this->x22 = tmp_x22;
	}
	matrix() {
		this->x11 = 1;
		this->x12 = 0;
		this->x21 = 0;
		this->x22 = 1;
	}
	matrix operator *(const matrix b) {
		int tmp_x11 = this->x11*b.x11 + this->x12*b.x21;
		int tmp_x12 = this->x11*b.x12 + this->x12*b.x22;
		int tmp_x21 = this->x21*b.x11 + this->x22*b.x12;
		int tmp_x22 = this->x21*b.x12 + this->x22*b.x22;
		return matrix(tmp_x11, tmp_x12, tmp_x21, tmp_x22);
	}
	void print() {
		cout << x11 << "   " << x12 << endl;
		cout << x21 << "   " << x22;
	}
};


int main() {
	matrix x(0, 1, 1, 1);
	int a1 = 1, a2 = 1;
	int n = 20;
	n = n - 2;
	matrix b;
	while (n > 0) {
		if (n & 1) {
			b = b*x;
		}
		x = x*x;
		n=n >> 1;
	}
	
	cout << b.x21*a1 + b.x22*a2;


	system("pause");
	return 0;
}