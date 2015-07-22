#include <iostream>
using namespace std;
#define MAX 
#define SIZE 

int total_number, card[SIZE], saved[SIZE] = {};
main(){
	cin >> total_number;
	for(int i = 0; i < total_number; ++i)
		cin >> card[i];
	saved[total_number] = 1;
	for(int i = total_number - 1; i >= 0; --i){
		int num = 0, res = 0;
		for(int j = i; j < total_number; ++j){
			num += card[j];
			if(num >= 0)
				res = (res + saved[j + 1]) % MAX;
		}
		saved[i] = res;
	}

	cout << saved[0];
}