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
	char a[1000]={'\0'},b[1000]={'\0'},c[2000];
	cin.getline(a,1000);
	cin.getline(b,1000);
	int i,j,k=1999,state=0,sol,k_per;
	for(i=0;i<100000;++i)
		if(a[i]=='\0')
			break;
	for(j=0;j<100000;++j)
		if(b[j]=='\0')
			break;
    for(k=0;k<2000;++k)
			c[k]='0';
    --k;
	for(--i;i>=0;--i,--k){
		if(a[i]=='0')
			continue;
        k_per=k;
		for(int j_per=j-1;j_per>=0;--j_per){
		    //cout<<(c[k_per]-'0')<<'\n';
			sol=(a[i]-'0')*(b[j_per]-'0')+state+(c[k_per]-'0');
//		    cout<<a[i]<<b[j_per]<<'\n';
			c[k_per--]=sol%10+'0';
			state=sol/10;
		}
		while(state){
			sol=state+(c[k_per]-'0');
			c[k_per--]=sol%10+'0';
			state=sol/10;
		}
	}
	for(k=0;k<2000;++k){
		if(c[k]>'0')
			state=1;
		if(state)
			cout<<c[k];
    }
    if(!state)
    cout<<0;
}
