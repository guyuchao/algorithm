#include<iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
	node() {
		left = nullptr;
		right = nullptr;
	}
	node(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};
class BST {
public:
	node* root;
	BST(int *a) {
		for (int i = 0; i < 9; i++) {
			insert(root, a[i]);
		}
	}
	void insert(node*& cur,int data) {
		if (cur == nullptr) {
			cur = new node(data);
			return;
		}
		if (data < cur->data) {
			insert(cur->left, data);
		}
		else {
			insert(cur->right, data);
		}
	}
	void midorder(node* cur) {
		if (cur == nullptr)return;
		midorder(cur->left);
		cout << cur->data<<" ";
		midorder(cur->right);
	}
	void preorder(node* cur) {
		if (cur == nullptr)return;
		cout << cur->data << " ";
		preorder(cur->left);
		preorder(cur->right);
	}
	node* findd(int data,node* cur) {
		if (cur->data == data)return cur;
		else {
			if (data < cur->data) {
				return findd(data, cur->left);
			}
			else {
				return findd(data, cur->right);
			}
		}
	}
};
node*  lca(node* root, node* node1, node* node2) {
	if (root == node2|| root == node1||root==nullptr)return root;
	node* lret = lca(root->left, node1, node2);
	node* rret = lca(root->right, node1, node2);
	if (lret == nullptr&&rret != nullptr)return rret;
	if (rret == nullptr&&lret != nullptr)return lret;
	if (lret != nullptr&&rret != nullptr)return root;
	return nullptr;
}	
int main() {
	int a[9] = { 4,2,1,3,9,5,6,7,0 };
	BST A(a);
	node* ans = lca(A.root, A.findd(3,A.root), A.findd(5,A.root));
	cout << ans->data;
	system("pause");
	return 0;
}