#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node(int d) {
		data = d;
		next = nullptr;
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
			tailinsert(str[0] - '0');
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
	void quchong() {//ШЅжи
		node* cur = head->next;
		while (cur != nullptr) {
			node* tmp = cur->next;
			while (cur!=nullptr&&tmp!=nullptr&&cur->data == tmp->data) {
				cur->next = tmp->next;
				delete(tmp);
				tmp = cur->next;
			}
			cur = cur->next;
		}
	}
};

int main() {
	string str = "12233445";
	Link A(str);
	A.quchong();
	A.transvers();
	system("pause");
	return 0;
}