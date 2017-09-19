//查找旋转数组的最小值
#include<iostream>
using namespace std;
int solve(int from, int to, int *a){
	if (from == to)return a[from];
	if (a[from] < a[to])return a[from];
	else{
		int mid = (from + to) / 2;
		if (a[mid] > a[to]){
			return solve(mid + 1, to, a);
		}
		else{
			return solve(from, mid, a);
		}
	}
}
int main(){
	int n;
	cin >> n;
	int a[20];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int ans = solve(1, n, a);
	cout << ans;
	system("pause");
	return 0;
}