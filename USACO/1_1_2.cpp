/*
ID: sammail1
PROG: ride
LANG: C++
*/
#include <cstdio>
#define UP 47

char s[100];
int result1 = 1, result2 = 1;

int main(){
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	scanf(" %s", s);
	for(int i = 0; s[i]; ++i)
		result1 = result1 * (s[i] - 'A' + 1) % UP;
	scanf(" %s", s);
	for(int i = 0; s[i]; ++i)
		result2 = result2 * (s[i] - 'A' + 1) % UP;
	if(result1 == result2)
		printf("GO\n");
	else
		printf("STAY\n");
	return 0;
}