#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int abs(int a){
    return(a>0?a:-a);
}

main(){
	int m,n,t;
	cin>>m>>n>>t;
	int maze[m][n],count=0,i=0,j=0,k=0,state=1;
	pair<int ,int> pos[m*n],now,amid;
	for(i=0;i<m;++i)
		for(k=0;k<n;++k){
		cin>>maze[i][k];
		if(maze[i][k]){
			pos[j].first=maze[i][k];
			pos[j++].second=i*m+k;
		}
	}
	for(i=0;i<j-1&&state;++i){
		state=0;
		for(k=0;k<j-i-1;++k){
			if(pos[k].first<pos[k+1].first){
				state=1;
				amid=pos[k];
				pos[k]=pos[k+1];
				pos[k+1]=amid;
			}
		}
	}
	now.first=-1;
	now.second=pos[0].second%m;
	for(i=0;i<j;++i){
//		k-=(abs(now.first-pos[i].second/m)+abs(now.second-pos[i].second%m)+2+pos[i].second/m);
		if((abs(now.first-pos[i].second/m)+abs(now.second-pos[i].second%m)+2+pos[i].second/m)>t)
			break;
//        cout<<t<<'\n';
		t-=(abs(now.first-pos[i].second/m)+abs(now.second-pos[i].second%m)+1);
		count+=pos[i].first;
		now.first=pos[i].second/m;
		now.second=pos[i].second%m;
	}
	cout<<count;
}