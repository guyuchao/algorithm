#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool huiwen(string str) {
	int i = 0;
	int j = str.length()-1;
	if (j < 0)return false;
	while (i <= j&&str[i] == str[j]) {
		i++;
		j--;
	}
	if (i > j)return true;
	else {
		return false;
	}
}
int main() {
	string str;
	cin >> str;
	vector<vector<string>> dp[20];
	int len = str.length();
	for (int i = len - 1; i >= 0; i--) {
		for (int j = i; j < len; j++) {
			string tmpstr = str.substr(i, j - i + 1);
			if (huiwen(tmpstr)) {
				vector<vector<string>> tmpvec = dp[j+1];
				if (tmpvec.size() == 0) {
					vector<string> tmp_new;
					tmp_new.push_back(tmpstr);
					dp[i].push_back(tmp_new);
				}
				for (int k = 0; k < tmpvec.size(); k++) {
					vector <string> tmp_new= tmpvec[k];
					tmp_new.push_back(tmpstr);
					dp[i].push_back(tmp_new);
				}
			}
		}
	}
	for (int i = 0; i < dp[0].size(); i++) {
		for (int j=0; j < dp[0][i].size(); j++) {
			cout << dp[0][i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}