#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
main(){
	int n,m,state=1,money=0;
	cin>>n>>m;
	pair<int,int> mulk[m],amid;
	for(int i=0;i<m;++i)
		cin>>mulk[i].first>>mulk[i].second;
	for(int i=0;i<m-1&&state;++i){
		state=0;
		for(int j=0;j<m-i-1;++j){
			if(mulk[j].first>mulk[j+1].first){
				state=1;
				amid=mulk[j];
				mulk[j]=mulk[j+1];
				mulk[j+1]=amid;
			}
		}
	}
	for(int i=0;n;++i){
		if(n<mulk[i].second){
			money+=mulk[i].first*n;
			n=0;
		}
		else{
			money+=mulk[i].first*mulk[i].second;
			n-=mulk[i].second;
		}
	}
	cout<<money;
}