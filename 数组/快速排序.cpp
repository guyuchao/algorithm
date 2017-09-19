//¿ìÅÅ
#include<iostream>
#include<algorithm>
using namespace std;
void qsortt(int begin, int end, int *num){
	if (begin >= end)return;
	int i = begin;
	int j = end;
	int tmp = num[i];
	while (i < j){
		while (num[j] > tmp&&j>i)j--;
		num[i] = num[j];
		while (num[i] < tmp&&i<j)i++;
		num[j] = num[i];
	}
	num[i] = tmp;
	qsortt(begin, i - 1,num);
	qsortt(i + 1, end, num);
}
int main(){
	int a[10] = { 5, 2, 1, 3, 4, 7, 8, 6, 9, 0 };
	qsortt(0, 9, a);
	for (int i = 0; i <= 9; i++){
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}