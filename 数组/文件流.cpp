//c++ ÎÄ¼şÁ÷
#include<fstream>
#include<iostream>
using namespace std;
int main(){
	
	ifstream file;
	char ouput[100];
	file.open("1.txt");
	file >> ouput;
	cout << ouput;
	system("pause");
	return 0;
}