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
	int matrix[600][600],l,state;
	for(int i=0;i<n;++i){
		cin>>l>>state;
		for(int j=0;j<l;++j)
			for(int k=0;k<l;++k)
				cin>>matrix[j][k];
		if(state==0)
			for(int j=0;j<l;++j){
				for(int k=l-1;k>=0;--k)
					cout<<matrix[j][k]<<' ';
				cout<<'\n';
			}
		else if(state==1)
			for(int j=l-1;j>=0;--j){
				for(int k=0;k<l;++k)
					cout<<matrix[j][k]<<' ';
			cout<<'\n';
			}
		else
			for(int j=0;j<l;++j){
				for(int k=0;k<l;++k)
					cout<<matrix[k][j]<<' ';
				cout<<'\n';
			}
	}
}
