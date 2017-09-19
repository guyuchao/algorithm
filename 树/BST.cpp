#include"BST.h"
#include<iostream>
BSTnode::BSTnode(){
	leftchild = NULL;
	rightchild = NULL;
}
BSTnode::BSTnode(int data){
	this->data = data;
}
BSTnode*& BSTtree::getroot(){
	return this->root;
}
BSTtree::BSTtree(){
	root = new BSTnode();
}
bool BSTtree::insert(BSTnode* &root_node, int insert_data){
	if (root_node == NULL){
		root_node = new BSTnode(insert_data);
		return true;
	}
	else{
		if (insert_data >= root_node->data){
			insert(root_node->rightchild, insert_data);
		}
		else{
			insert(root_node->leftchild, insert_data);
		}
	}
}
bool BSTtree::search(int search_data, BSTnode* root_node){
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
bool BSTtree::midorder(BSTnode* cur){
	if (cur->leftchild != NULL){
		midorder(cur->leftchild);
	}
	if (cur != root)std::cout << cur->data << " ";
	if (cur->rightchild != NULL){
		midorder(cur->rightchild);
	}
	return true;
}
BSTnode* BSTtree::findparent(BSTnode* find_node,BSTnode* cur_node){
	if (find_node == cur_node->leftchild || find_node == cur_node->rightchild)return cur_node;
	else{
		if (find_node->data < cur_node->data)findparent(find_node, cur_node->leftchild);
		else{
			findparent(find_node, cur_node->rightchild);
		}
	}
}
bool BSTtree::remove(int data,BSTnode* cur_node){
	if (cur_node == NULL)return false;
	if (data != cur_node->data){
		if (data < cur_node->data)remove(data, cur_node->leftchild);
		else{
			remove(data, cur_node->rightchild);
		}
	}
	else{
		//直接是节点
		BSTnode* tmpparent = findparent(cur_node, root);
		if (cur_node->leftchild == NULL&&cur_node->rightchild == NULL){
			if (tmpparent->leftchild == cur_node)tmpparent->leftchild = NULL;
			else{
				tmpparent->rightchild = NULL;
			}
			delete(cur_node);
			return true;
		}
		//只有一个孩子
		if (cur_node->leftchild == NULL && cur_node->rightchild != NULL){
			if (tmpparent->leftchild == cur_node){
				tmpparent->leftchild = cur_node->rightchild;
			}
			else{
				tmpparent->rightchild = cur_node->rightchild;
			}
			return true;
		}
		if (cur_node->leftchild != NULL && cur_node->rightchild == NULL){
			if (tmpparent->leftchild == cur_node){
				tmpparent->leftchild = cur_node->leftchild;
			}
			else{
				tmpparent->rightchild = cur_node->leftchild;
			}
			return true;
		}
		//有左右孩子
		if (cur_node->leftchild != NULL&&cur_node->rightchild != NULL){
			BSTnode* cur = cur_node->rightchild;
			while (cur->leftchild != NULL)cur = cur->leftchild;
			cur_node->data = cur->data;
			BSTnode* tmp_cur_parent = findparent(cur,root);
			if (tmp_cur_parent == cur_node){
				delete(cur);
				cur_node->rightchild = NULL;
				return true;
			}
			if (cur->rightchild == NULL){
				tmp_cur_parent->leftchild = NULL;
				delete(cur);
				return true;
			}
			else{
				tmp_cur_parent->leftchild = cur->rightchild;
				delete(cur);
				return true;
			}
		}
	}
}