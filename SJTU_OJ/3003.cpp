#include <cstdio>
#define SIZE 100100
#define MAX(x,y) ((x)>(y)?(x):(y))

int total_ant_number, total_length, ant_speed;
int init_pos[SIZE];
int direction;
double ant_distance, result = 0;

int main(){
	scanf("%d%d%d", &total_ant_number, &total_length, &ant_speed);
	for(int i = 0; i < total_ant_number; ++i)
		scanf("%d", &init_pos[i]);
	for(int i = 0; i < total_ant_number; ++i){
		scanf("%d", &direction);
		ant_distance = direction ? (total_length - init_pos[i]) : init_pos[i];
		result = MAX(ant_distance / ant_speed, result);
	}
	printf("%.3f\n", result);
}