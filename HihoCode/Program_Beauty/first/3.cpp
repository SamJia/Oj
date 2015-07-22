#include "iostream"
#define SIZE 1010
#define ABS(x) ((x)>0?(x):-(x))
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;

long long user_x[SIZE], user_y[SIZE], company_x[SIZE], company_y[SIZE];
long long total_number, total_x, total_y, user_number, company_number;
long long result, pos_x, pos_y;

// int abs(int number);
long long FindDistance(long long x, long long y);

int main(){
	cin >> total_number;
	for(int i = 0; i < total_number; ++i){
		pos_x = pos_y = 0;
		cin >> total_x >> total_y >> user_number >> company_number;
		for(int j = 0; j < user_number; ++j){
			cin >> user_x[j] >> user_y[j];
			pos_x += user_x[j];
			pos_y += user_y[j];
		}
		pos_x /= user_number;
		pos_y /= user_number;
		for(int j = 0; j < company_number; ++j)
			cin >> company_x[j] >> company_y[j];
		result = MIN(FindDistance(pos_x, pos_y), FindDistance(pos_x, pos_y + 1));
		result = MIN(result, FindDistance(pos_x + 1, pos_y));
		result = MIN(result, FindDistance(pos_x + 1, pos_y + 1));
		cout << "Case #" << i + 1 << ": " << result << '\n';
	}
	return 0;
}

// int abs(int number){
// 	return number > 0 ? number : -number;
// }

long long FindDistance(long long x, long long y){
	long long user_dis = 0;
	long long min_com_dis = 0x7fffffff;
	for(int i = 0; i < user_number; ++i)
		user_dis += (x-user_x[i]) * (x-user_x[i]) + (y-user_y[i]) * (y-user_y[i]);
	for(int i = 0; i < company_number; ++i)
		min_com_dis = MIN(min_com_dis, ABS(x-company_x[i]) + ABS(y-company_y[i]));
	return user_dis + min_com_dis;
}