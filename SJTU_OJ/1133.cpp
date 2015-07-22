#include <iostream>
using namespace std;

char str[1010];
long long little_friend[4] = {}, director[4] = {};

main(){
	cin.getline(str, 1010);
	for(int i = 0; str[i]; ++i){
		if(str[i] == 'S'){
			++little_friend[0];
			++director[0];
		}
		else if(str[i] == 'T'){
			little_friend[1] = min(little_friend[0], little_friend[1] + 1);
			++director[1];
		}
		else if(str[i] == 'A'){
			little_friend[2] = min(little_friend[1], little_friend[2] + 1);
			++director[2];
		}
		else if(str[i] == 'R'){
			little_friend[3] = min(little_friend[2], little_friend[3] + 1);
			++director[3];
		}
	}
	long long tmp = min(director[0], director[1]);
	tmp = min(tmp, director[2]);
	tmp = min(tmp, director[3]);
	cout << (director[0] * director[1] * director[2] * director[3]) << ' ' << tmp << ' ' << little_friend[3];
}