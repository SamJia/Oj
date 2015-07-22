#include <cstdio>
#define SIZE 310
#define MAX(x,y) ((x)>(y)?(x):(y))

char map[SIZE][SIZE], added_sum[SIZE][SIZE];
int total_test_numebr, total_row_number, total_colomn_numebr;
int result;

void Input();
void Init();
void Compute();
bool Check(int row, int colomn, int side);
int GetWeight(int r1, int c1, int r2, int c2);

int main(){
	// freopen("input", "r", stdin);
	scanf("%d", &total_test_numebr);
	for(int i = 0; i < total_test_numebr; ++i){
		Input();
		Init();
		Compute();
		if(result)
			printf("%d\n", result);
		else
			printf("IMPOSSIBLE\n");
	}
}

void Input(){
	scanf("%d%d", &total_row_number, &total_colomn_numebr);
	for(int i = 0; i < total_row_number; ++i)
		scanf(" %s", &map[i][0]);
	for(int i = 0; i < total_row_number; ++i)
		for(int j = 0; j < total_colomn_numebr; ++j)
			map[i][j] -= '0';
	// for(int i = 0; i < total_row_number; ++i)
	// 	printf("%s\n", map[i]);

}

void Init(){
	result = 0;
	added_sum[0][0] = 0;
	for(int i = 1; i <= total_row_number; ++i)
		added_sum[i][0] = added_sum[i-1][0] + map[i-1][0];
	for(int i = 1; i <= total_colomn_numebr; ++i)
		added_sum[0][i] = added_sum[0][i-1] + map[0][i-1];
	for(int i = 1; i <= total_row_number; ++i)
		for(int j = 1; j <= total_colomn_numebr; ++j)
			added_sum[i][j] = added_sum[i-1][j] + added_sum[i][j-1] - added_sum[i-1][j-1] + map[i-1][j-1];
}

void Compute(){
	for(int i = 0; i < total_row_number; ++i)
		for(int j = 0; j < total_colomn_numebr; ++j)
			for(int k = 3; Check(i, j, k); ++k){
				if(		GetWeight(i, j, i+k, j+k/2) - map[i][j] - map[i+k-1][j]
							== GetWeight(i, j+k-k/2, i+k, j+k) - map[i][j+k-1] - map[i+k-1][j+k-1]
					&&
						GetWeight(i, j, i+k/2, j+k) - map[i][j] - map[i][j+k-1]
							== GetWeight(i+k-k/2, j, i+k, j+k) - map[i+k-1][j] - map[i+k-1][j+k-1]){
					result = MAX(result, k);
					// printf("%d %d %d \n", i, j, k);
				}
			}
}

bool Check(int row, int colomn, int side){
	return row + side <= total_row_number && colomn + side <= total_colomn_numebr;
}

int GetWeight(int r1, int c1, int r2, int c2){
	return added_sum[r2][c2] - added_sum[r1][c2] - added_sum[r2][c1] + added_sum[r1][c1];
}