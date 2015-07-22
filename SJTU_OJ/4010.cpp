/****************************************
*                                       *
*     Copyright:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
#include <fstream>
using namespace std;
//--------------------------
struct Child{
	int patience, number;
	Child *next, *before;
} *head = new Child;
int number_of_children;
//--------------------------
void Input();
int FindMostPatient();
void PerOperate(int remain_number);
void DeleteOneChild();
void Output(int most_patient);
//--------------------------

main(){
	Input();
	int most_patient = FindMostPatient();
	Output(most_patient);
}

void Input(){
	cin >> number_of_children;
	Child *p = head;
	for (int i = 0; i < number_of_children; ++i){
		p->next = new Child;
		p->next->before = p;
		p = p->next;
		p->number = i + 1;
		cin >> p->patience;
	}
	p->next = head->next;
	p->next->before = p;
	head->before = p;
}

int FindMostPatient(){
	for(int i = number_of_children; i > 1; --i){
		PerOperate(i);
		DeleteOneChild();
	}
	return(head->next->number);
}

void PerOperate(int remain_number){
	Child *p = head;
	int min_patience = 10000000;
	for (int i = 0; i < remain_number; ++i){
		p = p->next;
		min_patience = min(min_patience, p->patience);
	}
	--min_patience;
	for (int i = 0; i < remain_number; ++i){
		p = p->next;
		p->patience -= min_patience;
	}
}

void DeleteOneChild(){
	static int order = 1;
	static Child *p = head;
	if(order)
		for(p = p->next; p->patience > 1; --p->patience, p = p->next);
	else
		for(p = p->before; p->patience > 1; --p->patience, p = p->before);
	p->before->next = p->next;
	p->next->before = p->before;
	head = p;
	order = !order;
}

void Output(int most_patient){
	cout << most_patient;
}