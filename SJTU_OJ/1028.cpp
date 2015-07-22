#include <iostream>
#include <string>
using namespace std;
//---------------------
void input();
void TranslateToNumber(int);
bool CheckWordList(int, int);
bool CheckThisWord(int, int &, int &);
bool CheckIf(int &, int &);
bool CheckElse(int &);
bool CheckBegin(int &);
bool CheckThisComplexSection(int &, int);
void Output(int);
//---------------------
string input_word, word_may_be_input[]={"if","then","else","begin","end"};
int total_number_of_word = 0, word_if = 0, word_then = 1, word_else = 2, word_begin = 3, word_end = 4, word_list[105] = {0};

main(){
	input();
	int right_or_not = CheckWordList(0, total_number_of_word);
	Output(right_or_not);
}

void input(){
	cin >> total_number_of_word;
	for(int i = 0; i < total_number_of_word; ++i){
		cin >> input_word;
		TranslateToNumber(i);
	}
}

void TranslateToNumber(int save_pos){
	for(int i = 0; i < 5; ++i)
		if(word_may_be_input[i] == input_word)
			word_list[save_pos] = i;
}

bool CheckWordList(int begin_pos,int end_pos){
	int if_minus_else = 0, this_word_is_valid = 1;
	for(; begin_pos < end_pos && this_word_is_valid; ++begin_pos)
		this_word_is_valid = CheckThisWord(word_list[begin_pos], begin_pos, if_minus_else);
	return(this_word_is_valid);
}

bool CheckThisWord(int this_word, int &begin_pos, int &if_minus_else){
	if(this_word == word_if)
		return(CheckIf(begin_pos, if_minus_else));
	else if(this_word == word_else)
		return(CheckElse(if_minus_else));
	else if(this_word == word_begin)
		return(CheckBegin(begin_pos));
	return(0);
}

bool CheckIf(int &begin_pos, int &if_minus_else){
	if(word_list[begin_pos + 1] != word_then)
		return(0);
	++if_minus_else;
	++begin_pos;
	return(1);
}

bool CheckElse(int &if_minus_else){
	if(if_minus_else == 0)
		return(0);
	--if_minus_else;
	return(1);
}

bool CheckBegin(int &begin_pos){
	int begin_minus_end = 1;
	for(int end_pos = begin_pos + 1; end_pos < total_number_of_word; ++end_pos){
		if(word_list[end_pos] == word_begin)
			++begin_minus_end;
		else if (word_list[end_pos] == word_end)
			--begin_minus_end;
		if(begin_minus_end == 0)
			return(CheckThisComplexSection(begin_pos, end_pos));
	}
	return(0);
}

bool CheckThisComplexSection(int &begin_pos, int end_pos){
	if(CheckWordList(begin_pos + 1, end_pos) == 0)
		return(0);
	begin_pos = end_pos;
	return(1);
}

void Output(int right_or_not){
	if(right_or_not)
		cout << "YES";
	else
		cout << "NO";
}