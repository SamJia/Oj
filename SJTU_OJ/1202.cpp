#include <iostream>
using namespace std;
struct OneBit{
	int number_;
	OneBit *next_;
	OneBit(int number = 0) : number_(number), next_(NULL){}
};

OneBit *head1 = new OneBit, *head2 = new OneBit, *head3 = new OneBit;

void Input(OneBit *head){
	char one_bit;
	OneBit *p;
	for(cin >> one_bit; one_bit != '\n'; cin >> one_bit){
		p = new OneBit(one_bit - '0');
		p->next_ = head->next_;
		head->next_ = p;
	}
}

void Calculate(){
	OneBit *p = head1->next_, *q = head2->next_, *r;
	int state = 0, result;
	for(;p || q;){
		if(!p){
			
		}
	}
}
main()
{	Input(head1);
	Input(head2);
	Calculate();
	Output(head3);
}

