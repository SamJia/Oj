/*
ID: sammail1
PROG: beads
LANG: C++
*/
#include <cstdio>
#define SIZE 400
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

char bead_string[SIZE];
int beads[2*SIZE];
int total_bead_number, result = 0, tmp_length;

int main(){
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	scanf("%d\n%s", &total_bead_number, bead_string);
	for(int i = 0; i < total_bead_number; ++i)
		if(bead_string[i] == 'w')
			beads[i+1] = beads[total_bead_number+i+1] = 0;
		else if(bead_string[i] == 'r')
			beads[i+1] = beads[total_bead_number+i+1] = 1;
		else if(bead_string[i] == 'b')
			beads[i+1] = beads[total_bead_number+i+1] = 2;
	beads[0] = beads[2*total_bead_number+1] = 3;
	for(int i = 1; i <= 2 * total_bead_number; ++i){
		tmp_length = 0;
		for(int j = i - 1, color = 0; color != 3; --j, ++tmp_length)
			color |= beads[j];
		for(int j = i, color = 0; color != 3; ++j, ++tmp_length)
			color |= beads[j];
		result = MAX(result, tmp_length);
	}
	result -= 2;
	result = MIN(result, total_bead_number);
	printf("%d\n", result);
	return 0;
}