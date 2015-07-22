#include <iostream>
#include <cstring>
#define SIZE1 10010
#define SIZE2 1000010
using namespace std;

char pattern_string[SIZE1], origin_string[SIZE2];
int next_array[SIZE1];
int total_test_number, pattern_length, origin_length;

void GetNextArray();
int FindMatchNumber();

int main(){
	cin >> total_test_number;
	for(int i = 0; i < total_test_number; ++i){
		cin >> pattern_string >> origin_string;
		pattern_length = strlen(pattern_string);
		origin_length = strlen(origin_string);
		GetNextArray();
		cout << FindMatchNumber() << '\n';
	}
	return 0;
}

void GetNextArray(){
	next_array[0] = -1;
	next_array[1] = 0;
	for(int i = 2, j; i <= pattern_length; ++i){
		for(j = next_array[i-1]; j >= 0; j = next_array[j])
			if(pattern_string[j] == pattern_string[i-1])
				break;
		next_array[i] = j + 1;
	}
	// for(int i = 0; i <= pattern_length; ++i)
	// 	cout << next_array[i] << ' ';
}

int FindMatchNumber(){
	int result = 0;
	for(int pattern_pos = 0, origin_pos = 0; origin_pos <= origin_length; ){
		// cout << pattern_pos << ' ' << origin_pos << '\n';
		if(pattern_pos == pattern_length){
			pattern_pos = next_array[pattern_pos];
			++result;
		}
		else if(pattern_pos == -1 || pattern_string[pattern_pos] == origin_string[origin_pos]){
			++pattern_pos;
			++origin_pos;
		}
		else
			pattern_pos = next_array[pattern_pos];
	}
	return result;
}