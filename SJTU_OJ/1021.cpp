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
	int n;
	cin>>n;
	int n_2=n*n,mountain[n_2],num=1,pos=-1,sign[4]={1,n,-1,-n},i=0;
	for(int j=0;j<n_2;++j)
        mountain[j]=0;
	while(num<=n_2){
		do{
		    pos+=sign[i];
			mountain[pos]=num++;
		}
		while(pos!=n-1&&pos!=n_2-1&&mountain[pos+sign[i]]==0);
		i=(i+1)%4;
	}
	for(pos=0;pos<n_2;++pos){
		cout<<setw(6)<<mountain[pos];
		if(!((pos+1)%n))
			cout<<'\n';
	}
}
