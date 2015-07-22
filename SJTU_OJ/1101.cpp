#include <iostream>
#include <cstring>
using namespace std;
main(){
	int total_number, length, tail_number, start_pos, transform[] = {0, 1, 3, 6, 0, 5, 1, 8, 6, 5};
	char an_interge[15], result[15];
	cin >> total_number;
	for(int i = 0; i < total_number; ++i){
		cin >> an_interge;
		length = strlen(an_interge);
		tail_number = an_interge[length - 1] - '0';
		result[length] = '\0';
		if(length > 1)
			result[length - 1] = (transform[tail_number] + (an_interge[length - 2] - '0') % 2 * 5) % 10 + '0';
		else
			result[length - 1] = transform[tail_number] + '0';
		for(int j = 0; j < length - 1; ++j){
			result[j] = (an_interge[j] - '0') * (tail_number + 1) % 10 + '0';
		}
		for(start_pos = 0; start_pos < length - 1; ++start_pos)
			if(result[start_pos] != '0')
				break;
		cout << result + start_pos << '\n';
	}
}