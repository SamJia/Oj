#include <iostream>
using namespace std;
int judge(int a,int b){
	int c=a;
	while(c){
		c=b%a;
		b=a;
		a=c;
	}
	if(b==1)
		return(0);
	return(1);
}



main(){
	int n,min_i,min_j,state=1;
	double min=1.0;
	cin>>n;
	int num[n+1][n+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
            if(judge(i,j)&&i!=1)
                num[i][j]=1;
            else
                num[i][j]=0;
		}
    cout<<"0/1\n";
	while(state){
		state=0;
		min=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(num[i][j]==0&&((double)i)/j<=min){
					min=((double)i)/j;
					min_i=i;
					min_j=j;
					state=1;
				}
		if(state){
			cout<<min_i<<'/'<<min_j<<'\n';
			num[min_i][min_j]=1;
		}
	}
}
