#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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

int right(){
	input();
	return CheckWordList(0, total_number_of_word);
}

void input(){
	ifstream fin("1028.txt");
	fin >> total_number_of_word;
	for(int i = 0; i < total_number_of_word; ++i){
		fin >> input_word;
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


//-------------------------------------------------
string str[200];
int arr[200] = {0};
int N, statement = 0;

void input1()
{   
	ifstream fin2("1028.txt");
	fin2 >> N;
	getchar();
	string str0;
	getline(fin2, str0);
	int start = 0, end  = 0, i = 0, len = str0.length();
	while (start < len)
	{
		while (str0[end] != ' ' && end < len) ++end;
		str[i++] = str0.substr(start, end - start);
		start = ++end;
	} N=i;
}
int unknown() 
{
	input();
	int i, j = 0;
	bool flag = true, flag1 = false;
	
	for (i = 0; i < N && flag; ++i)
	{
		if (str[i] == "if")
		{
			if (str[i + 1] == "then") {++i; arr[j++] = 1;}
				else flag = false;
		}
		
		else if (str[i] == "then") flag = false;
		else if (str[i] == "begin") {arr[j++] = 2; ++statement;}
		else if (str[i] == "end")
		{
			for (int k = j - 1; k >= 0; --k)
				if (arr[k] == 2)
				{
					--statement;
					flag1 = true;
					j = k;
					for (; arr[k] != 0; ++k) arr[k] = 0;
					break;
				}
			
			if (flag1) flag1 = false;
				else flag = false;
		}
		
		else
		{
			for (int k = j - 1; k >= 0; --k)
				if (arr[k] == 1)
				{
					flag1 = true;
					j = k;
					for (; arr[k] != 0; ++k) arr[k] = 0;
					break;
				}
			
			if (flag1) flag1 = false;
				else flag = false;
		}
	}
	
	if (statement) flag = false;
	return(flag);
}

main(){
	srand(time(0));
	int num = 0;
	for (int abc = 0; abc < 1000; ++abc){
		ofstream fout("1028.txt");
		num =rand()%100;
		fout << num << '\n';
		for (int j = 0; j < num; ++j){
			fout << word_may_be_input[rand()%5] << ' ';
		}
		fout << '\n';
		if(right() != unknown()){
			cout << 0;
			break;
		}
		else{
			ifstream fin("1028.txt");
			int a;
			fin >> a;
			cout << a << ' ';
			// cout << abc << "right" <<' ';
		}
		fout.close();
	}
}