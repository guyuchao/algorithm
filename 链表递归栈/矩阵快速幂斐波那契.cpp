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

matrix quick_pow(matrix a,int times) {
	if (times == 1)return a;
	if (times % 2 == 0) {
		return quick_pow(a,times/2)*quick_pow(a, times / 2);
	}
	else {
		return quick_pow(a, (times-1) / 2)*quick_pow(a, (times-1) / 2)*a;
	}
}

int main() {
	matrix x(0, 1, 1, 1);
	int a1 = 1, a2 = 1;
	int n = 25;
	matrix b = quick_pow(x, n-2);
	cout << b.x21*a1 + b.x22*a2;

	system("pause");
	return 0;
}