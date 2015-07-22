#include <iostream>
#include <fstream>
using namespace std;

long long Insert(int *begin, int length){
	int half_length = length / 2, tmp_array[length], i, j, k;
	long long result = 0;
	for(i = k = 0, j = half_length; i < half_length && j < length;){
		if(begin[i] <= begin[j])
			tmp_array[k++] = begin[i++];
		else{
			tmp_array[k++] = begin[j++];
			result += half_length - i;
		}
	}
	if(j == length)
		for(; i < half_length;)
			tmp_array[k++] = begin[i++];
	for(i = 0; i < k; ++i)
		begin[i] = tmp_array[i];
	return(result);
}

long long Find(int *begin, int length){
	if(length == 1)
		return(0);
	long long result = 0;
	int half_length = length / 2;
	result += Find(begin, half_length);
	result += Find(begin + half_length, length - half_length);
	result += Insert(begin, length);
	return(result);
}

main(){
	int n;
	cin >> n;
	int number[n];
	for(int i = 0; i < n; ++i)
		cin >> number[i];
	long long result = Find(number, n);
	cout << result;
}