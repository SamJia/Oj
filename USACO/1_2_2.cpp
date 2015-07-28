/*
ID: sammail1
PROG: transform
LANG: C++
*/
#include <cstdio>
#define SIZE 15
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

char before[SIZE][SIZE], after[SIZE][SIZE];
int total_length;

bool check1(){
	for(int i = 0; i < total_length; ++i)
		for(int j = 0; j < total_length; ++j)
			if(before[i][j] != after[j][total_length - i - 1])
				return false;
	return true;
}
bool check2(){
	for(int i = 0; i < total_length; ++i)
		for(int j = 0; j < total_length; ++j)
			if(before[i][j] != after[total_length - i - 1][total_length - j - 1])
				return false;
	return true;
}
bool check3(){
	for(int i = 0; i < total_length; ++i)
		for(int j = 0; j < total_length; ++j)
			if(before[i][j] != after[total_length - j - 1][i])
				return false;
	return true;
}
bool check4(){
	for(int i = 0; i < total_length; ++i)
		for(int j = 0; j < total_length; ++j)
			if(before[i][j] != after[i][total_length - j - 1])
				return false;
	return true;
}
bool check5(){
	bool result1 = true, result2 = true, result3 = true;
	for(int i = 0; i < total_length; ++i)
		for(int j = 0; j < total_length; ++j)
			if(before[i][j] != after[total_length - j - 1][total_length - i - 1])
				result1 = false;
	for(int i = 0; i < total_length; ++i)
		for(int j = 0; j < total_length; ++j)
			if(before[i][j] != after[total_length - i - 1][j])
				result2 = false;
	for(int i = 0; i < total_length; ++i)
		for(int j = 0; j < total_length; ++j)
			if(before[i][j] != after[j][i])
				result3 = false;
	return result1 || result2 || result3;
}
bool check6(){
	for(int i = 0; i < total_length; ++i)
		for(int j = 0; j < total_length; ++j)
			if(before[i][j] != after[i][j])
				return false;
	return true;
}

int main(){
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	scanf("%d", &total_length);
	for(int i = 0; i < total_length; ++i)
		scanf("%s", before[i]);
	for(int i = 0; i < total_length; ++i)
		scanf("%s", after[i]);
	if(check1())
		printf("1\n");
	else if(check2())
		printf("2\n");
	else if(check3())
		printf("3\n");
	else if(check4())
		printf("4\n");
	else if(check5())
		printf("5\n");
	else if(check6())
		printf("6\n");
	else
		printf("7\n");
	return 0;
}