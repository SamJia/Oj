#include <iostream>
using namespace std;

main(){
	int n, tree[2000][2] = {};
	cin >> n;
	int root;
	for(int i = 0; i < n / 2; ++i){
		cin >> root;
		cin >> tree[root][0] >> tree[root][1];
	}
	int roots[2000] = {};
	for(int i = 1; i <= n; ++i)
		roots[tree[i][0]] = roots[tree[i][1]] = 1;
	for(root = 1; root <= n && roots[root]; ++root);
	int queue[2000], h = 0, t = 1;
	queue[0] = root;
	// cout << root;
	while(h < t){
		if(tree[queue[h]][0])
			queue[t++] = tree[queue[h]][0];
		if(tree[queue[h]][1])
			queue[t++] = tree[queue[h]][1];
		cout << queue[h++] << '\n';
	}
}