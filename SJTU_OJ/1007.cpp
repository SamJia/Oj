#include <iostream>
#include <stdio.h>
using namespace std;
main(){
	char a[202]={'\0'},b[202]={'\0'},c[203]={'\0'};
	int k1,k2,state=0,sum;
	scanf("%s",a);
	scanf("%s",b);
	for(int i=0;i<201;++i)
        if(a[i]=='.'){
        	k1=i;
        	break;
        }
    for(int i=0;i<201;++i)
        if(b[i]=='.'){
        	k2=i;
        	break;
        }
    for(int i=2;i>0;--i){
	    sum=a[k1+i]+b[k2+i]-'0'+state;
	    if(sum>'9'){
	    	c[199+i]=sum-10;
	    	state=1;
	    }
	    else{
	    	c[199+i]=sum;
	    	state=0;
	    }
	}
	c[199]='.';
	--k1,--k2;
	for(int i=198;k1>=0||k2>=0;--k1,--k2,--i){
		if(k1<0)
			sum=b[k2]+state;
		else if(k2<0)
			sum=a[k1]+state;
		else
			sum=a[k1]+b[k2]+state-'0';
		if(sum>'9'){
	    	c[i]=sum-10;
	    	state=1;
	    }
	    else{
	    	c[i]=sum;
	    	state=0;
	    }
	}
	if(state==1)
        cout<<'1';
	for(int i=0;i<202;++i)
		if(c[i]!='\0')
			cout<<c[i];
}
