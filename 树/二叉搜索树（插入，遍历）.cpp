#include<iostream>
using namespace std;
class BSTnode{
public:
	int data;
	BSTnode* leftchild;
	BSTnode* rightchild;
	BSTnode(){
		leftchild = NULL;
		rightchild = NULL;
	}
	BSTnode(int data){
		this->data = data;
	}
};
class BSTtree{
private:
	BSTnode* root;
public:
	BSTnode* &getroot(){
		return this->root;
	}
	BSTtree(){
		root = new BSTnode();
	}
	bool insert(BSTnode* &root_node, int insert_data){
		if (root_node == NULL){
			root_node = new BSTnode(insert_data);
			return true;
		}
		else{
			if (insert_data >= root_node->data){
				insert(root_node->rightchild,insert_data);
			}
			else{
				insert(root_node->leftchild, insert_data);
			}
		}
	}
	bool search(int search_data, BSTnode* root_node){
		if (root_node == NULL)return false;
		else{
			if (root_node->data == search_data){
				return true;
			}
			else{
				if (search_data >= root_node->data)search(search_data, root_node->rightchild);
				else{
					search(search_data, root_node->leftchild);
				}
			}
		}
	}
	bool midorder(BSTnode* cur){
		if (cur->leftchild != NULL){
			midorder(cur->leftchild);
		}
		if(cur!=root)cout << cur->data<<" ";
		if (cur->rightchild != NULL){
			midorder(cur->rightchild);
		}
		return true;
	}
};
int main(){
	BSTtree tree;
	int num[12] = { 15, 5, 3, 12, 16, 20, 23, 13, 18, 10, 6, 7 };
	for (int i = 0; i < 12; i++){
		tree.insert(tree.getroot(), num[i]);
	}
	tree.midorder(tree.getroot());
	system("pause");
	return 0;

}