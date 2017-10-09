#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool kuohao(char a, char b) {
	if (a == '('&&b == ')')return true;
	if (a == '['&&b == ']')return true;
	if (a == '{'&&b == '}')return true;
	return false;
}
bool pipei(string str) {
	stack<char> S;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			S.push(str[i]);
		else {
			if (kuohao(S.top(), str[i]))S.pop();
			else {
				return false;
			}
		}
	}
	if(S.empty()==true)	return true;
}
int main() {
	string str = "(({})[())])";
	bool ans = pipei(str);
	string ans1=(ans == 1) ? "true" : "false";
	cout << ans1;
	system("pause");
	return 0;
}