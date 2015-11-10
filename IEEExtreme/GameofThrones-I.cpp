#include <cstdio>
#define SIZE 110000

int count[200] = {};
char s[SIZE];

int main(){
	scanf("%s", s);
	for(int i = 0; s[i]; ++i)
		++count[s[i]];
	int odd_count = 0;
	for(int i = 'a'; i <= 'z'; ++i)
		if(count[i] & 1)
			++odd_count;
	if(odd_count <= 1)
		printf("YES\n");
	else
		printf("NO\n");
}