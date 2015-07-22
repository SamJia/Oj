#include <iostream>
using namespace std;

main(){
	int total_number, list[110000] = {}, result = 1;
	cin >> total_number;
	for(int i = 0; i < total_number; ++i)
		cin >> list[i];
	for(int i = 1; i < total_number; ++i)
		if(list[i] >= list[i - 1]){
			++result;
		}
	cout << result - 1;
}