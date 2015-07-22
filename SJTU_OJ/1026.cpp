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
#define LEN 20000
using namespace std;
bool cmp(char *a,int i,int *b,int j){
	int k=j/LEN*LEN+LEN;
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
	char a[LEN+1]={'\0'},b[LEN+1]={'\0'},c[LEN+1]={'\0'};
	cin.getline(a,LEN);
	cin.getline(b,LEN);
	int a_start,b_start;
	for(int i=0;i<LEN;++i)
		if(a[i]=='\0'){
			a_start=i;
			break;
		}
	for(int i=LEN-1;i>=LEN-a_start;--i)
		a[i]=a[i-LEN+a_start];
	a_start=LEN-a_start;
	for(int j=0;j<LEN;++j)
		if(b[j]=='\0'){
			b_start=j;
			break;
		}
	for(int j=LEN-1;j>=LEN-b_start;--j)
		b[j]=b[j-LEN+b_start];
	b_start=LEN-b_start;
	int n_b[9*LEN+10]={0},sol=0,state=0,i=0,j=0,k=0;
	for(int i=1;i<10;++i){
		for(j=LEN-1,k=i*LEN-1;j>=b_start;--j,--k){
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
		n_b[9*LEN+i]=k+1;
	}
	/*for(i=0;i<9000;++i)
        if(n_b[i]!=0)
            cout<<n_b[i]<<' ';*/
	while(a_start<=b_start){
		for(i=9*LEN+9;i>9*LEN;--i){
		 // cout<<a[a_start]-'0'<<' '<<n_b[n_b[i]]<<' ';
			if(n_b[n_b[i]]<(a[a_start]-'0'))
				break;
			if(n_b[n_b[i]]==(a[a_start]-'0'))
				if(cmp(a,a_start,n_b,n_b[i]))
					break;
		}
//        cout<<i<<' ';
		j=n_b[i];
		k=(i-9*LEN)*LEN-1;
		c[LEN-1-b_start+a_start]+=(i-9*LEN);
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
	for(k=0;k<LEN;++k){
		if(c[k]>'\0')
			state=1;
		if(state)
			cout<<c[k]-'\0';
    }
    if(!state)
        cout<<0;
}
