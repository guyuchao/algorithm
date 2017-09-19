//Áã×ÓÊý×é
#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const void *a, const void *b){
	int *c = (int*)a;
	int *d = (int*)b;
	return  *c-*d ;
}
int main(){
	int n;
	int a[20];
	a[0] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int tmp;
		cin >> tmp;
		a[i] = a[i - 1] + tmp;
	}
	qsort(a+1,n,sizeof(a[0]),cmp);
	int min1=100000;
	for (int i = 2; i <= n; i++){
		if ((a[i] - a[i - 1]) < min1){
			min1 = a[i] - a[i - 1];
		}
	}
	int min2 = abs(a[1]);
	for (int i = 2; i <= n; i++){
		if (abs(a[i]) < min2){
			min2 = abs(a[i]);
		}
	}
	cout << min(min1, min2);
	system("pause");
	return 0;
}