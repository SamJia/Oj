#include "cstdio"

class SearchTree
{
public:

	struct Node
	{
		Node(int number = 0x7fffffff) : number_(number), l_son_(NULL), r_son_(NULL){}
		void DeleteSon(){
			if(l_son_)
				delete l_son_;
			if(r_son_)
				delete r_son_;
		}
		int number_;
		Node *l_son_, *r_son_;
	};

	
	SearchTree() : head_(new Node()){}
	~SearchTree(){
		head_->DeleteSon();
		delete head_;
	}
	void Insert(int number){
		Node *p = head_, *q = head_->l_son_;
		for(; q;){
			if(q->number_ == number)
				return;
			p = q;
			if(q->number_ < number)
				q = q->r_son_;
			else
				q = q->l_son_;
		}
		if(p->number_ >= number)
			p->l_son_ = new Node(number);
		else
			p->r_son_ = new Node(number);
	}
	void Remove(int number){
		Node *p = head_, *q = head_->l_son_;
		for(; q && q->number_ != number;){
			p = q;
			if(q->number_ < number)
				q = q->r_son_;
			else
				q = q->l_son_;
		}
		if(q == NULL)
			return;
		if(q->l_son_ && q->r_son_){
			Node *p2 = q, *q2 = q->l_son_;
			for(; q2->r_son_; p2 = q2, q2 = q2->r_son_);
			q->number_ = q2->number_;
			if(p2->l_son_ == q2)
				p2->l_son_ = q2->l_son_;
			else
				p2->r_son_ = q2->l_son_;
			delete q2;
		}
		else{
			Node *new_node = NULL;
			if(q->l_son_)
				new_node = q->l_son_;
			else if(q->r_son_)
				new_node = q->r_son_;

			if(p->l_son_ == q)
				p->l_son_ = new_node;
			else
				p->r_son_ = new_node;
			delete q;
		}
	}
	bool Find(int number){
		for(Node *p = head_->l_son_; p;){
			if(p->number_ == number)
				return true;
			else if(p->number_ < number)
				p = p->r_son_;
			else
				p = p->l_son_;
		}
		return false;
	}
	void Output(){
		if(head_->l_son_)
			Output(head_->l_son_);
		printf("\n");
	}

	void Output(Node *p){
		if(p->l_son_)
			Output(p->l_son_);
		printf("%d ", p->number_);
		if(p->r_son_)
			Output(p->r_son_);
	}
	Node *head_;

};

int total_number, set_number, parameter;
char command;
SearchTree *tree = new SearchTree();
SearchTree *new_tree = new SearchTree();

int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i){
		scanf(" %c%d", &command, &set_number);
		for(int j = 0; j < set_number; ++j){
			scanf("%d", &parameter);
			if(command == '+')
				tree->Insert(parameter);
			else if(command == '-')
				tree->Remove(parameter);
			else if(command == '*'){
				if(tree->Find(parameter))
					new_tree->Insert(parameter);
			}
		}
		if(command == '*'){
			delete tree;
			tree = new_tree;
			new_tree = new SearchTree();
		}
		tree->Output();
	}
	return 0;
}