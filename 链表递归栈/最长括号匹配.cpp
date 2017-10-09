//×î³¤À¨ºÅÆ¥Åä  £¨£©£¨£©£º4 £¨£¨£©£¨£©£©£º6
#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
int maxlen(string str) {
	int last = 0;
	stack<int> S;
	int max_ans = -1;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			S.push(i);
		}
		else {
			if (S.empty()) {
				last = i+1;
			}
			else {
				int tmp = S.top();
				S.pop();
				if (S.empty()) {
					max_ans = max(max_ans, i - last+1);
				}
				else {
					max_ans = max(max_ans, i - tmp+1);
				}
			}
		}
	}
	return max_ans;
}
int main() {
	int last = 0;
	string test = "())()()()";
	cout << maxlen(test);
	system("pause");
	return 0;
}