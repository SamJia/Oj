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
	int n,result=0,a,b;
	cin>>n;
	pair<int,int> area[n];
	for(int i=0;i<n;++i){
		cin>>a>>b;
		area[i].first=a>b?b:a;
		area[i].second=a>b?a:b;
	}
	sort(area,area+n);
	for(int i=1;i<n;++i){
		if(area[i].first>=area[i-1].second)
			result+=(area[i-1].second-area[i-1].first);
		else{
			area[i].first=area[i-1].first;
			if(area[i].second<area[i-1].second)
				area[i].second=area[i-1].second;
		}
	}
	result+=(area[n-1].second-area[n-1].first);
	cout<<result;
}
