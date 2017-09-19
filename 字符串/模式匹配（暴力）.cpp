//Ä£Ê½Æ¥Åä-±©Á¦
#include<iostream>
#include<string>
using namespace std;
int main(){
	string s, p;
	cin >> s >> p;
	int pos = -1;
	for (int i = 0; i <= s.length() - p.length(); i++){
		int s_i=i, p_i = 0;
		while (p_i != p.length()){
			if (s[s_i] == p[p_i]){
				s_i++;
				p_i++;
			}
			else{
				break;
			}
		}
		if (p_i == p.length()){
			pos = i;
			break;
		}
	}
	cout << pos+1;
	system("pause");
	return 0;
}