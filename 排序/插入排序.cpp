#include<iostream>
using namespace std;
void insert_sort(int * a,int len) {
	for (int i = 2; i < len; i++) {
		a[0] = a[i];
		int j=i-1;
		while (a[j] > a[0]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = a[0];
	}
}
int main() {
	int a[11] = {0,4,3,2,5,6,1,7,0,9,8 };
	insert_sort(a,11);
	for (int i = 1; i < 11; i++) {
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}