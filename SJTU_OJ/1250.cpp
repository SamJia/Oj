#include <iostream>
using namespace std;
#define SIZE 100100
int weight[SIZE], cumulative_sum[SIZE], total_number, min_length;

double GetMaxAvg(int bgein, int end);

main(){
    cin>>total_number>>min_length;
    for(int i=0;i<total_number;++i)
        cin>>weight[i];
    cumulative_sum[0] = 0;
    for(int i=1;i<=total_number;++i)
        cumulative_sum[i] = cumulative_sum[i-1] + weight[i-1];
	double min_avg=GetMaxAvg(0, total_number);
	cout<<(int)(min_avg*1000);
}

double GetMaxAvg(int begin, int end){
    if (end - begin <= min_length)
        return 0.0;
    int mid = (begin + end) / 2;
    double max_avg_left = 0, max_avg_right = 0, max_avg_mid = 0, tmp = 0;
    max_avg_left = GetMaxAvg(begin, mid);
    max_avg_right = GetMaxAvg(mid, end);
    for (int i = max(mid + 2 - 2 * min_length, begin); i < mid; ++i)
        for (int j = max(mid + 1, i + min_length); j <= max(i + 2 * min_length - 1, end); ++j){
            tmp = double(cumulative_sum[j] - cumulative_sum[i]) / (j - i);
            if (tmp > max_avg_mid)
                max_avg_mid = tmp;
        }
    return max(max(max_avg_left, max_avg_right), max_avg_mid);
}