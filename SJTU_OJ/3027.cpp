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
bool cmp(char list[],int i,int n){
    for(;i<=n;++i,--n){
        if(list[i]<list[n])
            return(1);
        if(list[i]>list[n])
            return(0);
    }
    return(1);
}

main(){
	int n,i=0;
	cin>>n;
	char list_old[2000]={'\0'},list_new[81]={'\0'};
	for(int i=0;i<n;++i)
		cin>>list_old[i];
	--n;
	while(i<=n){
        for(int j=0;j<80&&i<=n;++j){
            if(cmp(list_old,i,n))
                list_new[j]=list_old[i++];
            else
                list_new[j]=list_old[n--];
        }
        cout<<list_new<<'\n';
        for(int j=0;j<80;++j)
            list_new[j]='\0';
	}
}
