#include<iostream>
#include<string>
using namespace std;
struct node{
	char data;
	node* leftchild;
	node* rightchild;
	node() :leftchild(NULL), rightchild(NULL){}
	node(char c){
		leftchild = NULL;
		rightchild = NULL;
		data = c;
	}
};
class tree{
public:
	node *root;
	tree() :root(NULL){}
	void work(string &pre, string mid,node*& current){
		current = new node(pre[0]);	
		int len = mid.length();
		string left = "";
		string right = "";
		int i, j;
		for (i = 0; mid[i] != pre[0]; i++){
			left += mid[i];
		}
		for (j = i + 1; j < len; j++){
			right += mid[j];
		}
		pre.erase(pre.begin());
		if (left.empty() == false){
			work(pre, left, current->leftchild);
		}
		if (right.empty() == false){
			work(pre, right, current->rightchild);
		}
	}
	void preorder(node* current){
		if (current == NULL)return;
		cout << current->data << " ";
		preorder(current->leftchild);
		preorder(current->rightchild);
	}
	void midorder(node* current){
		if (current == NULL)return;
		midorder(current->leftchild);
		cout << current->data << " ";		
		midorder(current->rightchild);
	}
};
int main(){
	tree A;
	string pre = "GDAFEMHZ";
	string mid = "ADEFGHMZ";
	A.work(pre, mid,A.root);
	A.preorder(A.root);
	cout << endl;
	A.midorder(A.root);
	system("pause");
	return 0;
}



