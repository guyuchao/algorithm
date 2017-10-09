//Äæ²¨À¼±í´ïÊ½
#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isdigit(char a) {
	if (a >= '0'&&a <= '9')return true;
	return false;
}
int nibolan(string testcase) {
	stack<int> S;
	int len = testcase.length();
	for (int i = 0; i < len; i++) {
		if (testcase[i] == ',')continue;
		if (isdigit(testcase[i])) {
			int tmp = testcase[i] - '0';
			while (isdigit(testcase[i + 1])) {
				i++;
				tmp = tmp * 10 + (testcase[i]-'0');
			}
			S.push(tmp);
		}
		else {
			int right = S.top();
			S.pop();
			int left = S.top();
			S.pop();
			switch (testcase[i]) {
			case '+':
				S.push(left + right);
				break;
			case '-':
				S.push(left - right);
				break;
			case '*':
				S.push(left*right);
				break;
			case '/':
				S.push(int(left / right));
				break;
			}
		}
	}
	return S.top();
}
int main() {
	string testcase = "4,13,5,/,+";
	cout << nibolan(testcase);
	system("pause");
	return 0;
}