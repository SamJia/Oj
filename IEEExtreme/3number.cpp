#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
	int a, b, c;
	int level;
	Node *prev = NULL;
	Node(int _a = 0, int _b = 0, int _c = 0, int _level = 0):a(_a), b(_b), c(_c), level(_level){}
};

int main() {
	queue<Node*> Q;
	stack<Node*> S;
	Node *poker = new Node;
	cin >> poker->a >> poker->b >> poker->c;
	poker->level = 0;
	Q.push(poker);
	int flag = 0;
	while(!Q.empty()) {
		Node *node = Q.front();
		Q.pop();
		if(node->level == 11) break;
		if(node->a == node->b || node->a == node->c || node->b == node->c) {
			flag = 1;
			if(node->a == node->b) {
				Node *las = new Node(node->a * 2, 0, node->c, node->level + 1);
				S.push(las);
			}
			else if(node->a == node->c) {
				Node *las = new Node(node->a * 2, node->b, 0, node->level + 1);
				S.push(las);
			}
			else {
				Node *las = new Node(node->a, node->b * 2, 0, node->level + 1);
				S.push(las);
			}
			while(node != NULL) {
				S.push(node);
				node = node->prev;
 			}
			break;
		}
		if(node->a < node->b) {
			Node *tmp1 = new Node(node->a * 2, node->b - node->a, node->c, node->level + 1);
			tmp1->prev = node;
			Q.push(tmp1);
		}
		if(node->a < node->c) {
			Node *tmp1 = new Node(node->a * 2, node->b, node->c - node->a, node->level + 1);
			tmp1->prev = node;
			Q.push(tmp1);
		}
		if(node->a > node->b) {
			Node *tmp1 = new Node(node->a - node->b, node->b * 2, node->c, node->level + 1);
			tmp1->prev = node;
			Q.push(tmp1);
		}
		if(node->b < node->c) {
			Node *tmp1 = new Node(node->a, node->b * 2, node->c - node->b, node->level + 1);
			tmp1->prev = node;
			Q.push(tmp1);
		}
		if(node->a > node->c) {
			Node *tmp1 = new Node(node->a - node->c, node->b, node->c * 2, node->level + 1);
			tmp1->prev = node;
			Q.push(tmp1);
		}
		if(node->b > node->c) {
			Node *tmp1 = new Node(node->a, node->b - node->c, node->c * 2, node->level + 1);
			tmp1->prev = node;
			Q.push(tmp1);
		}
	}
	if(flag) {
		while(!S.empty()) {
			Node *res = S.top();
			S.pop();
			cout << res->a << ' ' << res->b << ' ' << res->c << endl;
		}
	}
	else cout << "Ok" << endl;
}