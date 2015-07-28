/*
ID: sammail1
PROG: friday
LANG: C++
*/
#include <cstdio>

bool isLeap(int year){
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int days[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int years, day = 0, choice;
int result[10] = {};

int main(){
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	scanf("%d", &years);
	for(int i = 0; i < years; ++i){
		choice = isLeap(1900 + i);
		// printf("year:%d,choice:%d\n", 1900+i, choice);
		for(int j = 0; j < 12; ++j){
			++result[day];
			day = (day + days[choice][j]) % 7;
		}
	}
	// --result[day];
	for(int i = 0; i < 6; ++i)
		printf("%d ", result[i]);
	printf("%d\n", result[6]);
	return 0;
}