//LCS
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	string a, b;
	cin >> a >> b;
	int lena = a.length();
	int lenb = b.length();
	int dp[100][100];
	char dir[100][100];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= lena; i++){
		for (int j = 1; j <= lenb; j++){
			if (a[i-1] == b[j-1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				dir[i][j] = 'x';//Ð±ÉÏ
			}
			else{
				if (dp[i][j - 1] > dp[i - 1][j]){
					dp[i][j] = dp[i][j - 1];
					dir[i][j] = 'z';//×ó
				}
				else{
					dp[i][j] = dp[i-1][j];
					dir[i][j] = 's';//ÓÒ
				}
				
			}
		}
	}
	string c;
	int i=lena, j=lenb;
	while (i > 0 && j > 0){
		switch (dir[i][j]){
		case 'x':
			c += a[i-1];
			i--;
			j--;
			break;
		case 'z':
			j--;
			break;
		case 's':
			i--;
			break;
		}
	}
	reverse(c.begin(), c.end());
	cout << c;
	system("pause");
	return 0;
}