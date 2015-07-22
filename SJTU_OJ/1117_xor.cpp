#include <cstdio>
#define SIZE 100100

int link[SIZE] = {}, link_number[SIZE] = {}, stack[SIZE];
int total_node_number = 1, stack_size = 0;


void Input();
void Output();

int main(){
	Input();
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
			link[tmp_number] ^= stack[stack_size-1];
			link[stack[stack_size-1]] ^= tmp_number;
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

void Output(){
	for(int i = 1, deleted_node = i, link_node; i <= total_node_number; deleted_node = ++i){
		if(link_number[i] == 1){
			do{
				link_node = link[deleted_node];
				printf("%d ", link_node);
				link[link_node] ^= deleted_node;
				link_number[link_node]--;
				deleted_node = link_node;
			}
			while(deleted_node < i && link_number[deleted_node] == 1);
		}
	}
}