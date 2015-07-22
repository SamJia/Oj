#include <iostream>
using namespace std;
int josephus(int n){
	int a[n];
	int i,num_remain=n-1,number_off=0;
	for (i=0;i<=n-1;++i)a[i]=1;
	i=-1;
	while(num_remain){
		i=(i+1)%n;
		if (a[i]){
			number_off+=a[i];
			if (number_off>=3){
				number_off=0;
				num_remain-=1;
				a[i]=0;
			}
		}
	}
	for (i=0;!a[i];++i);
	return(i);
}
main(){
    cout<<josephus(6);
}
