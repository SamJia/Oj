#include <cstdio>
#define SIZE 110
#define MAX(x,y) ((x)>(y)?(x):(y))
int student[SIZE][SIZE]={}, m, n, result[SIZE][SIZE][SIZE] = {};// path[SIZE][SIZE] = {0};
int p1[] = {1, 0, 1, 0}, p2[] = {1, 0, 0, 1};

main(){
	// cin >> m >> n;
	// freopen("input", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &student[i][j]);
			// cin >> student[i][j];
	// student[0][0] = student[m-1][n-1] = 0;
	// result[1][1][0] = student[1][0] + student[0][1];
	result[0][0][0] = student[0][0];
	for(int step = 1; step < m + n; ++step)
		for(int i = 0; i <= step; ++i)
			for(int j = 0; j < i; ++j){
				if(i > 0 && j > 0)
					result[step][i][j] = MAX(result[step][i][j], result[step-1][i-1][j-1]);
				if(i < step && j < step)
					result[step][i][j] = MAX(result[step][i][j], result[step-1][i][j]);
				if(i > 0 && j < step)
					result[step][i][j] = MAX(result[step][i][j], result[step-1][i-1][j]);
				if(i < step && j > 0)
					result[step][i][j] = MAX(result[step][i][j], result[step-1][i][j-1]);
				// printf("%d %d\n", i, j);
				// result[step][i][j] -= student[i][step - i] + student[j][step - j];
				// for(int k = 0; k < 4; ++k)
				// 	if(OK(step-1, i-p1[k], j-p2[k])){
				// 		// printf("%d %d %d %d %d\n", step, i, j, i-p1[k], j-p2[k]);
				// 		result[step][i][j] = MAX(result[step][i][j], result[step-1][i-p1[k]][j-p2[k]]);
				// 	}
				result[step][i][j] += student[i][step - i] + student[j][step - j];
				// result[step][j][i] = result[step][i][j];
			}
	printf("%d\n", result[m+n-3][m-1][m-2] + student[m-1][n-1]);
}