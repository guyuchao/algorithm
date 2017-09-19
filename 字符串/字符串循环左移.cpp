//×Ö·û´®Ñ­»·×óÒÆ
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string a;
	cin >> a;
	int k;
	cin >> k;
	string::iterator it = a.begin();
	
	reverse(a.begin(), (a.begin() +k));
	
	cout << a;
	system("pause");
	reverse((a.begin() + k) , a.end());
	cout << a;
	system("pause");
	reverse(a.begin(), a.end());
	cout << a;
	system("pause");
}