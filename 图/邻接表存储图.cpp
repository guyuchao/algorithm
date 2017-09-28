//邻接表存储
#include<iostream>
using namespace std;
struct edge_table_node {//边表节点
	int node;//顶点下标
	int dis;
	edge_table_node* next;
	edge_table_node() {
		next = nullptr;
		dis = -1;
	}
	edge_table_node(int n, int d) {
		node = n;
		dis = d;
		next = nullptr;
	}
};
struct vertex_table_node {
	int node;//顶点下标
	edge_table_node* edge_head;
	vertex_table_node() {
		edge_head = new edge_table_node();
	}
	bool isempty() {
		if (edge_head->next == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
};
class adjlist {
public:
	vertex_table_node *vertex_list;
	int vertex_num;
	int edge_num;
	adjlist(int node_num) {
		vertex_list = new vertex_table_node[node_num+1];
		vertex_num = node_num;
	}
	void insert(int begin, int end, int dis = 1) {
		if (vertex_list[begin].isempty()) {
			edge_table_node* cur = vertex_list[begin].edge_head;
			cur->next = new edge_table_node(end, dis);
		}
		else {
			edge_table_node* cur = vertex_list[begin].edge_head->next;
			edge_table_node* tmp = new edge_table_node(end, dis);
			tmp->next = cur;
			vertex_list[begin].edge_head->next = tmp;
		}
	}
	void transvers() {
		for (int i = 1; i <= vertex_num; i++) {
			cout << i << "    :";
			if (!vertex_list[i].isempty()) {
				edge_table_node* cur = vertex_list[i].edge_head->next;
				while (cur != nullptr) {
					cout << cur->node << " ";
					cur = cur->next;
				}
			}
			cout << endl;
		}
	}
};
int main() {
	adjlist A(3);
	A.insert(1, 2);
	A.insert(2, 1);
	A.insert(2, 3);
	A.insert(3, 2);
	A.transvers();
	system("pause");
	return 0;
}
