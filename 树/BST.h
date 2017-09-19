#ifndef _BST_H_
#define _BST_H_
class BSTnode{
public:
	int data;
	BSTnode* leftchild;
	BSTnode* rightchild;
	BSTnode();
	BSTnode(int data);
};
class BSTtree{
private:
	BSTnode* root;
public:
	BSTnode* &getroot();
	BSTtree();
	bool insert(BSTnode* &root_node, int insert_data);
	bool search(int search_data, BSTnode* root_node);
	bool midorder(BSTnode* cur);
	bool remove(int data,BSTnode* cur_node);
	BSTnode* findparent(BSTnode* find_node,BSTnode* curnode);
};
#endif