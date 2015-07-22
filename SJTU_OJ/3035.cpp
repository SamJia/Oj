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
	int n;
	cin>>n;
	int a,b,score[n],num[11]={0},max=0;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		++num[10-(a*7+b*3)/111];
	}
	for(int i=1;i<11;++i)
		if(num[i]>num[max])
			max=i;
	cout<<max;
}