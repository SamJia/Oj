#include <iostream>
using namespace std;
int main(){
	int n,sum=0;
	cin>>n;
	int soduko[81],sol[n],num[10]={0};
	for(int i=0;i<n;++i)
		sol[i]=1;
	for(int k=0;k<n;++k){
		for(int i=0;i<81;++i){
			cin>>soduko[i];
		}
		for(int i=0;i<81;i+=9){
		    num={0,0,0,0,0,0,0,0,0,0};
			for(int j=0;j<9;++j){
				if(num[soduko[i+j]]==1){
					sol[k]=0;
					num={0,0,0,0,0,0,0,0,0,0};
					break;
				}
				num[soduko[i+j]]=1;
			}
			if(!sol[k])
				break;
		}
		if(!sol[k])
			continue;
		for(int i=0;i<9;i++){
            num={0,0,0,0,0,0,0,0,0,0};
			for(int j=0;j<81;j+=9){
				if(num[soduko[i+j]]==1){
					sol[k]=0;
					num={0,0,0,0,0,0,0,0,0,0};
					break;
				}
				num[soduko[i+j]]=1;
			}
			if(!sol[k])
				break;
		}
		if(!sol[k])
			continue;
		int seqi[]={0,3,6,27,30,33,54,57,60},seqj[]={0,1,2,9,10,11,18,19,20};
		for(int i=0;i<9;++i){
            num={0,0,0,0,0,0,0,0,0,0};
			for(int j=0;j<9;++j){
				if(num[soduko[seqi[i]+seqj[j]]]==1){
					sol[k]=0;
					num={0,0,0,0,0,0,0,0,0,0};
					break;
				}
				num[soduko[seqi[i]+seqj[j]]]=1;
			}
			if(!sol[k])
				break;
		}
	}
	for(int i=0;i<n;++i)
		if(sol[i])
			cout<<"Right"<<endl;
		else
			cout<<"Wrong"<<endl;
	return 0;
}
