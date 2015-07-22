#include <iostream>
using namespace std;

int depth[1001000] = {}, number[30] = {1}, max_depth = 0;

int main(){
	int root_number, root, tmp_depth;
	cin >> root_number;
	for(int i = 1; i < root_number; ++i){
		cin >> root;
		tmp_depth = depth[root] + 1;
		depth[i] = tmp_depth;
		++number[tmp_depth];
		max_depth = max(max_depth, tmp_depth);
	}
	for(int i = 1; i < max_depth; ++i)
		if(number[i] != (number[i - 1]<<1)){
			cout << "false\n";
			return 0;
		}
	cout << "true\n";
	return 0;
}