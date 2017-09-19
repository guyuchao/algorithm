//ÕÍ√¿œ¥≈∆
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[100];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int i = n / 2, j = n / 2 + 1;
	swap(a[i], a[j]);
	while (i-1 > 1 && j+1 < n){
		i--;
		j++;
		swap(a[i], a[i + 1]);
		swap(a[j - 1], a[j]);
	}
	for (int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}