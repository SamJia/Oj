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
#define num first
#define a_i second
using namespace std;
struct Plane{
	int ti,ui,gi,num;
};

inline bool cmp_ti(Plane p1,Plane p2){
    return(p1.ti<p2.ti);
}
main(){
	int n,max,s,safe_time=0,pi=0,i=0,now_time=0;
	cin>>n>>max>>s;
	Plane p_list[n],amid;
	int down_time[n];
	for(i=0;i<n;++i){
		cin>>p_list[i].ti>>p_list[i].ui>>p_list[i].gi;
		p_list[i].num=i;
	}
    sort(p_list,p_list+n,cmp_ti);
	for(now_time=0;now_time<max;++now_time){
		if(pi==n)
			break;
		if(now_time==p_list[pi].ti){
			if(pi<n-1)
				if(p_list[pi].ti==p_list[pi+1].ti){
					cout<<"CHANGE BOYFRIEND";
					exit(0);
				}
			if(p_list[pi].ti+p_list[pi].ui>=safe_time){
				safe_time=p_list[pi].ti+p_list[pi].ui+s;
				down_time[p_list[pi++].num]=safe_time-s;
			}
			else{
				p_list[pi].ti+=p_list[pi].gi;
				amid=p_list[pi];
				for(i=1;pi+i<n&&(p_list[pi+i].ti<amid.ti);p_list[pi+i-1]=p_list[pi+i],++i);
				p_list[pi+i-1]=amid;
			}
		}
	}
	if(pi==n)
		if(down_time[n-1]<=max){
			for(int i=0;i<n;++i)
				cout<<down_time[i]<<'\n';
			exit(0);
		}
	cout<<"GO DATING";
}

		// if(pi<n-1){
		// 	if(p_list[pi].ti==p_list[pi+1].ti){
		// 		cout<<
		// 		exit(0);
		// 	}
		// }
		// else

		// if(){
		//
		// 	if(p_list[pi].ti+p_list[pi].ui>max){
		// 		cout<<"GO DATING";
		// 		exit(0);
		// 	}
		//
		// 	++pi;
		// }
		// else{
		//
		// }
