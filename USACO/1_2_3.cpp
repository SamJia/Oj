/*
ID: sammail1
PROG: namenum
LANG: C++
*/
#include <cstdio>
#include <cstring>
#define SIZE 20
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

char numbers[SIZE], chars[SIZE], map[200];
bool exist = false;

void Init(){
	map['A'] = map['B'] = map['C'] = '2';
	map['D'] = map['E'] = map['F'] = '3';
	map['G'] = map['H'] = map['I'] = '4';
	map['J'] = map['K'] = map['L'] = '5';
	map['M'] = map['N'] = map['O'] = '6';
	map['P'] = map['R'] = map['S'] = '7';
	map['T'] = map['U'] = map['V'] = '8';
	map['W'] = map['X'] = map['Y'] = '9';
	map['Q'] = map['Z'] = '1';
}

bool Check(){
	if(strlen(numbers) != strlen(chars))
		return false;
	for(int i = 0; chars[i]; ++i)
		if(map[chars[i]] != numbers[i])
			return false;
	exist = true;
	return true;
}

int main(){
	Init();
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	scanf("%s", numbers);
	freopen("dict.txt", "r", stdin);
	while(scanf("%s", chars) != EOF){
		if(Check())
			printf("%s\n", chars);
	}
	if(!exist)
		printf("NONE\n");
	return 0;
}