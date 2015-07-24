/*
ID: sammail1
PROG: gift1
LANG: C++
*/
#include <cstdio>
#include <cstring>
#define SIZE 20

char person[SIZE][SIZE];
char name[SIZE];
int total_person_number;
int money[SIZE] = {}, para1, para2;

void Modify(int added_money){
	for(int i = 0; i < total_person_number; ++i)
		if(!strcmp(name, person[i])){
			money[i] += added_money;
			return;
		}
}

int main(){
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	scanf("%d", &total_person_number);
	for(int i = 0; i < total_person_number; ++i)
		scanf("%s", person[i]);
	while(true){
		if(scanf("%s", name) == EOF)
			break;
		scanf("%d%d", &para1, &para2);
		if(para2 == 0)
			continue;
		Modify(- para1 / para2 * para2);
		for(int i = 0; i < para2; ++i){
			scanf("%s", name);
			Modify(para1 / para2);
		}
	}
	for(int i = 0; i < total_person_number; ++i)
		printf("%s %d\n", person[i], money[i]);
	return 0;
}