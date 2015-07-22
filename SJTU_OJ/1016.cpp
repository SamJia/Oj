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
bool cmp(char *a,int i,int *b,int j){
	int k=j/1000*1000+1000;
	for(;j<k;++i,++j){
		// cout<<a[i]<<' '<<b[j]<<' ';
		if(a[i]-'0'<b[j])
			return(0);
		if(a[i]-'0'>b[j])
			return(1);
	}
	return(1);
}
main(){
	char a[1001]={'\0'},b[1001]={'\0'},c[1001]={'\0'};
	cin.getline(a,1000);
	cin.getline(b,1000);
	int a_start,b_start;
	for(int i=0;i<1000;++i)
		if(a[i]=='\0'){
			a_start=i;
			break;
		}
	for(int i=999;i>=1000-a_start;--i)
		a[i]=a[i-1000+a_start];
	a_start=1000-a_start;
	for(int j=0;j<1000;++j)
		if(b[j]=='\0'){
			b_start=j;
			break;
		}
	for(int j=999;j>=1000-b_start;--j)
		b[j]=b[j-1000+b_start];
	b_start=1000-b_start;
	int n_b[9010]={0},sol=0,state=0,i=0,j=0,k=0;
	for(int i=1;i<10;++i){
		for(j=999,k=i*1000-1;j>=b_start;--j,--k){
			sol=i*(b[j]-'0')+state;
			n_b[k]=sol%10;
			state=sol/10;
		}
		if(state){
			// cout<<state<<' ';
			n_b[k+1]+=state*10;
			// cout<<state<<' ';
			state=state/10;
			// cout<<state<<' ';
		}
		n_b[9000+i]=k+1;
	}
	/*for(i=0;i<9000;++i)
        if(n_b[i]!=0)
            cout<<n_b[i]<<' ';*/
	while(a_start<=b_start){
		for(i=9009;i>9000;--i){
		 // cout<<a[a_start]-'0'<<' '<<n_b[n_b[i]]<<' ';
			if(n_b[n_b[i]]<(a[a_start]-'0'))
				break;
			if(n_b[n_b[i]]==(a[a_start]-'0'))
				if(cmp(a,a_start,n_b,n_b[i]))
					break;
		}
//        cout<<i<<' ';
		j=n_b[i];
		k=(i-9000)*1000-1;
		c[999-b_start+a_start]+=(i-9000);
		for(i=a_start+k-j;k>=j;--k,--i){
			sol=(a[i]-'0')-n_b[k]+state;
			//cout<<a[i]-'0'<<' '<<n_b[k]<<' '<<sol<<' '<<'\n';
			if(sol<0){
				a[i]=sol+10+'0';
				state=-1;
			}
			else{
				a[i]=sol+'0';
				state=0;
			}
		}
		//cout<<'\n';
        // cout<<a_start<<' ';
		a[a_start+1]=a[a_start+1]+(a[a_start]-'0')*10;
        // cout<<a_start<<' ';
		++a_start;
	}
	state=0;
	for(k=0;k<1000;++k){
		if(c[k]>'\0')
			state=1;
		if(state)
			cout<<c[k]-'\0';
    }
    if(!state)
        cout<<0;
}
