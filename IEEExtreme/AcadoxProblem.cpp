#include <cstdio>
#include <cstring>
#define SIZE 100

int dict[1000];

struct Num
{
	Num(char num_string[] = NULL){
		if(num_string == NULL){
			bits[0] = bits[1] = bits[2] = bits[3] = 0;
			return;
		}
		int length = strlen(num_string);
		for(int i = 0; i < 4 - length; ++i)
			bits[i] = 0;
		for(int i = 0; i < length; ++i)
			bits[4 - length + i] = Char2Num(num_string[i]);
	}

	void Print(){
		char tmp[10] = {};
		for(int i = 0; i < 4; ++i)
			tmp[i] = Num2Char(bits[i]);
		printf("%s\n", tmp);
	}

	int Char2Num(char c){
		if(c >= '0' && c <= '9')
			return c - '0';
		else if(c >= 'a' && c <= 'f')
			return c - 'a' + 10;
		else
			return c - 'A' + 10;
	}

	char Num2Char(int num){
		if(num >= 0 && num <= 9)
			return '0' + num;
		else
			return 'A' + num - 10;
	}

	int bits[4];
};

Num stack[SIZE];
int stack_size = 0;

int main(){
	char tmp[10];
	scanf("%s", tmp);
	stack[stack_size++] = tmp;
	stack[0].Print();
}