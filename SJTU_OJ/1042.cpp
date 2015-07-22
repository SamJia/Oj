#include <iostream>
using namespace std;
int n, root[13000] = {}, tmp, root_num;
pair<int, int>node[13000] = {};

void DLR(int num){
	if(!num)
		return;
	cout << num << ' ';
	DLR(num = node[num].first);
	while(num)
		DLR(num = node[num].second);
}

void LRD(int num){
	if(!num)
		return;
	int tmp_num = num;
	LRD(tmp_num = node[tmp_num].first);
	while(tmp_num)
		LRD(tmp_num = node[tmp_num].second);
	cout << num << ' ';
}

void Aspect(int num){
	int que[13000] = {num}, h = 0, t = 1;
	while(h < t){
		cout << que[h] << ' ';
		if(num = node[que[h]].first)
			que[t++] = num;
		while(num)
			if(num = node[num].second)
				que[t++] = num;
		h++;
	}
}

main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> tmp;
		cin >> node[tmp].first >> node[tmp].second;
		root[node[tmp].first] = root[node[tmp].second] = 1;
	}
	for(root_num = 1; root_num <= n && root[root_num]; ++root_num);
	DLR(root_num);
	cout << '\n';
	LRD(root_num);
	cout << '\n';
	Aspect(root_num);
}