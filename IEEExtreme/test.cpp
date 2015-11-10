#include <cstdio>

union{
	char a;
	int b;
} test1, test2;

int main(){
	test1.b = 0x646362ff;
	test2.b = 0x0fffffff;
	test1.a = 'a';
	test2.a = 'a';
	printf("%c %c %c %c \n", test1);
}