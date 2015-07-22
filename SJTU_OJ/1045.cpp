#include <cstdio>
#define SIZE 200010
int father[SIZE] = {0, 1}, son[SIZE] = {}, l_brother[SIZE] = {}, r_brother[SIZE] = {};
int command_number, man, born, family_number = 1;
char command;

int main(){
	scanf("%d", &command_number);
	for(int i = 0; i < command_number; ++i){
		scanf("\n%c", &command);
		if(command == 'B'){
			scanf("%d%d", &man, &born);
			father[born] = man;
			if(son[man]){
				for(man = son[man]; r_brother[man]; man = r_brother[man]);
				r_brother[man] = born;
				l_brother[born] = man;
			}
			else
				son[man] = born;
		}
		else{
			scanf("%d", &man);
			if(father[man] == man)
				--family_number;
			if(son[father[man]] == man)
				son[father[man]] = r_brother[man];
			r_brother[l_brother[man]] = r_brother[man];
			l_brother[r_brother[man]] = l_brother[man];
			for(man = son[man]; man; man = r_brother[man], ++family_number)
				father[man] = man;
			printf("%d\n", family_number);
		}
	}
	return 0;
}