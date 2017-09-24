//链表部分翻转
#include<iostream>
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

	Link(string A) {
		head = new node(0);
		tail = head;
		for (int i = 0; i < A.length(); i++) {
			tailinsert(A[i] - '0');
		}
	}
	void tailinsert(int data) {
		tail->next = new node(data);
		tail = tail->next;
	}
	void transverse() {
		node* cur = head->next;
		while (cur != NULL) {
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
	void reverse(int m, int n) {
		//翻转m-n
		node* cur_head = head;
		for (int i = 1; i <= m-1; i++) {
			cur_head = cur_head->next;
		}
		node* cur_tail = cur_head->next;
		for (int i = 1; i <= n-m; i++) {
			node* tmp = cur_tail->next;
			cur_tail->next = tmp->next;
			tmp->next = cur_head->next;
			cur_head->next = tmp;
			
		}
	}
};
int main() {
	string testcase = "12345";
	Link A(testcase);
	A.reverse(2, 4);
	A.transverse();
	system("pause");
	return 0;
}