#include <iostream>
#include <cmath>
using namespace std;

void resolve(int num,int array_num[],int array_count[]){
	int min=2,i=0;
	while(min<=sqrt(num)){
		if(num%min==0){
            if(min!=array_num[i]&&array_num[i]!=0)
			    ++i;
            array_num[i]=min;
            ++array_count[i];
			num/=min;
		}
		else
			++min;
	}
    if(num!=array_num[i]&&array_num[i]!=0)
            ++i;
    array_num[i]=num;
    ++array_count[i];
}

main(){
	int n,array_num[15]={0},array_count[15]={0};
	cin>>n;
	resolve(n,array_num,array_count);
	cout<<n<<'=';
	for(int i=0;i<15&&array_num[i]>0;++i)
		cout<<array_num[i]<<'('<<array_count[i]<<')';
}
