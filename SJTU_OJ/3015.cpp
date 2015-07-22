#include <cstdio>
#define SIZE 101000
int star_number, command_number, count = 0, star1, star2, father[SIZE];
char command;
bool star[SIZE] = {};

int root(int one_star){
	if(father[one_star] != one_star)
		father[one_star] = root(father[one_star]);
	return father[one_star];
}

int main(){
	for(int i = 1; i < SIZE; ++i)
		father[i] = i;
	scanf("%d%d", &star_number, &command_number);
	for(int i = 0; i < command_number; ++i){
		scanf("\n%c", &command);
		if(command == 'a'){
			scanf("%d%d", &star1, &star2);
			if(root(star1) != root(star2)){
				if(!star[star1] && !star[star2])
					++count;
				else if(star[star1] && star[star2])
					--count;
				star[star1] = star[star2] = true;
				father[root(star1)] = root(star2);
			}
		}
		else if(command == 'b'){
			printf("%d\n", count);
		}
		else{
			scanf("%d%d", &star1, &star2);
			if(root(star1) == root(star2))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}