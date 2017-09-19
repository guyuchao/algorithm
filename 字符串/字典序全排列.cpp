//后找，小大，交换，翻转，字典序全排列
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void swapp(string::iterator it1,string::iterator it2){
	char tmp;
	tmp = *it1;
	*it1=*it2;
	*it2 = tmp;
	return;
}
void find_next_permutation(string& str){
	string::iterator iter = str.end();
	iter--;
	while (iter != str.begin()){
		if (*iter > *(iter - 1)){
			for (string::iterator it = str.end() - 1;; it--){
				if (*it > *(iter - 1)){
					swapp(it, (iter - 1));
					reverse(iter, str.end());
					return;
				}
			}
		}
		else{
			iter--;
		}
	}
}
int main(){
	string str;
	cin >> str;
	string str1 = str;
	sort(str.begin(), str.end());
	cout << str << endl;
	sort(str1.rbegin(), str1.rend());
	//cout << str<<endl<<str1;
	do{
		find_next_permutation(str);
		cout << str<<endl;
	} while (str != str1);
	system("pause");
	return 0;
}