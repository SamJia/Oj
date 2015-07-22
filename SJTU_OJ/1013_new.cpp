/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#define volumn first
#define value second
using namespace std;
//--------------------------
int total_volumn, number_of_item;
pair <int, int> item[1010];
// ifstream fin(".txt");
//--------------------------
void Input();
int CopyUsefulitemList(pair <int, int>[]);
bool ThisItemIsUseful(pair <int, int>);
int FindMaxValue(int);
void Output(int);
//--------------------------

main(){
	Input();
	int max_value = FindMaxValue(total_volumn);
	Output(max_value);
}

void Input(){
	cin >> total_volumn >> number_of_item;
	pair <int, int> tmp_item[number_of_item];
	for (int i = 0; i < number_of_item; ++i)
		cin >> tmp_item[i].volumn >> tmp_item[i].value;
	number_of_item = CopyUsefulitemList(tmp_item);
}

int CopyUsefulitemList(pair <int, int> tmp_item[]){
	sort(tmp_item, tmp_item + number_of_item);
	int number_of_useful_item = 0;
	for (int i = 0; i < number_of_item; ++i)
		if(ThisItemIsUseful(tmp_item[i]))
			item[number_of_useful_item++] = tmp_item[i];
	return(number_of_useful_item);
}

bool ThisItemIsUseful(pair <int, int> tmp){
	int value_before = 0;
	for (int i = 0; item[i].volumn != 0; ++i){
		value_before = tmp.volumn / item[i].volumn * item[i].value;
		if (value_before >= tmp.value)
			return(0);
	}
	return(1);
}

int FindMaxValue(int free_volumn){
	static int max_value = 0, max_value_list[10010] = {0};
	int tmp_value = 0, tmp_max_value = 0;
	if(!max_value_list[free_volumn]){
		for(int i = 0; i < number_of_item && item[i].volumn <= free_volumn; ++i){
			tmp_value = item[i].value + FindMaxValue(free_volumn - item[i].volumn);
			tmp_max_value = max(tmp_max_value, tmp_value);
		}
		max_value_list[free_volumn] = tmp_max_value;
	}
	return(max_value_list[free_volumn]);
}

void Output(int max_value){
	cout << max_value;
}