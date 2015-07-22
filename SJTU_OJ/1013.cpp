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
#define c first
#define w second

using namespace std;

int package(int v,pair<int,int> object[],int length=0,int wealth=0,int k=0){
	static int max=0,len=length;
	for(int i=k;i<len;++i){
		if(v>object[i].c)
			package(v-object[i].c,object,0,wealth+object[i].w,i);
		else if(v==object[i].c){
			if(wealth+object[i].w>max)
				max=wealth+object[i].w;
			break;
		}
		else{
			if(wealth>max)
				max=wealth;
			break;
		}
	}
	return(max);
}


main(){
	int v,n;
	cin>>v>>n;
	pair<int,int> object[n];
	for(int i=0;i<n;++i)
		cin>>object[i].c>>object[i].w;
	sort(object,object+n);
	double ratio=0;
	for(int i=0;i<n-1;++i){
		if(object[i].c==object[i+1].c)
			object[i].c=0;
		else if((double)object[i].w/object[i].c>=ratio)
			ratio=(double)object[i].w/object[i].c;
		else
			object[i].w=0;
	}
	int k=0;
	for(int i=0;i<n;++i)
		if(object[i]!=0)
			++k;
	pair<int,int> object_sorted[k];
	for(int i=0,int j=0;i<n;++i)
		if(object[i]!=0)
			object_sorted[k++]=object[i];
    //for(int i=0;i<sizeof(object_sorted)/sizeof(object_sorted[0]);++i)
	    //cout<<object_sorted[i].c<<' '<<object_sorted[i].w<<'\n';
	int wealth=package(v,object_sorted,length);
	cout<<wealth;
}
