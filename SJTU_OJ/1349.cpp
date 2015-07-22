#include <iostream>
using namespace std;
#define SIZE 20

int row_number, colomn_number;
char map[SIZE][SIZE] = {};
int result[SIZE][SIZE] = {};

int main(){
	cin >> row_number >> colomn_number;
	for(int i = 0; i < row_number; ++i)
		cin >> map[i];
	result[row_number-1][colomn_number-1] = 1;
	for(int i = row_number - 2; i >= 0; --i)
		for(int j = colomn_number - 2; j >= 0; --j){
			for(int r = i + 1; r < row_number; ++r)
				for(int c = j + 1; c < colomn_number; ++c)
					if(map[i][j] != map[r][c])
						result[i][j] += result[r][c];
		}
	cout << result[0][0];
}