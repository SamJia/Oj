#include <iostream>
#include <fstream>
using namespace std;
//-------------------------------
struct LenAndNum{
	int length;
	long long number;
} len_num_init = {0, 1};
long long infemum, superimum;
LenAndNum max_list_found[200020] = {len_num_init};
//-------------------------------
void Input();
LenAndNum FindBestBegin();
LenAndNum FindLongestList(int);
void UpdateTempAnswer(LenAndNum &, LenAndNum);
void SaveAnswer(int, LenAndNum);
void Output(LenAndNum);
//-------------------------------

main(){
	Input();
	LenAndNum result = FindBestBegin();
	Output(result);
}

void Input(){
	cin >> infemum >> superimum;
}

LenAndNum FindBestBegin(){
	LenAndNum result = len_num_init;
	for(int best_begin = infemum; best_begin <= min(2 * infemum, superimum); ++best_begin)
		UpdateTempAnswer(result, FindLongestList(best_begin));
	return(result);
}

LenAndNum FindLongestList(int begin_number){
	if(!max_list_found[begin_number].length){
		LenAndNum max_list_now = len_num_init, max_list_tmp;
		int next_number = 0;
		for(int i = 101; (begin_number * i <= 100 * superimum) && (i < 201); ++i)
			if((begin_number * i) % 100 == 0){
				next_number = begin_number * i / 100;
				max_list_tmp = FindLongestList(next_number);
				UpdateTempAnswer(max_list_now, max_list_tmp);
			}
		SaveAnswer(begin_number, max_list_now);
	}
	return(max_list_found[begin_number]);
}

void UpdateTempAnswer(LenAndNum &max_list_now, LenAndNum max_list_tmp){
	if(max_list_tmp.length == max_list_now.length)
		max_list_now.number +=max_list_tmp.number;
	else if(max_list_tmp.length > max_list_now.length)
		max_list_now = max_list_tmp;
}

void SaveAnswer(int begin_number, LenAndNum max_list_now){
	max_list_found[begin_number].length = max_list_now.length + 1;
	max_list_found[begin_number].number = max_list_now.number;
}

void Output(LenAndNum result){
	cout << result.length << '\n' << result.number << '\n';
}
