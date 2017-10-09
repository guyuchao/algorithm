//¹é²¢ÅÅĞò
#include<iostream>
using namespace std;
void guibing(int* a, int begin, int end) {
	if ((end - begin) == 1) {
		if (a[begin] > a[end]) {
			int c = a[end];
			a[end] = a[begin];
			a[begin] = c;
		}
		return;
	}
	if (begin == end)return;
	int mid = (begin + end) / 2;
	guibing(a, begin, mid);
	guibing(a, mid + 1, end);
	int *tmp = new int[end - begin + 1];
	int cnt_tmp = -1;
	int i = begin, j = mid + 1;
	while (i <= mid&&j <= end) {
		if (a[i] < a[j]) {
			tmp[++cnt_tmp] = a[i];
			i++;
			
		}
		else {
			tmp[++cnt_tmp] = a[j];
			j++;
		}
	}
	if (i > mid) {
		while (j <= end) {
			tmp[++cnt_tmp] = a[j++];
		}
	}
	else {
		while (i <= mid) {
			tmp[++cnt_tmp] = a[i++];
		}
	}
	i = begin;
	j = 0;
	while (j <= cnt_tmp) {
		a[begin+j] = tmp[j++];
	}
	delete(tmp);
}
int main() {
	int a[10] = {
		8,1,3,4,0,6,7,2,5,9
	};
	guibing(a, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}