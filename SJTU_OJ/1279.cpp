#include <iostream>
using namespace std;
int numbers[10000000] = {};
main(){
	int change[128] = {};
	change['1'] = 1;
	change['2'] = change['A'] = change['B'] = change['C'] = 2;
	change['3'] = change['D'] = change['E'] = change['F'] = 3;
	change['4'] = change['G'] = change['H'] = change['I'] = 4;
	change['5'] = change['J'] = change['K'] = change['L'] = 5;
	change['6'] = change['M'] = change['N'] = change['O'] = 6;
	change['7'] = change['P'] = change['R'] = change['S'] = 7;
	change['8'] = change['T'] = change['U'] = change['V'] = 8;
	change['9'] = change['W'] = change['X'] = change['Y'] = 9;
	int n;
	cin >> n;
	int tmp_num = 0 ;
	char num_char[10000];
	for(int i = 0; i < n; ++i, tmp_num = 0){
		cin >> num_char;
		for(int j = 0; num_char[j]; ++j)
			if(num_char[j] != '-')
				tmp_num = tmp_num * 10 + change[num_char[j]];
		++numbers[tmp_num];
	}
	int flag = 0;
	for(int i = 0; i < 10000000; ++i)
		if(numbers[i] > 1){
			char output[10] = {};
			int num = i;
			for(int j = 7; j >= 0; --j){
				if(j == 3){
					output[j] = '-';
					continue;
				}
				output[j] = num % 10 + '0';
				num /= 10;
			}
			cout << output << ' ' << numbers[i] << '\n';
			flag = 1;
		}
	if(!flag)
		cout << "No duplicates.";
}