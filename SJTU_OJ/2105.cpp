#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 100010
struct Node{
	Node(int low, int high) : low_(low), high_(high), last_point_(-1), left_(NULL), right_(NULL){}
	int low_, high_, last_point_;
	Node *left_, *right_;
};
pair<int, int> height_to_sort[SIZE], width[SIZE];
int sorted_height[SIZE], total_number, request_height, request_pos, height[SIZE];
Node *head;

void Input();
void CreateTree(Node *root);
void TreeInit(Node *root);
void FindLeftEdge();
void FindRightEdge();
int FindLeft(Node *root);
int FindRight(Node *root);
void AddPoint(Node *root);
void FindResult();


main(){
	Input();
	FindLeftEdge();
	TreeInit(head);
	FindRightEdge();
	FindResult();
}

void Input(){
	cin >> total_number;
	for(int i = 0; i < total_number; ++i){
		cin >> height_to_sort[i].first;
		height_to_sort[i].second = i;
		height[i] = height_to_sort[i].first;
	}
	sort(height_to_sort, height_to_sort + total_number);
	sorted_height[height_to_sort[0].second] = 0;
	for(int i = 1; i < total_number; ++i)
		sorted_height[height_to_sort[i].second] = height_to_sort[i].first ==  height_to_sort[i - 1].first ? sorted_height[height_to_sort[i - 1].second] : sorted_height[height_to_sort[i - 1].second] + 1;
	head = new Node(0, sorted_height[height_to_sort[total_number - 1].second]);
	CreateTree(head);
}

void CreateTree(Node *root){
	if(root->low_ != root->high_){
		CreateTree(root->left_ = new Node(root->low_, (root->low_ + root->high_) / 2));
		CreateTree(root->right_ = new Node((root->low_ + root->high_) / 2 + 1, root->high_));
	}
}

void TreeInit(Node *root){
	root->last_point_ = total_number;
	if(root->left_)
		TreeInit(root->left_);
	if(root->right_)
		TreeInit(root->right_);
}

void FindLeftEdge(){
	for(int i = 0; i < total_number; ++i){
		request_height = sorted_height[i];
		request_pos = i;
		width[i].first = FindLeft(head);
		AddPoint(head);
	}
}

void FindRightEdge(){
	for(int i = total_number - 1; i >= 0; --i){
		request_height = sorted_height[i];
		request_pos = i;
		width[i].second = FindRight(head);
		AddPoint(head);
	}
}

int FindLeft(Node *root){
	if(request_height == root->low_)
		return -1;
	if(request_height <= root->left_->high_)
		return FindLeft(root->left_);
	return max(root->left_->last_point_, FindLeft(root->right_));
}

int FindRight(Node *root){
	if(request_height == root->low_)
		return total_number;
	if(request_height <= root->left_->high_)
		return FindRight(root->left_);
	return min(root->left_->last_point_, FindRight(root->right_));
}

void AddPoint(Node *root){
	root->last_point_ = request_pos;
	if(root->low_ != root->high_)
		AddPoint(request_height <= (root->low_ + root->high_) / 2 ? root->left_ : root->right_);
}

void FindResult(){
	long long max_s = 0;
	for(int i = 0; i < total_number; ++i){
		// cout << width[i].second << ' ' << width[i].first << '\n';
		max_s = max(max_s, (long long)height[i] * (width[i].second - width[i].first - 1));
	}
	cout << max_s;
}