#include <iostream>
#include <fstream>
#define MAX_MONKEY 10010
using namespace std;
struct Monkey{
	int number;
	Monkey *before, *next;
};
int number_of_monkey, list[MAX_MONKEY];
Monkey *head = new Monkey, *p;
// ifstream fin("1038.txt");

void Input(){
	cin >> number_of_monkey;
	p =head;
	p->number = 1;
	for(int i = 0; i < number_of_monkey - 1; ++i){
		p->next = new Monkey;
		p->next->before = p;
		p = p->next;
		p->number = i + 2;
		cin >> list[i];
	}
	p->next = head;
	head->before = p;
}

void MonkeyJosephus(){
	int num = 0, total = 0;
	for(int i = 0; i < number_of_monkey - 1; ++i){
		total = number_of_monkey - i;
		num = (list[i] - 1) % total;
		if(2*num < total)
			for(; num; p=p->next)
				--num;
		else
			for(; num < total; p=p->before)
				++num;
		p->next = p->next->next;
		p->next->before = p;
	}
}

void Output(){
	cout << p->number;
}

main(){
	Input();
	MonkeyJosephus();
	Output();
}