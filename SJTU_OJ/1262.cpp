
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
main(){
	int n,exist_time=0,nonexist = 0,a,b;
	cin>>n;
	pair<int,int> area[n];
	for(int i=0;i<n;++i){
		cin>>a>>b;
		area[i].first=a>b?b:a;
		area[i].second=a>b?a:b;
	}
	sort(area,area+n);
	for(int i=1;i<n;++i){
		if(area[i].first>area[i-1].second){
			exist_time=max(exist_time, (area[i-1].second-area[i-1].first));
			nonexist = max(nonexist, area[i].first - area[i-1].second);
		}
		else{
			area[i].first=area[i-1].first;
			if(area[i].second<area[i-1].second)
				area[i].second=area[i-1].second;
		}
	}
	exist_time=max(exist_time, (area[n-1].second-area[n-1].first));
	cout<<exist_time << ' ' << nonexist;
}
