#include <cstdio>
#include <ctime>
#include <cstdlib>

int main(){
	srand(time(0));
	printf("%d\n", 800);
	for(int i = 0; i < 800; ++i)
		printf("%d ", rand()%200);
}