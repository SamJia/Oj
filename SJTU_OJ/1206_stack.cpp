#include "SeqStack.h"
#include "fstream"
#define SIZE 100
//---------------------
void input();
bool CheckWord();
bool CheckNumber(int this_word);
void Output(int right_or_not);
//---------------------

char input_word[SIZE], word_may_be_input[5][SIZE]={{"if"},{"then"},{"else"},{"begin"},{"end"}};
int word_if = 0, word_then = 1, word_else = 2, word_begin = 3, word_end = 4;

// ifstream fin("1206_stack.txt");
SeqStack<int> stack;

main(){
	try{
		while(cin >> input_word)
			if(!CheckWord()){
				Output(false);
				return 0;
			}
		Output(stack.is_empty());
	}
	catch(...){
		Output(false);
	}
	return 0;
}

bool CheckWord(){
	for(int i = 0; i < 5; ++i)
		if(!strcmp(word_may_be_input[i], input_word))
			if (!CheckNumber(i))
				return false;
	return true;
}

bool CheckNumber(int this_word){
	if(this_word == word_then){
		if (stack.pop() != word_if)
			return false;
		stack.push(this_word);
	}
	else if(this_word == word_else){
		if (stack.pop() != word_then)
			return false;
	}
	else if(this_word == word_end){
		for (int tmp = stack.pop(); tmp != word_begin; tmp = stack.pop())
			if (tmp != word_then)
				return false;
	}
	else
		stack.push(this_word);
	return(true);
}

void Output(int right_or_not){
	if(right_or_not)
		cout << "Match!";
	else
		cout << "Error!";
}