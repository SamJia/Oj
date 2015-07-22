#include <iostream>
using namespace std;
int main(){
	int l,n=0,a=0;
	cin>>l;
	int l_2=l*l,area[l_2];
	for(int i=0;i<l_2;++i)cin>>area[i];
	while(1){
		a=0;
		for(int i=0;i<l_2;++i){
			if(area[i]==1){
				if(i>=l)
					if(!area[i-l]){
						area[i-l]=3;
						a=1;
					}
				if((i%l))
					if(!area[i-1]){
						area[i-1]=3;
						a=1;
					}
				if(i<(l_2-l))
					if(!area[i+l]){
						area[i+l]=3;
						a=1;
					}
				if(((i+1)%l))
					if(!area[i+1]){
						area[i+1]=3;
						a=1;
					}
				area[i]=2;
			}
		}
		for(int i=0;i<l_2;++i)
            if(area[i]==3)
                area[i]=1;
		if(!a)break;
		n++;
	}
	cout<<n;
	return 0;
}
