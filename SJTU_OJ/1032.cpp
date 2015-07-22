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

int ack(int m,int n){
	if(m==0)
		return(n+1);
	else if(n==0)
		return(ack(m-1,1));
	else
		return(ack(m-1,ack(m,n-1)));
}

main(){
	int m,n;
	cin>>m>>n;
	cout<<ack(m,n);
}
