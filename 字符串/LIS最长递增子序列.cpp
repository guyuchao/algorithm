//LIS最长递增子序列
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string a;
	cin >> a;
	int len = a.length();
	string b = a;
	sort(b.begin(), b.end());
	int dp[2][100];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= len; i++){
		for (int j = 1; j <= len; j++){
			if (a[i - 1] == b[j- 1]){
				dp[1][j] = dp[0][j-1]+1;
			}
			else{
				dp[1][j] = max(dp[0][j], dp[1][j-1]);
			}
		}
		for (int k = 1; k <= len; k++){
			dp[0][k] = dp[1][k];
			dp[1][k] = 0;
		}
	}
	cout << dp[0][len];
	system("pause");
	return 0;
}