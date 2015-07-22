#include "iostream"
#include "cstring"
#define SIZE 1010
using namespace std;

int result[SIZE][3] = {}, get_prev[3] = {2, 0, 1}, get_next[3] = {1, 2, 0};
int total_number, length;
char char_list[SIZE];

void Init();
void Compute();

int main(){
	cin >> total_number;
	for(int i = 0; i < total_number; ++i){
		cin >> char_list;
		Init();
		Compute();
		cout << "Case #" << i + 1 << ": " << result[0][length%3] << '\n';
	}
}

void Init(){
	length = strlen(char_list);
	for(int i = 0; i < length; ++i){
		result[i][0] = 0;
		result[i][1] = 1;
	}
}

void Compute(){
	for(int i = 2; i <= length; ++i)
		for(int j = 0; j <= length-i; ++j){
			if(char_list[j] == char_list[j+i-1])
				result[j][i%3] = (result[j][get_prev[i%3]] + result[j+1][get_prev[i%3]] + 1) % 100007;
			else
				result[j][i%3] = (result[j][get_prev[i%3]] + result[j+1][get_prev[i%3]] - result[j+1][get_next[i%3]]) % 100007;
		}
}