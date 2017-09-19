#include<iostream>
#include<algorithm>
using namespace std;
void findd(int *num, bool *take, int cur, int len, int sum,int ans_sum){
	if (cur > len)return;
	if ((sum + num[cur]) > ans_sum)return;
	if ((sum + num[cur]) == ans_sum){
		for (int i = 1; i < cur;i++){
			if (take[i] == true){
				cout << num[i] << " ";
			}
		}
		cout << num[cur] << endl;
		return;
	}
	
	else{
		take[cur] = true;
		findd(num, take, cur + 1, len, sum + num[cur], ans_sum);
		take[cur] = false;
		findd(num, take, cur + 1, len, sum, ans_sum);
	}
}
int main(){
	int n;
	cin >> n;
	int a[100];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n);
	int ans_sum;
	cin >> ans_sum;
	bool take[100];
	memset(take, 0, sizeof(take));
	findd(a,take, 1, n, 0,ans_sum);
	system("pause");
	return 0;
}