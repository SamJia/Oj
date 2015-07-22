#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
int student[55][55]={0}, m, n, saved[55][55][55][55] = {0};// path[55][55] = {0};
int p1[] = {1, 0, 1, 0}, p2[] = {0, 1, 0, 1}, p3[] = {1, 0, 0, 1}, p4[] = {0, 1, 1, 0};

bool OK(int a, int b, int c, int d){
	if(a == m-1 && b == n-1)
		return(1);
	if(a < m && b < n && c < m && d < n && a != c)
		return(1);
	return(0);
}

int Find(int pos1 = 0, int pos2 = 0, int pos3 = 0, int pos4 = 0){
	if(!saved[pos1][pos2][pos3][pos4]){
		int max_sum = 0;
		for(int i = 0; i < 4; ++i)
			if(OK(pos1 + p1[i], pos2 + p2[i], pos3 + p3[i], pos4 + p4[i]))
				max_sum = max(max_sum, Find(pos1 + p1[i], pos2 + p2[i], pos3 + p3[i], pos4 + p4[i]));
		saved[pos1][pos2][pos3][pos4] = saved[pos3][pos4][pos1][pos2] = max_sum + student[pos1][pos2] + student[pos3][pos4];
	}
	return(saved[pos1][pos2][pos3][pos4]);
}

main(){
	cin >> m >> n;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			cin >> student[i][j];
	cout << Find();
}