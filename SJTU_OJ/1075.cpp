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
#define SIZE 50

int result[3340]={1,1};

int solve(int num){
	if(result[num])
		return(result[num]);
	int tmp_result=solve(num-1),n=num/2;
	for(int i=0;i<n-1;++i)
        tmp_result+=(result[i]*result[num-2-i]*2)%19301;
	tmp_result+=result[n-1]*result[num-n-1]*(num%2+1);
	tmp_result%=19301;
	result[num]=tmp_result;
	return(tmp_result);
}

main(){
	/*result[0]=new char[SIZE];
	result[0][0]='1';
	result[0][1]='\0';
	result[1]=new char[SIZE];
	result[1][0]='1';
	result[1][1]='\0';*/
//	ofstream fout("kuohaopipei.txt");
	int n=solve(3333);
    cout<<n;
//	for(int i=0;i<3334;++i)
//		fout<<result[i]<<',';
}
