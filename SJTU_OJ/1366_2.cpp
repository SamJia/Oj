#include <cstdio>
#define SIZE 27
#define WORD_LEN 1100000

struct Node{
	Node() : number_(0), pos_in_dic_(-1){
		for(int i = 0; i < SIZE; ++i)
			next_[i] = NULL;
	}
	int number_, pos_in_dic_;
	Node *next_[SIZE];
};

Node *head = new Node();
int total_word_number, total_query_number;
char word[WORD_LEN];

void AddWord(int pos_in_dic);
int QueryWord(int pos_in_dic);
int FindWordPos(Node *root, int pos);

int main(){
	scanf("%d%d", &total_word_number, &total_query_number);
	for(int i = 1; i <= total_word_number; ++i){
		scanf("%s", &word);
		AddWord(i);
	}
	int pos;
	for(int i = 0; i < total_query_number; ++i){
		scanf("%d%s", &pos, &word);
		printf("%d\n", QueryWord(pos));
	}
	return 0;
}

void AddWord(int pos_in_dic){
	Node *p = head;
	for(int i = 0; word[i]; p = p->next_[word[i]-'a'], ++p->number_, ++i)
		if(!p->next_[word[i]-'a'])
			p->next_[word[i]-'a'] = new Node();
	p->pos_in_dic_ = pos_in_dic;
}

int QueryWord(int pos_in_dic){
	Node *p = head;
	for(int i = 0; word[i]; p = p->next_[word[i]-'a'], ++i)
		if(!p->next_[word[i]-'a'])
			return -1;
	if(p->number_ < pos_in_dic)
		return -1;
	return FindWordPos(p, pos_in_dic);
}

int FindWordPos(Node *root, int pos){
	if(root->pos_in_dic_ > 0)
		return root->pos_in_dic_;
	int count = 0;
	for(int i = 0; i < 26; ++i){
		if(root->next_[i]){
			if(count + root->next_[i]->number_ >= pos)
				return FindWordPos(root->next_[i], pos - count);
			count += root->next_[i]->number_;
		}
	}
}