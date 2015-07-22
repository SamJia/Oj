#include <iostream>
using namespace std;
#define SIZE 100000000;

int data[2010][1010], N, F, cows[2010];

int Find(int pos, int remain){
	if(data[pos][remain] == -1)
		data[pos][remain] = (Find(pos + 1, remain) + Find(pos + 1, (remain - cows[pos]) < 0 ? (remain - cows[pos] + F) : (remain - cows[pos]))) % SIZE;
	return data[pos][remain];
}



main(){
	cin >> N >> F;
	for(int i = 0; i < N; ++i){
		cin >> cows[i];
		cows[i] %= F;
	}
	for(int i = 0; i < N - 1; ++i)
		for(int j = 0; j < F; ++j)
			data[i][j] = -1;
	data[N - 1][0] = 1;
	for(int i = 1; i < F; ++i)
		data[N - 1][i] = 0;
	data[N - 1][cows[N - 1]]++;
	cout << Find(0, 0) - 1;
}