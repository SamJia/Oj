#include <iostream>
using namespace std;
main(){
	int total_number, people, i, j, k;
	unsigned long long total_time1 = 0, used_time1 = 0, total_time2 = 0, used_time2 = 0, queue1[3] = {}, queue2[3] = {};
	cin >> total_number;
	for(i = j = 0; i < total_number; ++i, j = (j + 1) % 3){
		cin >> people;
		total_time1 += queue1[j];
		queue1[j] += people;
		used_time1 = max(used_time1, queue1[j]);
		if(queue2[0] < queue2[1] && queue2[0] < queue2[2])
			k = 0;
		else
			k = queue2[1] < queue2[2] ? 1 : 2;
		total_time2 += queue2[k];
		queue2[k] += people;
		used_time2 = max(used_time2, queue2[k]);
	}
	cout << total_time1 << ' ' << used_time1 << '\n';
	cout << total_time2 << ' ' << used_time2 << '\n';	
}