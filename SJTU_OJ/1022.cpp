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
	int a=0,b=1,c,start0,start1;
	char n[15]={'\0'};
	n[13]=0;
	cin.getline(n,15);
	for(int i=0;i<15;++i)
		if(n[i]=='\0'){
			n[14]=i;
			break;
		}
	while(n[14]-n[13]>5){
		start0=b-a;
		start1=a;
		if(b<a)
            start0+=2010;
		a=(start0*1035+start1*361)%2010;
		b=(start0*361+start1*1396)%2010;
		for(int i=n[14]-6;i>=n[13];--i){
			if(n[i]-->'0')
				break;
			n[i]='9';
		}
		if(n[n[13]]=='0'){
			++n[13];
		}
	}
	int num=0;
	for(int i=n[14]-1;i>=n[13];--i){
		num+=(n[i]-'0')*pow(10,n[14]-i-1);
	}
	for(int i=0;i<num;++i){
		c=a+b;
		if(c>=2010)
			c-=2010;
		a=b;
		b=c;
    }
    cout<<a;
}
// 10000:1605
// 10001:1201
// 10002:796
// 100000:1035
// 100001:361
// 100002:1396
