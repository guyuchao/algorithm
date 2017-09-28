#include<iostream>
#include<queue>
using namespace std;
struct node {
	int data;
	node* parent;
	node* leftchild;
	node* rightchild;

	node(int d,node* p) {
		data = d;
		parent = p;
		leftchild = nullptr;
		rightchild = nullptr;
	}
};
class Tree {
public:
	node* root;
	Tree() {
		root = new node(1,nullptr);
		root->leftchild = new node(2,root);
		root->leftchild->leftchild = new node(3, root->leftchild);
		root->leftchild->rightchild = new node(4, root->leftchild);
		root->leftchild->rightchild->leftchild = new node(5, root->leftchild->rightchild);
		root->leftchild->rightchild->rightchild = new node(6, root->leftchild->rightchild);
		root->rightchild = new node(7, root);
		root->rightchild->rightchild = new node(8, root->rightchild);
		root->rightchild->rightchild->rightchild = new node(9, root->rightchild->rightchild);
		root->rightchild->rightchild->rightchild->leftchild = new node(10, root->rightchild->rightchild->rightchild);
		root->rightchild->rightchild->rightchild->rightchild = new node(11, root->rightchild->rightchild->rightchild);
	}
	void midorder(node* cur) {
		if (cur == nullptr)return;
		midorder(cur->leftchild);
		cout << cur->data << " ";
		midorder(cur->rightchild);
	}
	int length(node* cur) {
		int len = 1;
		while (cur->parent != nullptr) {
			cur = cur->parent;
			len++;
		}
		return len;
	}
	node* find(int data) {
		queue<node*> Q;
		Q.push(root);
		while (!Q.empty()) {
			node* cur = Q.front();
			Q.pop();
			if (cur->data == data) {
				return cur;
			}
			if (cur->leftchild != nullptr) {
				Q.push(cur->leftchild);
			}
			if (cur->rightchild != nullptr) {
				Q.push(cur->rightchild);
			}
		}
	}
	int LCA(int a,int b) {
		node* cur_a = find(a);
		node* cur_b = find(b);
		int len_a = length(cur_a);
		int len_b = length(cur_b);
		if (len_a >= len_b) {
			int tmp = len_a - len_b;
			while (tmp--) {
				cur_a = cur_a->parent;
			}
		}
		else {
			return LCA(b, a);
		}
		while (cur_a->parent != cur_b->parent) {
			cur_a = cur_a->parent;
			cur_b = cur_b->parent;
		}
		return cur_a->parent->data;
	}
};
int main() {
	Tree A;
	//A.midorder(A.root);
	cout << A.LCA(6, 10);
	system("pause");
	return 0;
}