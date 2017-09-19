//manacher
#include<iostream>
#include<string>
using namespace std;
int huiwen_force(string str,int pos){
	int i = pos - 1;
	int j = pos + 1;
	int tmp=1;
	while (i > 0 && j < str.length()){
		if (str[i] == str[j]){
			i--;
			j++;
			tmp++;
		}
		else{
			break;
		}
	}
	return tmp;
}
int huiwen_force(string str, int pos,int pianyi){
	int i = pos - pianyi;
	int j = pos + pianyi;
	int tmp = pianyi;
	
	while (i > 0 && j < str.length()){
		if (str[i] == str[j]){
			i--;
			j++;
			tmp++;
		}
		else{
			break;
		}
	}
	return tmp;
}
int main(){
	string str;
	cin >> str;
	string str2;
	str2 += '$';
	for (int i = 0; i < str.length(); i++){
		str2 += '#';
		str2 += str[i];
	}
	str2 += '#';//gap´®
	
	int len_str2 = str2.length();
	int ans[100];
	memset(ans, 0, sizeof(ans));
	int max_right=-1,max_right_center=-1;
	for (int i = 1; i < len_str2; i++){
		
		if ((max_right + max_right_center - 1) >= i){
			int tmp_point = 2 * max_right_center - i;
			if ((ans[tmp_point] + i - 1) < (max_right + max_right_center - 1)){
				ans[i] = ans[tmp_point];
			}
			else{
				ans[i] = huiwen_force(str2, i, max_right+max_right_center-1-i);
			}
		}
		else{
			ans[i] = huiwen_force(str2, i);
			if ((max_right+max_right_center-1) < (ans[i]+i-1)){
				max_right = ans[i];
				max_right_center = i;
			}
		}
	}
	for (int i = 1; i < str2.length(); i++){
		cout << str2[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < str2.length(); i++){
		cout << ans[i] << " ";
	}

	system("pause");
	return 0;

}