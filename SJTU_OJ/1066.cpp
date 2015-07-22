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

int fee_arr[4000000],n,m,fee,ins,del,charge[128];
char name[2010],letter;

int min_fee(int begin,int end){
	int m1=0,m2=0,pos=begin*m+end;
	if(fee_arr[pos]>=0)
		return(fee_arr[pos]);
	for(;(name[begin]==name[end])&&(begin<end);++begin,--end);
	if(begin>=end){
        fee_arr[pos]=0;
		return(0);
	}
    m1=min_fee(begin+1,end)+charge[name[begin]];
    for(;name[begin]!=name[end];m2+=charge[name[end]],--end);
	m2+=min_fee(begin+1,end-1);
	fee_arr[pos]=min(m1,m2);
    return(fee_arr[pos]);
}

main(){
	cin>>n>>m;
	cin>>name;
	for(int i=0;i<n;++i){
	cin>>letter>>ins>>del;
	charge[letter]=ins<del?ins:del;
	}
	int m__2=m*m;
	for(int i=0;i<m__2;++i)
		fee_arr[i]=-1;
	fee=min_fee(0,m-1);
	cout<<fee;
}
