#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 100010
#define POINTS first
#define TIME second

struct Node{
	Node(int low, int high) : low_(low), high_(high), max_time(high), left_(NULL), right_(NULL){}
	int low_, high_, max_time;
	Node *left_, *right_;
};

int backets_number, points[SIZE] = {};
pair<int, int> backets[SIZE] = {};
Node *head = new Node(1, 10000);

void Input();
void CreateTree(Node *root);
void FindMaxPoints();
int FindProperTime(Node *root, int disappear_time);
void ModifyTree(Node *root, int proper_time);
void Output();


main(){
	Input();
	FindMaxPoints();
	Output();
}

void Input(){
	cin >> backets_number;
	for(int i = 0; i < backets_number; ++i)
		cin >> backets[i].POINTS >> backets[i].TIME;
	sort(backets, backets + backets_number);
	CreateTree(head);
}

void CreateTree(Node *root){
	if(root->high_ > root->low_){
		root->left_ = new Node(root->low_, (root->low_ + root->high_) / 2);
		CreateTree(root->left_);
		CreateTree(root->right_ = new Node((root->low_ + root->high_) / 2 + 1, root->high_));
	}
}

void FindMaxPoints(){
	int proper_time;
	for(int i = backets_number - 1; i >= 0; --i){
		proper_time = FindProperTime(head, backets[i].TIME);
		if(proper_time){
			points[proper_time] = backets[i].POINTS;
			ModifyTree(head, proper_time);
		}
	}
}

int FindProperTime(Node *root, int disappear_time){
	if(root->max_time <= disappear_time)
		return root->max_time;
	if(disappear_time <= (root->low_ + root->high_) / 2)
		return FindProperTime(root->left_, disappear_time);
	if(disappear_time > (root->low_ + root->high_) / 2)
		return max(FindProperTime(root->right_, disappear_time), root->left_->max_time);
}

void ModifyTree(Node *root, int proper_time){
	if(root->low_ == root->high_){
		root->max_time = 0;
		return;
	}
	else if(proper_time <= (root->low_ + root->high_) / 2)
		ModifyTree(root->left_, proper_time);
	else
		ModifyTree(root->right_, proper_time);
	root->max_time = max(root->left_->max_time, root->right_->max_time);
}

void Output(){
	int result = 0;
	for(int i = 1; i <= 10000; ++i)
		result += points[i];
	cout << result;
}