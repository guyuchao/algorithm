#include<iostream>
#include<map>
#include<set>
using namespace std;
struct edge_node {
	int node_id;
	int dis;
};
class graph {
public:
	int num_node;
	int num_edge;
	map<int, set<edge_node>> graph;
	void insert(int begin, int end, int dis = 1) {
		edge_node tmp;
		tmp.dis = dis;
		tmp.node_id = end;
		graph[begin].insert(tmp);
	}
	void transvers() {
		for (auto ele : graph[1]) {
			cout << ele << " ";
		}
	}
};
int main() {
	graph A;
	A.insert(1, 2);
	A.insert(2, 3);
	A.insert(1, 3);
	A.transvers();

	system("pause");
	return 0;
}