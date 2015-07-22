#include <iostream>
using namespace std;

main(){
	int N, K, a, b, c, num = 0, j = 0;
	int arr[100010] = {};
	cin >> N;
	for(int i = 0; i < N; ++i, ++num){
		cin >> a;
		if(a == j - 1)
			++arr[a];
		for(; j < a; ++j)
			arr[j] = num;
	}
	cin >> K;
	for(int i = 0; i < K; ++i){
		cin >> b >> c;
		if(!c)
			cout << num << '\n';
		else if(b * b / c / 4 >= a)
			cout << num << '\n';
		else
			cout << arr[b * b / c / 4] << '\n';
	}
}