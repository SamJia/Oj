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
int find(int pos[],int p){
	for(int i=0;i<6;++i)
		if(pos[i]==p)
			return(i);
}
void point_path(int distance[],int maze[],int pos[],int n,int m,int total,int box){
	static int p1=0;
	maze[pos[p1]]=2;
	int n_m=n*m,path=0,p2,source=2,state=0;
	while(box>1){
		++path;
		for(int j=0;j<n_m;++j)
			if(maze[j]==source){
				state=1;
				if(j>=m)
					switch(maze[j-m]){
						case 0:maze[j-m]=-source;break;
						case 1:maze[j-m]=-source;
							p2=find(pos,j-m);
							distance[p1*total+p2]=path;
							distance[p2*total+p1]=path;
							--box;
							break;
					}
				if(j%m)
					switch(maze[j-1]){
						case 0:maze[j-1]=-source;break;
						case 1:maze[j-1]=-source;
							p2=find(pos,j-1);
							distance[p1*total+p2]=path;
							distance[p2*total+p1]=path;
							--box;
							break;
					}
				if(j<n_m-m)
					switch(maze[j+m]){
						case 0:maze[j+m]=-source;break;
						case 1:maze[j+m]=-source;
							p2=find(pos,j+m);
							distance[p1*total+p2]=path;
							distance[p2*total+p1]=path;
							--box;
							break;
					}
				if((j+1)%m)
					switch(maze[j+1]){
						case 0:maze[j+1]=-source;break;
						case 1:maze[j+1]=-source;
							p2=find(pos,j+1);
							distance[p1*total+p2]=path;
							distance[p2*total+p1]=path;
							--box;
							break;
					}
				maze[j]=3;
			}
		source=-source;
		if(!state){
			cout<<-1;
			exit(0);
		}
		state=0;
	}
	++p1;
}
void init(int maze[],int pos[],int n_m,int box,int p){
	for(int i=0;i<n_m;++i)
		if(maze[i]!=-1)
			maze[i]=0;
	for(int i=p;i<box;++i)
		maze[pos[i]]=1;
}

int min_len(int distance[],int total,int box,int *path,int num=0){
	static int min=100000;
	int amid=0;
	if(box==0){
		for(int i=0;i<total-1;++i)
			amid+=distance[path[i]*total+path[i-1]];
		min=min<amid?min:amid;
	}
	else{
		int state=1;
		for(int i=1;i<total;state=1,++i){
			for(int j=0;j<num;++j)
				if(path[j]==i)
					state=0;
			if(state){
				path[num]=i;
				min_len(distance,total,box-1,path,num+1);
			}
		}
	}
	return(min);
}

main(){
	int n,m,box=1;
	cin>>n>>m;
	int n_m=n*m;
	int maze[n_m];
	int pos[6];
	for(int i=0;i<n_m;++i){
		cin>>maze[i];
		if(maze[i]==1)
			pos[box++]=i;
		if(maze[i]==2)
			pos[0]=i;
	}
	int distance[box*box];
	for(int i=0;i<box-1;++i){
		point_path(distance,maze,pos,n,m,box,box-i);
		init(maze,pos,n_m,box,i+1);
	}
	int length=0,path[box];
	path[0]=0;
	int min=min_len(distance,box,box-1,path+1);
	cout<<min;
}
