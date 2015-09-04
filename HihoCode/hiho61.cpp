#include <cstdio>
#define SIZE 50100

struct Node
{
	int low_, high_, add_, acc_;
	Node *left_, *right_;
	int value_;
	bool reset_;
	Node(int low, int high) : low_(low), high_(high), add_(0), acc_(0),
		left_(NULL), right_(NULL), value_(-1), reset_(false){}
};

char str[SIZE], tmp_str[10], para_char;
int total_string_length, total_command_number;
int head = 0, command, para1, para2, para3, pos;
Node *root;

Node *CreateTree(int low, int high){
	// printf("create tree\n");
	Node *node = new Node(low, high);
	if (low == high)
		node->value_ = str[low] - 'A';
	else{
		node->left_ = CreateTree(low, (low + high) / 2);
		node->right_ = CreateTree((low + high) / 2 + 1, high);
	}
	return node;
}

void Down(Node *root){
	// printf("Down:  low:%d,high:%d,reset:%d\n", root->low_, root->high_, root->reset_);
	if(root->reset_){
		root->add_ = root->acc_ = 0;
		root->reset_ = false;
		if(root->left_){
			root->left_->reset_ = root->right_->reset_ = true;
			root->left_->value_ = root->right_->value_ = root->value_;
		}
	}
	else if(root->left_){
		if(root->left_->reset_)
			Down(root->left_);
		if(root->right_->reset_)
			Down(root->right_);
		root->left_->add_ += root->add_;
		root->left_->acc_ += root->acc_;
		root->right_->add_ += root->add_ + root->acc_ * (root->right_->low_ - root->low_);
		root->right_->acc_ += root->acc_;
		root->add_ = root->acc_ = 0;
	}
}

void Reset(Node *root, int low, int high, char target){
	// if(root->reset_)
	Down(root);
	// printf("get in reset\n");
	if(root->high_ < low || root->low_ > high)
		return;
	else if(root->low_ >= low && root->high_ <= high){
		root->value_ = target - 'A';
		// printf("low:%d,high:%d\n", root->low_, root->high_);
		root->reset_ = true;
	}
	else{
		// printf("next level\n");
		Reset(root->left_, low, high, target);
		Reset(root->right_, low, high, target);
	}
}


void Add(Node *root, int low, int high, int add, int acc){
	// if(root->reset_)
	Down(root);
	if(root->high_ < low || root->low_ > high)
		return;
	else if(root->low_ >= low && root->high_ <= high){
		// printf("%d %d\n", root->low_, root->high_);
		root->add_ += add + (root->low_ - low) * acc;
		root->acc_ += acc;
	}
	else{
		Add(root->left_, low, high, add, acc);
		Add(root->right_, low, high, add, acc);
	}
}

void Print(Node *root/*, int add = 0, int acc = 0*/){
	// printf("start print\n");
	// if(root->reset_)
	Down(root);
	// if(root->value_ >= 0){
	// 	value = root->value_;
	// 	add = acc = 0;
	// }
	if(root->left_){
		Print(root->left_/*, root->add_ + add, root->acc_ + acc*/);
		Print(root->right_/*, root->add_ + add + (root->acc_ + acc) * (root->right_->low_ - root->low_),
			 root->acc_ + acc*/);
	}
	else{
		// printf("root value:%d\n", root->value_);
		// printf("reset_:%d,value_:%d,add_:%d,acc_:%d\n", root->reset_, root->value_, root->add_, root->acc_);
		pos = root->low_ - head;
		if(pos < 0)
			pos += total_string_length;
		str[pos] = (root->value_/* + add*/ + root->add_/* + acc*/ + root->acc_) % 26 + 'A';
		// printf("%c", (root->value_ + add + acc) % 26 + 'A');
	}
}

int main(){
	scanf("%d%d", &total_string_length, &total_command_number);
	scanf("%s", str);
	root = CreateTree(0, total_string_length - 1);
	// printf("create tree done\n");
	int low, high;
	for(int i = 0; i < total_command_number; ++i){
		// printf("start scanf\n");
		scanf("%s%d", tmp_str, &command);
		// printf("command is %d\n", command);
		if(command == 1){
			scanf("%d%d %c", &para1, &para2, &para_char);
			low = head + para1 - 1;
			high = head + para2 - 1;
			if (low >= total_string_length)
				Reset(root, low % total_string_length, high % total_string_length, para_char);
			else if (high >= total_string_length){
				Reset(root, low, total_string_length - 1, para_char);
				Reset(root, 0, high % total_string_length, para_char);
			}
			else
				Reset(root, low, high, para_char);
		}
		else if(command == 2){
			scanf("%d%d%d", &para1, &para2, &para3);
			low = head + para1 - 1;
			high = head + para2 - 1;
			if (low >= total_string_length)
				Add(root, low % total_string_length, high % total_string_length, para3, 0);
			else if (high >= total_string_length){
				Add(root, low, total_string_length - 1, para3, 0);
				Add(root, 0, high % total_string_length, para3, 0);
			}
			else
				Add(root, low, high, para3, 0);
		}
		else if(command == 3){
			scanf("%d", &para1);
			head = (head + para1) % total_string_length;
		}
		else if(command == 4){
			scanf("%d%d", &para1, &para2);
			low = head + para1 - 1;
			high = head + para2 - 1;
			if (low >= total_string_length)
				Add(root, low % total_string_length, high % total_string_length, 0, 1);
			else if (high >= total_string_length){
				// printf("%d %d\n", low, total_string_length-1);
				Add(root, low, total_string_length-1, 0, 1);
				// printf("%d %d\n", 0, high % total_string_length);
				Add(root, 0, high % total_string_length, total_string_length - low, 1);
			}
			else
				Add(root, low, high, 0, 1);
		}
	}
	Print(root);
	printf("%s\n", str);
}