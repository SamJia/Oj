/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
#include <fstream>
using namespace std;
//--------------------------
int min_distance_found[16][32768] = {0}, number_of_post = 0, distance_of_post[16][16] = {0}, post_to_choose[16] = {0}, power_of_two[16] = {1}, pos_in_list;
ifstream fin(".txt");
//--------------------------
void Input();
void Initial();
int FindMinDistance(int);
void Output(int);
//--------------------------

main(){
	Input();
	Initial();
	int result = FindMinDistance(1);
	Output(result);
}

void Input(){
	cin >> number_of_post;
	for (int i = 1; i <= number_of_post; ++i)
		for(int j = 1; j <= number_of_post; ++j)
			cin >> distance_of_post[i][j];
}

void Initial(){
	for(int i = 1; i <= number_of_post; ++i){
		post_to_choose[i] = 1;
		power_of_two[i] = power_of_two[i - 1] * 2;
		pos_in_list += power_of_two[i];
	}
	pos_in_list -= 2;
}

int FindMinDistance(int begin_pos = 1){
	if(!pos_in_list)
		return(distance_of_post[begin_pos][1]);
	if(!min_distance_found[begin_pos][pos_in_list]){
		int tmp_min_distance = 0, min_distance = 1000000000;
		for(int i = 2; i <= number_of_post; ++i)
			if(post_to_choose[i]){
				post_to_choose[i] = 0;
				pos_in_list -= power_of_two[i];
				tmp_min_distance = distance_of_post[begin_pos][i] + FindMinDistance(i);
				min_distance = min(min_distance, tmp_min_distance);
				post_to_choose[i] = 1;
				pos_in_list += power_of_two[i];
			}
		min_distance_found[begin_pos][pos_in_list] = min_distance;
	}
	return(min_distance_found[begin_pos][pos_in_list]);
}

void Output(int result){
	cout << result;
}