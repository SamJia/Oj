#include <cstdio>
#include <iostream>
using namespace std;
#define GNUM first
#define FATHER first
#define TYPE second
#define DIFF second
int total_number, command_number, result = 0;
int command, ani1, ani2, group_number = 1;
pair<int, int> animal[50010], group[25010];

pair<int, int> root(int g_num){
	if(group[g_num].FATHER != g_num){
		pair<int, int> father = root(group[g_num].FATHER);
		group[g_num].FATHER = father.FATHER;
		group[g_num].DIFF = (group[g_num].DIFF + father.DIFF) % 3;
	}
	return group[g_num];
}


bool link(int an1, int greater, int an2){
	if(!animal[an1].GNUM && !animal[an2].GNUM){
		animal[an1].GNUM = animal[an2].GNUM = group_number++;
		animal[an1].DIFF = greater;
	}
	else if(!animal[an1].GNUM){
		animal[an1].GNUM = animal[an2].GNUM;
		animal[an1].DIFF = (animal[an2].DIFF + greater) % 3;
	}
	else if(!animal[an2].GNUM){
		animal[an2].GNUM = animal[an1].GNUM;
		animal[an2].DIFF = (animal[an1].DIFF - greater) % 3;
		animal[an2].DIFF += (animal[an2].DIFF < 0 ? 3 : 0);
	}
	else{
		pair<int, int> g1 = root(animal[an1].GNUM), g2 = root(animal[an2].GNUM);
		int type1 = (animal[an1].TYPE + g1.TYPE) % 3, type2 = (animal[an2].TYPE + g2.TYPE) % 3;
		type1 += (type1 < 0 ? 3 : 0);
		type2 += (type2 < 0 ? 3 : 0);
		if(g1.FATHER != g2.FATHER){
			group[g1.FATHER].FATHER = g2.FATHER;
			group[g1.FATHER].DIFF = type2 + greater - type1;
		}
		else if((type2 + greater) % 3 != type1)
			return false;
	}
	return true;
}

int main(){
	scanf("%d%d", &total_number, &command_number);
	for(int i = 0; i < 25010; ++i)
		group[i].FATHER = i;
	for(int i = 0; i < command_number; ++i){
		scanf("%d%d%d", &command, &ani1, &ani2);
		if(ani1 > total_number || ani2 > total_number){
			++result;
			continue;
		}
		if(ani1 == ani2){
			if(command == 2)
				++result;
			continue;
		}
		if(!link(ani1, command - 1, ani2))
			++result;
	}
	printf("%d\n", result);
	return 0;
}