#include <iostream>
#define SIZE 27
using namespace std;

struct Node{
	Node() : number_(0){
		for(int i = 0; i < SIZE; ++i)
			next_[i] = NULL;
	}
	int number_;
	Node *next_[SIZE];
};

Node *head = new Node();
int total_word_number, total_query_number;
char word[SIZE] = {};

void AddWord();
int QueryWord();

int main(){
	cin >> total_word_number;
	for(int i = 0; i < total_word_number; ++i){
		cin >> word;
		AddWord();
	}
	cin >> total_query_number;
	for(int i = 0; i < total_query_number; ++i){
		cin >> word;
		cout << QueryWord() << '\n';
	}
	return 0;
}

void AddWord(){
	Node *p = head;
	for(int i = 0; word[i]; p = p->next_[word[i]-'a'], ++p->number_, ++i)
		if(!p->next_[word[i]-'a'])
			p->next_[word[i]-'a'] = new Node();
}

int QueryWord(){
	Node *p = head;
	for(int i = 0; word[i]; p = p->next_[word[i]-'a'], ++i)
		if(!p->next_[word[i]-'a'])
			return 0;
	return p->number_;
}