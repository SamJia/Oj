#include <iostream>
using namespace std;
#define max_score first
#define root_number second
#define SIZE 32
int link_point_number, score[SIZE];
pair<unsigned long long, int> saved_data[SIZE][SIZE] = {};

void Input();
unsigned long long FindMaxScore(int begin_pos, int end_pos);
void Output(unsigned long long result);
void OutputRoots(int begin_pos, int end_pos);


main(){
	Input();
	unsigned long long result = FindMaxScore(0, link_point_number - 1);
	Output(result);
}

void Input(){
	cin >> link_point_number;
	for(int i = 0; i < link_point_number; ++i){
		cin >> score[i];
		saved_data[i][i].max_score = score[i];
		saved_data[i][i].root_number = i;
	}
}

unsigned long long FindMaxScore(int begin_pos, int end_pos){
	if(begin_pos > end_pos)
		return 1;
	if(!saved_data[begin_pos][end_pos].max_score){
		unsigned long long tmp_score;
		for(int i = begin_pos; i <= end_pos; ++i){
			tmp_score = FindMaxScore(begin_pos, i - 1) * FindMaxScore(i + 1, end_pos) + score[i];
			if(saved_data[begin_pos][end_pos].max_score < tmp_score){
				saved_data[begin_pos][end_pos].max_score = tmp_score;
				saved_data[begin_pos][end_pos].root_number = i;
			}
		}
	}
	return saved_data[begin_pos][end_pos].max_score;
}

void Output(unsigned long long result){
	cout << result << '\n';
	OutputRoots(0, link_point_number - 1);
}

void OutputRoots(int begin_pos, int end_pos){
	if(begin_pos > end_pos)
		return;
	cout << saved_data[begin_pos][end_pos].root_number + 1 << ' ';
	OutputRoots(begin_pos, saved_data[begin_pos][end_pos].root_number - 1);
	OutputRoots(saved_data[begin_pos][end_pos].root_number + 1, end_pos);
}