#include <iostream>
using namespace std;
#define SIZE 1010000
bool possible[SIZE] = {};
int card[11], card_number;

int main(){
	cin >> card_number;
	for(int i = 0; i < card_number; ++i){
		cin >> card[i];
		if(card[i] == 1){
			cout << 0;
			return 0;
		}
		possible[card[i]] = 1;
	}
	for(int i = 0; i < 1000100; ++i)
		if(possible[i])
			for(int j = 0; j < card_number; ++j)
				possible[i + card[j]] = 1;
	int i;
	for(i = 1000000 ;possible[i]; --i);
	if(i > 100000)
		cout << 0;
	else
		cout << i;
	return 0;
}