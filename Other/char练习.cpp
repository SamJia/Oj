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

bool index(char a[],int i){
    if(a[i]==' ')
        return(1);
    else if(!('a'<=a[i]&&a[i]<='z'||'A'<=a[i]&&a[i]<='Z')){
        if(i==0||!a[i+1])
            return(1);
        else
            if(!('a'<=a[i-1]&&a[i-1]<='z'||'A'<=a[i-1]&&a[i-1]<='Z')||!('a'<=a[i+1]&&a[i+1]<='z'||'A'<=a[i+1]&&a[i+1]<='Z'))
                return(1);
    }
    return(0);
}

main(){
	char sentance[100];
	int m,n,state=0;
	cin>>m>>n;
	cin.getline(sentance,100);
	for(int i=0;i<m;++i)
		cin.getline(sentance,100);
	for(int i=0;i<n;++i){
        state=0;
		cin.getline(sentance,100);
		for(int j=0;sentance[j];++j)
			if(index(sentance,j))
				state=1;
			else{
				if(state){
					cout<<'\n';
					state=0;
				}
				cout<<sentance[j];
			}
	}
}
