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

main(){
	int t, i, j, k, num, plane[30], rac[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8,9,10, 11},{12, 13, 14, 15},{0, 4, 8, 12},{1, 5, 9, 13},{2, 6, 10, 14},{3, 7, 11, 15},{0, 5, 10, 15},{3, 6, 9, 12}};
	cin >> t;
	char tmp_char;
	char change[] = {'.', 'O', 'X', 'T','\n'};
	int change_num[] = {0, 1, 10, 100, 0}, flag;
	for (i = 0; i < t; ++i){
		flag = 0;
		for(j = 0; j < 16; ++j){
			cin >> tmp_char;
			for(k = 0; tmp_char != change[k] && k < 4; ++k);
			plane[j] = change_num[k];
		}
		for(j = 0; j < 10; ++j){
			for(k = 0, num = 0; k < 4; ++k){
				num += plane[rac[j][k]];
				if(!plane[rac[j][k]])
					flag = 1;
			}
			if(num == 4 || num == 103){
				cout << "O won" << endl;
				break;
			}
			if(num == 40 || num == 130){
				cout << "X won" << endl;
				break;
			}
			if(j == 9){
				if(flag)
					cout << "Game has not completed" << endl;
				else
					cout << "Draw" << endl;
			}
		}
	}
}
