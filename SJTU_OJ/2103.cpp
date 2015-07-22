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
	int m,n,n8,kn[7],num=1,num_array[8005]={0},eat=0,eat_num,times=0;
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>n>>kn[0]>>kn[1]>>kn[2]>>kn[3]>>kn[4]>>kn[5]>>kn[6];
		n8=8*n;
		for(int j=0;j<7;++j){
			while(times<n8){
				for(int k=0;k<kn[j]-1+eat&&times<n8;){
					if(num_array[num]==0){
						if(eat){
							eat_num=num;
							num_array[num]=1;
                        }
						++k;
					}
                    ++num;
					if(num>n8)
						num=1;
					++times;
				}
				eat=!eat;
			}
			num=eat_num+1;
			if(num>n8)
                num=1;
			times=0;
			eat=0;
		}
		cout<<eat_num<<'\n';
		for(int j=0;j<8005;++j)
			num_array[j]=0;
		num=1;
	}
}
