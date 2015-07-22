#include <cstdio>
#define SIZE 110
#define MAX(x,y) ((x)>(y)?(x):(y))
int student[SIZE][SIZE]={}, m, n, saved[SIZE][SIZE][SIZE] = {};// path[SIZE][SIZE] = {0};
int p1[] = {1, 0, 1, 0}, p2[] = {1, 0, 0, 1};

bool OK(int step, int row1, int row2){
	if (step == 0 && row1 == 0 && row2 == 0)
		return true;
	if (row1 == row2)
		return false;
	// printf("%d %d %d %d\n", step, row1, row2, (0 < row1 && row1 < m && 0 < row2 && row2 < m && step - row1 < n && step - row2 < n));
	return (0 <= row1 && 0 <= row2 && 0 <= step - row1 && 0 <= step - row2);
}

main(){
	// cin >> m >> n;
	// freopen("input", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &student[i][j]);
			// cin >> student[i][j];
	// student[0][0] = student[m-1][n-1] = 0;
	saved[0][0][0] = student[0][0];
	for(int step = 1; step < m + n; ++step)
		for(int i = 0; i <= step; ++i)
			for(int j = 0; j < i; ++j){
				// printf("%d %d\n", i, j);
				saved[step][i][j] -= student[i][step - i] + student[j][step - j];
				for(int k = 0; k < 4; ++k)
					if(OK(step-1, i-p1[k], j-p2[k])){
						// printf("%d %d %d %d %d\n", step, i, j, i-p1[k], j-p2[k]);
						saved[step][i][j] = MAX(saved[step][i][j], saved[step-1][i-p1[k]][j-p2[k]]);
					}
				saved[step][i][j] += student[i][step - i] + student[j][step - j];
				// saved[step][j][i] = saved[step][i][j];
			}
	printf("%d\n", saved[m+n-3][m-1][m-2] + student[m-1][n-1]);
}