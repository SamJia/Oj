#include <iostream>
using namespace std;

int map[33][33], M, N, M1, M2, data[33][33], trace[33][33] = {};
int move[8][2];
inline bool Check(int x, int y){
	return (x >= 0 && x < M && y >= 0 && y < N);
}

int Find(){
	int n = 1;
	while(1){
		for(int i = 0; i < M; ++i)
			for(int j = 0; j < N; ++j)
				if(map[i][j] == 3)
					for(int k = 0; k < 8; ++k)
						if(Check(i + move[k][0], j + move[k][1])){
							if(map[i + move[k][0]][j + move[k][1]] == 4)
								return n;
							else if(map[i + move[k][0]][j + move[k][1]] == 1)
								map[i + move[k][0]][j + move[k][1]] = 5;
						}
		for(int i = 0; i < M; ++i)
			for(int j = 0; j < N; ++j)
				if(map[i][j] == 3)
					map[i][j] = 0;
				else if(map[i][j] == 5)
					map[i][j] = 3;
		++n;
		// data[x][y] = tmp + 1;
	}
	// return data[x][y];
}


main(){
	cin >> M >> N >> M1 >> M2;
	move[0][0] = move[1][0] = -M1;
	move[2][0] = move[3][0] = M1;
	move[4][0] = move[5][0] = -M2;
	move[6][0] = move[7][0] = M2;
	move[0][1] = move[2][1] = -M2;
	move[1][1] = move[3][1] = M2;
	move[4][1] = move[6][1] = -M1;
	move[5][1] = move[7][1] = M1;
	int start_x, start_y;
	for(int i = 0; i < M; ++i)
		for(int j = 0; j < N; ++j){
			cin >> map[i][j];
			data[i][j] = -1;
			if(map[i][j] == 4)
				data[i][j] = 0;
			else if(map[i][j] == 3){
				start_x = i;
				start_y = j;
			}
		}
	cout << Find();
}