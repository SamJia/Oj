#include <cstdio>

struct Node {
	Node(int low = 0, int high = 0) : low_(low), high_(high), left_(NULL), right_(NULL), value_(NULL) {}
	int low_, high_;
	int value_;
	Node *left_, *right_;
};

Node *head[20];
int total_row, total_column;
int total_command;
char command;
int row1, row2, col1, col2;

void CreateTree(Node *p) {
	if (p->low_ < p->high_) {
		p->left_ = new Node(p->low_, (p->low_ + p->high_) / 2);
		CreateTree(p->left_);
		p->right_ = new Node((p->low_ + p->high_) / 2 + 1, p->high_);
		CreateTree(p->right_);
	}
}

int Modify(Node *node, int low, int high, int add_sub){
	int change = 0;
	if(node->low_ > high || node->high_ < low){

	}
	else if(node->low_ >= low && node->high_ <= high){
		change += add_sub * (node->high_ - node->low_ + 1);
	}
	else{
		change += Modify(node->left_, low, high, add_sub);
		change += Modify(node->right_, low, high, add_sub);
	}
	node->value_ += change;
	return change;
}

int Query(Node *node, int low, int high){
	int result = 0;
	// printf("%d %d %d\n", node->low_, node->high_, node->value_);
	if(node->low_ > high || node->high_ < low){

	}
	else if(node->low_ >= low && node->high_ <= high){
		result += node->value_;
	}
	else{
		int tmp_value = (node->value_ - node->left_->value_ - node->right_->value_) / (node->high_ - node->low_ + 1);
		node->left_->value_ += tmp_value * (node->left_->high_ - node->left_->low_ + 1);
		node->right_->value_ += tmp_value * (node->right_->high_ - node->right_->low_ + 1);
		result += Query(node->left_, low, high);
		result += Query(node->right_, low, high);
	}
	return result;
}

int main() {
	scanf("%d%d", &total_row, &total_column);
	for (int i = 1; i <= total_row; ++i) {
		head[i] = new Node(1, total_column);
		CreateTree(head[i]);
	}
	scanf("%d", &total_command);
	for (int i = 0; i < total_command; ++i) {
		scanf(" %c%d%d%d%d", &command, &row1, &col1, &row2, &col2);
		if (command == 'a' || command == 'r') {
			for (int i = row1; i <= row2; ++i)
				Modify(head[i], col1, col2, command == 'a' ? 1 : -1);
		}
		else {
			int result = 0;
			for (int i = row1; i <= row2; ++i){
				int tmp = Query(head[i], col1, col2);
				// printf("query:%d ", tmp);
				result += tmp;
			}
			printf("%d\n", result);
		}
	}
}