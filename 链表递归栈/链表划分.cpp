#include<iostream>
#include<string>
using namespace std;
struct node {
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
class Link {
public:
	node* head;
	node* tail;
	Link(string str) {
		head = new node(0);
		tail = head;
		while (!str.empty()) {
			tailinsert(str[0]-'0');
			str.erase(str.begin());
		}
	}
	Link() {
		head = new node(0);
		tail = head;
	}
	void tailinsert(int data) {
		tail->next = new node(data);
		tail = tail->next;
		head->data++;
	}
	void transvers() {
		node* cur = head->next;
		while (cur != nullptr) {
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
};
Link huafen(Link A,int key) {
	Link tmp_left;
	Link tmp_right;
	int cnt = A.head->data;
	node* cur = A.head->next;
	while (cnt--) {
		if (cur->data < key) {
			tmp_left.tailinsert(cur->data);
		}
		else {
			tmp_right.tailinsert(cur->data);
		}
		cur = cur->next;

	}
	tmp_left.tail->next = tmp_right.head->next;
	tmp_left.head->data += tmp_right.head->data;
	delete(tmp_right.head);
	return tmp_left;
}
int main() {
	string str = "143252";
	int key = 3;
	Link A(str);
	Link B=huafen(A,key);
	B.transvers();
	system("pause");
	return 0;
}