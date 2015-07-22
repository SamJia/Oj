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
	char a[100000]={'\0'},b[100000]={'\0'},c[100000]={'\0'};
	cin.getline(a,100000);
	cin.getline(b,100000);
	int i,j,k=99999,state=0,sol;
	for(i=0;i<100000;++i)
		if(a[i]=='\0')
			break;
	for(j=0;j<100000;++j)
		if(b[j]=='\0')
			break;
	for(--i,--j;i>=0||j>=0;--i,--j,--k){
		if(i<0)
			sol=b[j]-'0'+state;
		else if(j<0)
			sol=a[i]-'0'+state;
		else
			sol=a[i]+b[j]-'0'-'0'+state;
		c[k]=sol%10+'0';
		state=sol/10;
	}
	if(state)
		c[k--]='1';
	for(++k;k<100000;++k)
		cout<<c[k];
}
