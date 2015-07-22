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
	int n,num,count=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>num;
		while(num){
			count+=(num%2);
			num/=2;
		}
	}
	cout<<count;
}