//À¨ºÅÆ¥Åä£¨¿Õ¼äO(1)¸Ä½ø£©
#include<iostream>
#include<algorithm>	
#include<string>

using namespace std;
int pipei(string str) {
	int start = 0;
	int ans = 0;
	int deep = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			deep++;
		}
		else {
			deep--;
			if (deep == 0) {
				ans = max(ans, i - start+1);
			}
			if (deep < 0) {
				deep = 0;
				start = i + 1;
			}
		}
	}
	start = str.length()-1;
	deep = 0;
	for (int i = str.length()-1; i >=0; i--) {
		if (str[i] == ')') {
			deep++;
		}
		else {
			deep--;
			if (deep == 0) {
				ans = max(ans, start-i+1);
			}
			if (deep < 0) {
				deep = 0;
				start = i - 1;
			}
		}
	}

	return ans;
}
int main() {
	string testcase = "((()())";
	cout << pipei(testcase);
	system("pause");
	return 0;
}