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
	int t,n,m,list[1000]={0},station[1000]={0},i,j,k,u;
	cin>>t;
	for(i=0;i<t;++i){
		cin>>n>>m;
		for(j=0;j<n;++j)
			cin>>list[j];
		for(j=0,k=0,u=0;(j<n||k>0)&&k<=m;){
			if(j<n&&j==list[u]){
				++j;
				++u;
			}
			else if(k>0&&station[k-1]==list[u]){
				--k;
				++u;
			}
			else
				station[k++]=j++;
		}
		if(j==n&&k==0)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
}
