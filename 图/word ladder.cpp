#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
using namespace std;

void work(string beginword, set<string>& nodeset, set<string>& wordlist) {
	int len = beginword.length();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j <= 25; j++) {
			char tmpch = 'a' + j;
			string tmpstr = beginword.substr(0, i) + tmpch + beginword.substr(i + 1, len - 1);
			if (tmpstr != beginword&&wordlist.count(tmpstr) != 0) {
				nodeset.insert(tmpstr);
			}
		}
	}
}

int ladderLength(string beginWord, string endWord, set<string>& wordList) {
	map<string, set<string>> graph;
	for (auto &item : wordList) {
		set<string> nodeset;
		work(item, nodeset,wordList);
		graph[item] = nodeset;
	}
	
	for (auto key : graph) {
		cout << key.first << "    " ;
		for (auto &item : key.second) {
			cout << item << " ";
		}
		cout << endl;
	}
	map<string, string> pre;
	set<string> visited;
	queue<string> myque;
	myque.push(beginWord);
	while (!myque.empty()) {
	
		string now = myque.front();
		myque.pop();
		if (visited.count(now) != 0) {
			continue;
		}
		visited.insert(now);
		if (now == endWord) {
			int ans = 0;
			string tmp = endWord;
			while (pre.count(tmp) != 0) {
				ans++;
				//cout << tmp;
				tmp = pre[tmp];
				
			}
			return ans;
		}
		else {
			for (auto &elem : graph[now]) {
				if (visited.count(elem) == 0&&pre.count(elem)==0) {
					myque.push(elem);
					pre[elem] = now;
				}
			}
		}
	}
}
int main() {
	string begin, end;
	set<string> wordlist;
	cin >> begin >> end;
	string tmp;
	for(int i=1;i<=5;i++) {
		cin >> tmp;
		wordlist.insert(tmp);
	}
	wordlist.insert(begin);
	wordlist.insert(end);
	cout<<ladderLength(begin, end, wordlist);
	
	//system("pause");
	return 0;
}