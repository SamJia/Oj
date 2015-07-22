#include <iostream>
#include <cstring>
using namespace std;
#define SUM first
#define NUM second

pair<long long, long long> saved_data[10][20][200][2] = {}; // [first bit][number length][sum + 100][first bit is positive(0) or negetive(1)]
long long power_of_ten[20] = {1};
int sum;

void ComputeData();
pair<long long, long long> ComputeResult(char *edge, int tmp_sum, int pos = 0, bool flag = 0); // flag : 0 is pos and 1 is neg
// long long ComputeResult(char *edge);
long long Check(char *edge);

int main(){
	char left_edge[20], right_edge[20];
	cin >> left_edge >> right_edge >> sum;
	ComputeData();
	// cout << left_edge << ' '<< right_edge << '\n';
	long long result = (ComputeResult(right_edge, sum+100).SUM - ComputeResult(left_edge, sum+100).SUM + Check(right_edge)) % 1000000007;
	result = result > 0 ? result : -result;
	cout << result;
	return 0;
}

void ComputeData(){
	for(int i = 1; i < 20; ++i)
		power_of_ten[i] = (power_of_ten[i-1] * 10) % 1000000007;
	for(int i = 0; i < 10; ++i){
		saved_data[i][1][i+100][0].SUM = i;
		saved_data[i][1][i+100][0].NUM = 1;
		saved_data[i][1][-i+100][1].SUM = i;
		saved_data[i][1][-i+100][1].NUM = 1;
	}
	for(int i = 2; i < 20; ++i)
		for(int j = 0; j < 10; ++j)
			for(int k = 10; k < 190; ++k){
				for(int m = 0; m < 10; ++m){
					saved_data[j][i][k][0].SUM += saved_data[m][i-1][k-j][1].SUM;
					saved_data[j][i][k][0].NUM += saved_data[m][i-1][k-j][1].NUM;
				}
				saved_data[j][i][k][0].NUM %= 1000000007;
				saved_data[j][i][k][0].SUM = (((saved_data[j][i][k][0].NUM * power_of_ten[i-1]) % 1000000007) * j + saved_data[j][i][k][0].SUM) % 1000000007;

				for(int m = 0; m < 10; ++m){
					saved_data[j][i][k][1].SUM += saved_data[m][i-1][k+j][0].SUM;
					saved_data[j][i][k][1].NUM += saved_data[m][i-1][k+j][0].NUM;
				}
				saved_data[j][i][k][1].NUM %= 1000000007;
				saved_data[j][i][k][1].SUM = (((saved_data[j][i][k][1].NUM * power_of_ten[i-1]) % 1000000007) * j + saved_data[j][i][k][1].SUM) % 1000000007;
				// saved_data[j][i][k][1].SUM = ((saved_data[j][i][k][1].SUM % 1000000007) * (power_of_ten[i-1] % 1000000007)) % 1000000007;
				// for(int m = 0; m < 10; ++m)
					// saved_data[j][i][k][1] = (saved_data[j][i][k][1] + saved_data[m][i-1][k+j][0]) % 1000000007;
			}
	// for(int i = 0; i < 10; ++i)
		// cout << saved_data[1][2][99][1].NUM << ' ';
}

pair<long long, long long> ComputeResult(char *edge, int tmp_sum, int pos, bool flag){ // flag : 0 is pos and 1 is neg
	// cout << tmp_sum << '\n';
	if(!edge[pos]){
		pair<long long, long long> result;
		result.SUM = result.NUM = 0;
		return result;
	}
	// cout << edge << ' ';
	pair<long long, long long> result = ComputeResult(edge, tmp_sum - (flag ? -(edge[pos]-'0') : (edge[pos]-'0')), pos+1, !flag);
	int len = strlen(edge);
	result.SUM = ((result.NUM * power_of_ten[len-pos-1]) % 1000000007 * (edge[pos]-'0') + result.SUM) % 1000000007;
	// int pos_or_neg = 0;
	// int tmp_sum = sum + 100;
	// for(int i = 0; edge[i]; tmp_sum -= pos_or_neg ? -(edge[i]-'0') : (edge[i]-'0'), pos_or_neg ^= 1, ++i)
	for(int j = 0; '0' + j < edge[pos]; ++j){
		result.SUM = (result.SUM + saved_data[j][len-pos][tmp_sum][flag].SUM) % 1000000007;
		result.NUM = (result.NUM + saved_data[j][len-pos][tmp_sum][flag].NUM) % 1000000007;
		// cout << j << ' ' << len-pos << ' ' << tmp_sum << ' ' << flag << ' ' << saved_data[j][len-pos][tmp_sum][flag].NUM << '\n';
	}
	// if(!pos)
	// 	cout << result.NUM << ' ';
	return result;
}

long long Check(char *edge){
	int pos_or_neg = 0; // 0 is pos and 1 is neg
	int tmp_sum = 0;
	long long number = 0;
	for(int i = 0; edge[i]; pos_or_neg ^= 1, ++i){
		tmp_sum +=( pos_or_neg ? -(edge[i]-'0') : (edge[i]-'0'));
		number = number * 10 + edge[i] - '0';
	}
	return tmp_sum == sum ? number : 0;
}