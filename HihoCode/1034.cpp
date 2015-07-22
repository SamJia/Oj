#include <cstdio>

struct Node
{
	int left, right;
	long long value;
	Node *l_son, *r_son;
	Node(Node *ls = NULL, Node *rs = NULL) : left(0), right(0), value(0), l_son(ls), r_son(rs){}
};

