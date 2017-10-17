#include<algorithm>
#include<iostream>
using namespace std;
struct node{
	int data;
	node* leftchild;
	node* rightchild;
	node(){
		leftchild = NULL;
		rightchild = NULL;
	}
	node(int num){
		leftchild = NULL;
		rightchild = NULL;
		this->data = num;
	}
};
class avl_tree{
public:
	node* root;
	avl_tree(){
		root = NULL;
	}
	void Lrotate(node*& cur){
		node* tmp = cur->leftchild;
		cur->leftchild = tmp->rightchild;
		tmp->rightchild = cur;
		cur = tmp;
	}
	void Rrotate(node*& cur){
		node* tmp = cur->rightchild;
		cur->rightchild = tmp->leftchild;
		tmp->leftchild = cur;
		cur = tmp;
	}
	void LRrotate(node*&cur){
		Rrotate(cur->leftchild);
		Lrotate(cur);
	}
	void RLrotate(node*&cur){
		Lrotate(cur->rightchild);
		Rrotate(cur);
	}
	int height(node* cur){
		if (cur == NULL)return 0;
		else{
			return max(height(cur->leftchild), height(cur->rightchild)) + 1;
		}
	}
	void insert(node*& cur, int data){
		if (cur == NULL){
			cur = new node(data);
			return;
		}
		if (data < cur->data){
			insert(cur->leftchild, data);
			if (height(cur->leftchild) - height(cur->rightchild) == 2){
				if (height(cur->leftchild->leftchild) > height(cur->leftchild->rightchild)){
					Lrotate(cur);
				}
				else{
					RLrotate(cur);
				}
			}
		}
		else{
			insert(cur->rightchild, data);
			if (height(cur->rightchild) - height(cur->leftchild) == 2){
				if (height(cur->rightchild->rightchild) > height(cur->rightchild->leftchild)){
					Rrotate(cur);
				}
				else{
					LRrotate(cur);
				}
			}
		}
	}
	void remove(node*& cur,int data){
		if (cur == NULL)return;
		if (cur->data == data){

		}
		else{
			if (data < cur->data){
				remove(cur->leftchild, data);
			}
			else{
				remove(cur->rightchild, data);
			}
		}

	}
	void preorder(node* cur){
		if (cur == NULL)return;
		cout << cur->data << " ";
		preorder(cur->leftchild);
		preorder(cur->rightchild);
	}
	void midorder(node* cur){
		if (cur == NULL)return;
		midorder(cur->leftchild);
		cout << cur->data << " ";
		midorder(cur->rightchild);
	}
};

int main(){
	int a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	avl_tree Tree;
	for (int i = 0; i < 9; i++){
		Tree.insert(Tree.root, a[i]);
	}
	Tree.preorder(Tree.root);
	cout << endl;
	Tree.midorder(Tree.root);
	system("pause");
	return 0;
}