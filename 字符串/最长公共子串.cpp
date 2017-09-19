//最长公共子串
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string a, b;
	cin >> a >> b;
	int lena = a.length();
	int lenb = b.length();
	int dp[100][100];
	int max_ans = -1;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= lena; i++){
		for (int j = 1; j <= lenb; j++){
			if (a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				max_ans = max(max_ans, dp[i][j]);
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	cout << max_ans;
	system("pause");
	return 0;
}