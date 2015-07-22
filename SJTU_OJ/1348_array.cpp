#include <cstdio>
#include <algorithm>
using namespace std;
#define SIZE1 100100
#define SIZE2 1000010
int total_music_number, music_lengths[SIZE1], total_student_number, student_kind, arrive_time;
long long wait_times[2] = {};
int student_numbers[2] = {};
int students[2][SIZE2];

int main(int argc, char const *argv[])
{
	scanf("%d", &total_music_number);
	for(int i = 0; i < total_music_number; ++i)
		scanf("%d", music_lengths + i);
	scanf("%d", &total_student_number);
	for(int i = 0; i < total_student_number; ++i){
		scanf("%d %d", &student_kind, &arrive_time);
		students[student_kind%2][student_numbers[student_kind%2]++] = arrive_time;
	}
	sort(students[0], students[0] + student_numbers[0]);
	sort(students[1], students[1] + student_numbers[1]);
	int music_time = 0, count[2] = {};
	for(int i = 0; i < total_music_number; music_time += music_lengths[i++]){
		for(; count[0] < student_numbers[0] && students[0][count[0]] <= music_time &&
		  count[1] < student_numbers[1] && students[1][count[1]] <= music_time;){
			wait_times[0] += music_time - students[0][count[0]++];
			wait_times[1] += music_time - students[1][count[1]++];
		}
		// printf("%d %d\n", int(wait_times[0]), int(wait_times[1]));
	}
	// printf("%.2f %.2f\n", double(wait_times[0])/student_numbers[0], double(wait_times[1])/student_numbers[1]);
	music_time -= music_lengths[total_music_number-1];
	for(; count[0] < student_numbers[0];)
		wait_times[0] += music_time - students[0][count[0]++];
	for(; count[1] < student_numbers[1];)
		wait_times[1] += music_time - students[1][count[1]++];
	printf("%.2f %.2f", double(wait_times[1])/student_numbers[1], double(wait_times[0])/student_numbers[0]);
	return 0;
}