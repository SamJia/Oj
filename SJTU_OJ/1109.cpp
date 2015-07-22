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
#define num first
#define a_i second
using namespace std;
main(){
	int n,tmp_a,tmp_c,j;
	cin>>n;
	pair<int,int> list[n];
	cin>>list[0].a_i>>tmp_c;
	list[0].num=1;
	for(int i=1;i<n;++i){
		cin>>tmp_a>>tmp_c;
		for(j=i-1;j>=0&&tmp_c>0;--j,--tmp_c){
			if(list[j].a_i>tmp_a)
				break;
			list[j+1]=list[j];
		}
		list[j+1].num = i + 1;
		list[j+1].a_i=tmp_a;
	}
	for(int i=0;i<n;++i)
		cout<<list[i].num<<' ';
}
