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
template <typename T>
void sort_array(T *start,T *end){
	T amid,*min;
	for(;start<end-1;++start){
	    min=start;
		for(T *i=start+1;i<end;min=*min<*i?min:i,++i);
		amid=*start;
		*start=*min;
		*min=amid;
	}
}
main(){
	int n;
	cout<<"please input the number of the date you want to sort"<<'\n';
	cin>>n;
	int array[n];
	for(int i=0;i<n;++i)
		cin>>array[i];
	sort_array(array,array+n);
	for(int i=0;i<n;++i)
		cout<<array[i]<<'\n';
}
