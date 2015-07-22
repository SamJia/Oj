#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000009
#define SIZE 1000010
#define SUM first
#define NUM second

struct Node{
	Node(int low, int high) : low_(low), high_(high), data_(0), left_(NULL), right_(NULL){}
	int low_, high_, data_;
	Node *left_, *right_;
}*head;

int total_number;
int card[SIZE], new_sum[SIZE], result[SIZE] = {1};
pair<int, int> sum[SIZE];

void Input();
void CreateTree(Node *root);
void FindResult();
int FindInTree(Node *root, int height);
void ModifyTree(Node *root, int height, int one_result);


main(){
	Input();
	FindResult();
}

void Input(){
	cin >> total_number;
	sum[0].SUM = 0;
	sum[0].NUM = 0;
	for(int i = 1; i <= total_number; ++i){
		cin >> card[i];
		sum[i].SUM = sum[i - 1].SUM + card[i];
		sum[i].NUM = i;
	}
	sort(sum, sum + total_number + 1);
	new_sum[sum[0].NUM] = 0;
	for(int i = 1; i <= total_number; ++i)
		new_sum[sum[i].NUM] = sum[i].SUM == sum[i - 1].SUM ? new_sum[sum[i - 1].NUM] : new_sum[sum[i - 1].NUM] + 1;
	head = new Node(0, new_sum[sum[total_number].NUM]);
	CreateTree(head);
}

void CreateTree(Node *root){
	if(root->low_ != root->high_){
		CreateTree(root->left_ = new Node(root->low_, (root->low_ + root->high_) / 2));
		CreateTree(root->right_ = new Node((root->low_ + root->high_) / 2 + 1, root->high_));
	}
}

void FindResult(){
	ModifyTree(head, new_sum[0], 1);
	for(int i = 1; i <= total_number; ++i){
		result[i] = FindInTree(head, new_sum[i]) % MAX;
		ModifyTree(head, new_sum[i], result[i]);
	}
	cout << result[total_number];
}

int FindInTree(Node *root, int height){
	if(root->low_ == root->high_)
		return root->data_;
	if(height < (root->low_ + root->high_) / 2)
		return FindInTree(root->left_, height);
	if(height > (root->low_ + root->high_) / 2)
		return (root->left_->data_ + FindInTree(root->right_, height)) % MAX;
	return root->left_->data_;
}

void ModifyTree(Node *root, int height, int one_result){
	root->data_ = (root->data_ + one_result) % MAX;
	if(root->low_ != root->high_){
		if(height <= (root->low_ + root->high_) / 2)
			ModifyTree(root->left_, height, one_result);
		else
			ModifyTree(root->right_, height, one_result);
	}
}