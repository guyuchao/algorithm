//Á´Ê½¼Ó·¨
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

	Link(string A){
		head = new node(0);
		for (int i = 0; i < A.length(); i++) {
			headinsert(A[i] - '0');
		}
	}
	Link() {
		head = new node(0);
	}
	void headinsert(int data){
		node* tmp = new node(data);
		tmp->next = head->next;
		head->next = tmp;
		head->data++;
	}
	void transverse(){
		node* cur = head->next;
		while (cur!= NULL) {
			cout << cur->data<<" ";
			cur = cur->next;
		}
	}
};
Link pluss(Link A, Link B) {//A short
	Link ret;
	int jinwei = 0;
	node* a_cur = A.head->next;
	node* b_cur = B.head->next;
	for (int i = 0; i < A.head->data; i++) {
		int tmp = (jinwei + a_cur->data + b_cur->data) % 10;
		ret.headinsert(tmp);
		jinwei = (jinwei+a_cur->data + b_cur->data) / 10;
		a_cur = a_cur->next;
		b_cur = b_cur->next;
	}
	if (A.head->data == B.head->data) {
		if (jinwei == 0) {}
		else {
			ret.headinsert(jinwei);
		}
	}
	else {
		for (int i = 0; i < B.head->data - A.head->data; i++) {
			ret.headinsert((jinwei + b_cur->data) % 10);
			jinwei = (jinwei +  b_cur->data) / 10;
			b_cur = b_cur->next;
		}
		if (jinwei == 0) {
			return ret;
		}
		else {
			ret.headinsert(jinwei);
		}
	}
	return ret;
}
int main() {
	string a = "12345";
	string b = "123641";
	Link A(a);
	Link B(b);
	Link C;
	C = pluss(A, B);
	C.transverse();
	system("pause");
	return 0;
}