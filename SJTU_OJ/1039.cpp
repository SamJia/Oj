#include <iostream>
using namespace std;
#define SIZE 30010
struct Node{
	Node(int number) : number_(number), left_(NULL), right_(NULL){}
	int number_;
	Node *left_, *right_;
};

int total_number, number, leftchild, rightchild;
pair<int, Node *> nodes[SIZE] = {};

void AddThisNode();
void LRD(Node *root);


main(){
	nodes[1].first = 1;
	nodes[1].second = new Node(1);
	cin >> total_number;
	for(int i = 1; i <= total_number; ++i){
		cin >> number >> leftchild >> rightchild;
		AddThisNode();
	}
	for(int i = 1; i <= total_number; ++i)
		cout << nodes[i].first << ' ';
	cout << '\n';
	LRD(nodes[1].second);
}

void AddThisNode(){
	if(leftchild > 0){
		nodes[leftchild].second = nodes[number].second->left_ = new Node(leftchild);
		nodes[leftchild].first = 2 * nodes[number].first;
	}
	if(rightchild > 0){
		nodes[rightchild].second = nodes[number].second->right_ = new Node(rightchild);
		nodes[rightchild].first = 2 * nodes[number].first + 1;
	}
}

void LRD(Node *root){
	if(root->left_)
		LRD(root->left_);
	if(root->right_)
		LRD(root->right_);
	cout << root->number_ << ' ';
}
