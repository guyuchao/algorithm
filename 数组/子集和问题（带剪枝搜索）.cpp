//子集和分支限界
#include<iostream>
using namespace std;
void  findd(int* num, int cur, int len, bool* take, int sum, int ans_sum, int residual){
	if (sum + num[cur] == ans_sum){
		for (int i = 1; i < cur; i++){
			if (take[i] == true){
				cout << num[i] << " ";
			}
		}
		cout << num[cur] << endl;
		return;
	}
	else{
		if (sum + residual >= ans_sum&&sum + num[cur] <= ans_sum){
			take[cur] = true;
			findd(num, cur + 1, len, take, sum + num[cur], ans_sum, residual - num[cur]);
		}
		if (sum + residual - num[cur] >= ans_sum){
			take[cur] = false;
			findd(num, cur + 1, len, take, sum, ans_sum, residual - num[cur]);
		}
	}
}
int main(){
	int n;
	cin >> n;
	int a[100];
	int residual = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		residual += a[i];
	}
	int ans_sum;
	cin >> ans_sum;
	bool take[100];
	memset(take, 0, sizeof(take));
	findd(a, 1, n, take, 0, ans_sum, residual);
	system("pause");
	return 0;
}