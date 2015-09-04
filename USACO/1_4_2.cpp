/*
ID: sammail1
PROG: milk3
LANG: C++
*/
#include <cstdio>
#define SIZE 30
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

bool result[SIZE][SIZE][SIZE] = {};
int capacity[3];
int method[6][2] = {{0,1},{0,2},{1,0},{1,2},{2,0},{2,1}};

void Pull(int next[], int num){
	int change = MIN(next[method[num][0]], capacity[method[num][1]] - next[method[num][1]]);
	next[method[num][0]] -= change;
	next[method[num][1]] += change;
}

void DFS(int a, int b, int c){
	if(result[a][b][c])
		return;
	result[a][b][c] = true;
	for(int i = 0; i < 6; ++i){
		int next[] = {a, b, c};
		Pull(next, i);
		DFS(next[0], next[1], next[2]);
	}
}

int main(){
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	scanf("%d%d%d", &capacity[0], &capacity[1], &capacity[2]);
	DFS(0, 0, capacity[2]);
	bool first_out = true;
	for(int i = 0; i <= capacity[2]; ++i)
		if(result[0][capacity[2]-i][i]){
			if(!first_out)
				printf(" ");
			printf("%d", i);
			first_out = false;
		}
	printf("\n");
	return 0;
}