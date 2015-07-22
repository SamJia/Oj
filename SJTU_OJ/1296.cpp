#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define SIZE 5500
pair<int, int> height[SIZE];
int changed[SIZE];

struct Lnum{
	Lnum(){
		num[0] = '0';
		num[1] = '\0';
	}
	char num[1000];
	Lnum operator+(const Lnum& num2){
		Lnum result;
		int k = 0, sol, state = 0;
		for(int i = 0, j = 0; num[i] || num2.num[j];){
			if(!num[i])
				sol = num2.num[j++] - '0' + state;
			else if(!num2.num[j])
				sol = num[i++] - '0' + state;
			else
				sol = num[i++] - '0' + num2.num[j++] - '0' + state;
			result.num[k++] = sol % 10 + '0';
			state = sol / 10;
		}
		if(state)
			result.num[k++] = '1';
		result.num[k] = '\0';
		return result;
	}
	void init(int a){
		num[0] = '0' + a;
		num[1] = '\0';
	}
	void inverse(){
		for(int i = 0, j = strlen(num) - 1; i < j; ++i, --j)
			num[i] = num[j] + num[i] - (num[j] = num[i]);
	}
};
pair<int, Lnum> result[SIZE];
int total_number, max_dis = 0, changed_number;
Lnum max_num;

int main(){
	cin >> total_number;
	for(int i = 0; i < total_number; ++i){
		cin >> height[i].first;
		height[i].second = i;
	}
	sort(height, height + total_number);
	changed[height[0].second] = 0;
	for(int i = 1; i < total_number; ++i)
		changed[height[i].second] = changed[height[i - 1].second] + (height[i].first > height[i - 1].first);
	changed_number = changed[height[total_number - 1].second];
	max_num.init(1);
	for(int i = total_number - 1; i >= 0; --i, max_dis = 0, max_num.init(1)){
		for(int j = changed[i] - 1; j >= 0; --j){
			if(result[j].first > max_dis){
				max_dis = result[j].first;
				max_num = result[j].second;
			}
			else if(result[j].first == max_dis)
				max_num = max_num + result[j].second;
		}
		result[changed[i]].first = max_dis + 1;
		result[changed[i]].second = max_num;
	}
	max_dis = 0;
	max_num.init(0);
	for(int i = changed_number; i >= 0; --i){
		if(result[i].first > max_dis){
			max_dis = result[i].first;
			max_num = result[i].second;
		}
		else if(result[i].first == max_dis)
			max_num = max_num + result[i].second;
	}
	max_num.inverse();
	cout << max_dis << ' ' << max_num.num;
	return 0;
}