//ºÉÀ¼¹úÆì
#include<iostream>
#include<algorithm>
using namespace std;
void work(int *num, int end){
	int begin = 1;
	int cur = 1;
	while (cur<end){
		if (num[cur] == 2){
			int tmp = num[cur];
			num[cur] = num[end];
			num[end] = tmp;
			end--;
		}
		if (num[cur] == num[begin] && num[begin] == 0){
			begin++;
			cur++;
		}
		else{
			if (num[cur] == 0){
				int tmp = num[cur];
				num[cur] = num[begin];
				num[begin] = tmp;
				begin++;
			}
		}
		if (num[cur] == 1){
			cur++;
		}
	}
}
int main(){
	int num[100];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> num[i];
	}
	work(num, n);
	for (int i = 1; i <= n; i++){
		cout << num[i] << " ";
	}
	system("pause");
	return 0;
}