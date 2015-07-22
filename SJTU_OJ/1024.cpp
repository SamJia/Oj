#include <iostream>
using namespace std;
main(){
	int n;
	cin>>n;
	int array[n],amid,state=1;
	for(int i=0;i<n;++i)
		cin>>array[i];
	for(int i=0;i<n-1;++i){
		for(int j=n-1;j>i;--j)
			if(array[j]<array[j-1]){
				amid=array[j];
				array[j]=array[j-1];
				array[j-1]=amid;
				state=0;
			}
		if(state)
			break;
		state=1;
	}
	for(int i=0;i<n;++i)
		cout<<array[i]<<' ';
}
