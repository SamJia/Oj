#include <iostream>
using namespace std;
int total_number, number_on_paper[120] = {}, tmp, result = 0;

bool IsNew(int number){
	for(int i = 0; i < total_number; ++i)
		if(number == number_on_paper[i])
			return 0;
	return 1;
}

main(){
	cin >> total_number;
	for(int i = 0; i < total_number; ++i){
		cin >> number_on_paper[i];
	}
	for(int i = 0; i < total_number; ++i){
		for(int j = 0; j < total_number; ++j)
			if(i != j){
				tmp = max(number_on_paper[i], number_on_paper[j]) / min(number_on_paper[i], number_on_paper[j]);
				if(IsNew(tmp))
					number_on_paper[total_number++] = tmp;
			}
	}
	cout << total_number;
}