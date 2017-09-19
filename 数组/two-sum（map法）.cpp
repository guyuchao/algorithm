//two_sum hash
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	int n;
	cin >> n;
	typedef map<int, int> MyMap;
	MyMap mapp;
	for (int i = 1; i <= n; i++){
		int tmp;
		cin >> tmp;
		if (mapp.count(tmp) == false){
			mapp[tmp] = 1;
		}
		else{
			mapp[tmp]++;
		}
	}
	int sum;
	cin >> sum;
	MyMap::iterator it = mapp.begin();
	for (it; it != mapp.end(); it++){
		if ((mapp.count(it->first) == true) && (mapp.count(sum - it->first) == true)){
			cout << it->first << " " << sum - it->first;
			return;
		}
	}
	cout << "none";
	system("pause");
	return 0;
}