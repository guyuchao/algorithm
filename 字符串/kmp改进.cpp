//KMP and KMP¸Ä½ø
#include<iostream>
#include<string>
using namespace std;
void getnext(int* next,string pattern){
	next[1] = 0;
	int j = 0;
	int k = -1;
	int len_pat = pattern.length();
	while (j < len_pat - 1){
		if (k == -1||pattern[j]==pattern[k]){
			k++;//
			j++;
			if (pattern[j] == pattern[k]){
				next[j] = next[k];
			}
			else{
				next[j] = k;
			}
		}
		else{
			k = next[k];
		}
	}
}
int main(){
	string text, pattern;
	cin>>text>> pattern;
	int next[100];
	next[0] = -1;
	getnext(next,pattern);
	
	int txt_i=0,pat_j = 0;
	int ans = -1;
	int txt_len = text.length();
	int pat_len = pattern.length();
	while ((txt_i < txt_len) && (pat_j < pat_len)){
		if (pat_j == -1||text[txt_i] == pattern[pat_j]){
			txt_i++;
			pat_j++;
		}
		else{
			pat_j = next[pat_j];
		}
		if (pat_j == pattern.length() - 1){
			ans = txt_i - pat_j;
			break;
		}
	}
	cout << ans;
	system("pause");
	return 0;
} 