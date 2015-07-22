#include <cstdio>
#define SIZE 100100

struct Node
{
	Node(int number = 0, Node *next = NULL) : number_(number), next_(next){}
	int number_;
	Node *next_;
};
Node link[SIZE] = {};

int link_number[SIZE] = {}, leaf_heap[SIZE], stack[SIZE];
bool distinct[] = {};
int total_node_number = 1, heap_size = 1, stack_size = 0;

void Input();
void Init();
void Output();

int main(){
	Input();
	Init();
	Output();
	return 0;
}

void Input(){
	char tmp_char;
	int tmp_number, bracket_number = 1;
	scanf(" %c%d", &tmp_char, &tmp_number);
	stack[stack_size++] = tmp_number;
	while(bracket_number){
		scanf(" %c", &tmp_char);
		if(tmp_char == '('){
			scanf("%d", &tmp_number);
			total_node_number++;
			// fathers[tmp_number] = stack[stack_size-1];
			link[tmp_number].next_ = new Node(stack[stack_size-1], link[tmp_number].next_);
			link[stack[stack_size-1]].next_ = new Node(tmp_number, link[stack[stack_size-1]].next_);
			link_number[tmp_number]++;
			link_number[stack[stack_size-1]]++;
			stack[stack_size++] = tmp_number;
			bracket_number++;
		}
		else{
			stack_size--;
			bracket_number--;
		}
	}
}

void Init(){
	int tmp;
	// for(int i = 1; i <= total_node_number; ++i)
	// 	printf("%d ", fathers[i]);
	// printf("\n");
	for(int i = 1; i <= total_node_number; ++i)
		if(link_number[i] == 1)
			leaf_heap[heap_size++] = i;
}

void Output(){
	int tmp, linked_node;
	for(; total_node_number > 1; --total_node_number){
		// for(int i = 1; i < heap_size; ++i)
		// 	printf("%d ", leaf_heap[i]);
		// printf("\n");
		distinct[leaf_heap[1]] = true;
		for(Node *p = link[leaf_heap[1]].next_; p && distinct[linked_node = p->number_]; p = p->next_);
		printf("%d ", linked_node);
		link_number[linked_node]--;
		if(link_number[linked_node] == 1)
			leaf_heap[1] = linked_node;
		else
			leaf_heap[1] = leaf_heap[--heap_size];
		for(int i = 1, j = 2; j < heap_size; i = j, j = i << 1){
			if(j + 1 < heap_size && leaf_heap[j+1] < leaf_heap[j])
				j++;
			if(leaf_heap[i] > leaf_heap[j]){
				tmp = leaf_heap[i];
				leaf_heap[i] = leaf_heap[j];
				leaf_heap[j] = tmp;
			}
			else
				break;
		}
	}
}