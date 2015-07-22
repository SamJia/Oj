#include <iostream>
#include <cstring>
#define SIZE 1000010
using namespace std;

char origin_string[SIZE], processed_string[2*SIZE];
int total_string_number, result, half_lens[2];

void Init();
void Process();
int Compute();

int main(){
	cin >> total_string_number;
	Init();
	for(int i = 0; i < total_string_number; ++i){
		cin >> origin_string;
		Process();
		result = Compute();
		cout << result << '\n';
	}
	return 0;
}

void Init(){
	processed_string[0] = '@';
	for(int i = 0; i < SIZE; ++i)
		processed_string[(i<<1)+1] = '#';
}

void Process(){
	for(int i = strlen(origin_string); i >= 0; --i)
		processed_string[(i<<1)+2] = origin_string[i];
	half_lens[0] = 1;//not contain center char
	half_lens[1] = 0;
}

int Compute(){
	int max_half_len = 1;
	for(int i = 3, tmp_half_len; processed_string[i]; ++i){
		tmp_half_len = min(half_lens[i&1], half_lens[(i&1)^1] - 1);
		for(; processed_string[i+tmp_half_len] == processed_string[i-tmp_half_len]; ++tmp_half_len);
		max_half_len = max(max_half_len, --tmp_half_len);
		half_lens[i&1] = tmp_half_len;
	}
	return max_half_len;
}