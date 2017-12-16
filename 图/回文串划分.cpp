#include<vector>
#include<iostream>
#include<string>
using namespace std;
bool ishuiwen(string str) {
	if (str.length() == 0)return false;
	int i = 0;
	int j = str.length() - 1;
	while (i <= j&&str[i] == str[j]) {
		i++;
		j--;
	}
	if (i > j)return true;
	else return false;
}
void DFS(vector<vector<string>> &result, string str,vector<string> tmp_ans) {
	if (str.length() == 0) {
		result.push_back(tmp_ans);
		return;
	}
	else {
		for (int i = 0; i < str.length(); i++) {
			if (ishuiwen(str.substr(0, i+1)) == true) {
				tmp_ans.push_back(str.substr(0, i+1));
				DFS(result, str.substr(i+1), tmp_ans);
				tmp_ans.pop_back();
			}
		} 
	}
}
int main() {
	string str;
	cin >> str;
	vector<vector<string>> result;
	vector<string> tmp_ans;
	DFS(result, str,tmp_ans);
	for (int i = 0; i < result.size(); i++) {
		vector<string> now = result[i];
		for (int j = 0; j < now.size(); j++) {
			cout << now[j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}