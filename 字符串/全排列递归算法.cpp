//全排列递归算法（去除重复）
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
void swapp(string& a,int b,int c){
	char tmp;
	tmp = a[b];
	a[b] = a[c];
	a[c] = tmp;
	return;
}

void permutation(string a, int from,int to){
	bool mark[256];
	memset(mark, 0, sizeof(mark));
	if (from == to){
		cout << a<<endl;
		return;
	}
	int pos;
	for (int i = from; i < to;i++){
		//if ((pos = a.find(a[i]))<i){//没有当过首字符
		if (mark[a[i]] == false){
			mark[a[i]] = true;
			swapp(a, from, i);
			permutation(a, from + 1, to);
			swapp(a, from, i);
		}
		//}
	}
	return;
}

int main(){
	string a = "1122";
	
	permutation(a,0,a.length());
	system("pause");
	return 0;
}