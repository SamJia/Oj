#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#define SIZE 110
struct OneSection{
	long long number_;
	char operator_;
	OneSection *next_, *before_;
};
char expression[110] = {'\0'};
OneSection *left_bracket[50] = {NULL};
int left_number = 0, right_number = 0;
OneSection *head = new OneSection, *tail = new OneSection, *bracket[50][2] = {NULL};

void Input();
void DeleteSpace(char expression[]);
void CheckLeftBracket(OneSection *p, int &i);
void CheckRightBracket(OneSection *p, int &i);
long long GetNumber(int &i);
long long Calculate();
void CalculatePower(OneSection *begin_pos, OneSection *end_pos);
long long power(long long num1, long long num2);
void CalculateNegtive(OneSection *begin_pos, OneSection *end_pos);
void CalculateMultiply(OneSection *begin_pos, OneSection *end_pos);
void CalculatePlus(OneSection *begin_pos, OneSection *end_pos);
void Output(long long result);

main(){
	Input();
	long long result = Calculate();
	Output(result);
}

void Input(){
	cin.getline(expression, 110);
	DeleteSpace(expression);
	OneSection *p = head;
	for(int i = 0; expression[i];){
		p->next_ = new OneSection;
		p->next_->before_ = p;
		p = p->next_;
		p->next_ = tail;
		tail->before_ = p;
		CheckLeftBracket(p, i);
		p->number_ = GetNumber(i);
		CheckRightBracket(p, i);
		p->operator_ = expression[i++];
	}
	for(int i = 0; i < right_number; ++i)
		bracket[i][1] = bracket[i][1]->next_;
	bracket[right_number][0] = head->next_;
	bracket[right_number++][1] = tail;
	if(left_number){
		cout << "Error";
		exit(0);
	}
}

void DeleteSpace(char expression[]){
	int i = 0, j = 0;
	for(; expression[i]; ++i)
		if(expression[i] != ' ')
			expression[j++] = expression[i];
	expression[j] = expression[j+1] = '\0';
}

void CheckLeftBracket(OneSection *p, int &i){
	for(;expression[i] == '('; ++i)
		left_bracket[left_number++] = p;
}

void CheckRightBracket(OneSection *p, int &i){
	for(;expression[i] == ')'; ++i){
		if(!left_number){
			cout << "Error";
			exit(0);
		}
		bracket[right_number][0] = left_bracket[--left_number];
		bracket[right_number++][1] = p;
	}
}

long long GetNumber(int &i){
	long long tmp = 0, pos_or_neg = 1;
	if(expression[i] == '-')
		expression[i] = '#';
	for(; expression[i] >= '0' && expression[i] <= '9'; ++i)
		tmp = tmp * 10 + expression[i] - '0';
	return tmp * pos_or_neg;
}

long long Calculate(){
	for(int i = 0; i < right_number; ++i){
		CalculateNegtive(bracket[i][0], bracket[i][1]);
		CalculatePower(bracket[i][0], bracket[i][1]);
		CalculateMultiply(bracket[i][0], bracket[i][1]);
		CalculatePlus(bracket[i][0], bracket[i][1]);
	}
	return head->next_->number_;
}

void CalculatePower(OneSection *begin_pos, OneSection *end_pos){
	OneSection *tmp;
	if(begin_pos->next_ == end_pos)
		return;
	for(OneSection *p = end_pos->before_->before_; p != begin_pos->before_; p = p->before_)
		if(p->operator_ == '^'){
			tmp = p->next_;
			p->number_ = power(p->number_, tmp->number_);
			p->operator_ = tmp->operator_;
			p->next_ = tmp->next_;
			p->next_->before_ = p;
			delete tmp;
		}
}

long long power(long long num1, long long num2){
	if(num1 == 1)
		return 1;
	if(num1 == -1)
		return((num2 % 2) ? -1 : 1);
	long long tmp = 1;
	for(int i = 0; i < num2; ++i)
		tmp *= num1;
	return tmp;
}

void CalculateNegtive(OneSection *begin_pos, OneSection *end_pos){
	OneSection *tmp;
	for(OneSection *p = begin_pos; p != end_pos->before_; )
		if(p->operator_ == '#'){
			tmp = p->next_;
			p->number_ = -tmp->number_;
			p->operator_ = tmp->operator_;
			p->next_ = tmp->next_;
			p->next_->before_ = p;
			delete tmp;
		}
		else
			p = p->next_;
}


void CalculateMultiply(OneSection *begin_pos, OneSection *end_pos){
	OneSection *tmp;
	for(OneSection *p = begin_pos; p->next_ != end_pos;)
		if(p->operator_ == '*' || p->operator_ == '/'){
			tmp = p->next_;
			if(p->operator_ == '/')
				if(tmp->number_ == 0){
					cout << "Error";
					exit(0);
				}
				else 
					p->number_ = p->number_ / tmp->number_;
			else
				p->number_ = p->number_ * tmp->number_;
			p->operator_ = tmp->operator_;
			p->next_ = tmp->next_;
			p->next_->before_ = p;
			delete tmp;
		}
		else
			p = p->next_;
}

void CalculatePlus(OneSection *begin_pos, OneSection *end_pos){
	OneSection *tmp;
	for(OneSection *p = begin_pos; p != end_pos->before_; ){
		tmp = p->next_;
		if(p->operator_ == '+')
			p->number_ = p->number_ + tmp->number_;
		else
			p->number_ = p->number_ - tmp->number_;
		p->operator_ = tmp->operator_;
		p->next_ = tmp->next_;
		p->next_->before_ = p;
		delete tmp;
	}
}

void Output(long long result){
	cout << result;
}