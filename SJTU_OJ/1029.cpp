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
struct Onerow{
	int book[101];
	Onerow *next,*last;
};
main(){
	int n,state=0,a,b,i,j,k;
	cin>>n;
	char input[10000]={'\0'};
	Onerow *(row[n+1]),*p;
	getchar();
	for(i=1;i<=n;++i){
		cin.getline(input,10000);
		row[i]=p=new Onerow;
		p->next=NULL;
		p->last=p;
		state=1;
		for(j=0,k=-1;input[j]!='\0';++j){
			if(input[j]==' '){
				state=1;
				continue;
			}
			if(state){
				p->book[++k]=0;
				state=0;
			}
			p->book[k]=p->book[k]*10+input[j]-'0';
			p->book[100]=k+1;
		}
	}
	for(i=1;i<n;++i){
		cin>>a>>b;
		(row[b]->last)->next=row[a];
		row[b]->last=row[a]->last;
		row[a]=NULL;
	}
	for(i=1;i<=n;++i)
		if(row[i])
			for(p=row[i];p;p=p->next)
				for(j=0;j<(p->book[100]);++j)
					cout<<p->book[j]<<' ';
}
