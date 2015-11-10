#include <cstdio>
#define SIZE 1001313

struct Node
{
	int url_;
	Node *prev_, *next_;
	Node(int url = 0) : url_(url), prev_(NULL), next_(NULL){}
};

Node *head, *tail;
Node *nodes[SIZE] = {};
int total_cache, used_cache = 0, total_url, number;
char url[50];

void Init(){
	head = new Node();
	tail = new Node();
	head->next_ = tail;
	tail->prev_ = head;
}

int Hash(char url[]){
	unsigned int result = 0;
	for(int i = 0; url[i]; ++i)
		result = result * 31 + url[i];
	return (result & 0x7fffffff) % SIZE;
}

void Add(Node *node){
	node->prev_ = tail->prev_;
	node->next_ = tail;
	node->prev_->next_ = node;
	node->next_->prev_ = node;
}

void Remove(Node *node){
	node->prev_->next_ = node->next_;
	node->next_->prev_ = node->prev_;
}

void Delete(int number){
	Remove(nodes[number]);
	delete nodes[number];
	nodes[number] = NULL;
}

int main(){
	Init();
	scanf("%d%d", &total_url, &total_cache);
	for(int i = 0; i < total_url; ++i){
		scanf("%s", url);
		number = Hash(url);
		if(!nodes[number]){
			printf("Internet\n");
			if(used_cache < total_cache)
				used_cache++;
			else
				Delete(head->next_->url_);
			Add(nodes[number] = new Node(number));
		}
		else{
			printf("Cache\n");
			Remove(nodes[number]);
			Add(nodes[number]);
		}
	}
}