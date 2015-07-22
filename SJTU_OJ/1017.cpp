#include <iostream>
#include <string.h>
using namespace std;
void product(char *mon1,char *mon2,int a){
	int prod,state=0;
    for(int i=2999;i>=0;--i){
    	prod=(mon2[i]-'0')*a+state+mon1[i]-'0';
    	mon1[i]=prod%10+'0';
    	state=prod/10;
    }

}

void plus1(char *mon1,char *mon2){
	int sum,state=0;
	for(int i=2999;i>=0;--i){
    	sum=mon1[i]+mon2[i]-'0'-'0'+state;
    	mon1[i]=sum%10+'0';
    	state=sum/10;
    }
}

void print(char *mon){
    int state=0;
    for(int i=0;i<3000;++i)
        if(state||(mon[i]-'0')){
            cout<<mon[i];
            state=1;
    }
}

main(){
	char mon1[3000],mon2[3000],mon3[3000],birth[3000];
	char *p1=mon1,*p2=mon2,*p3=mon3,*pb=birth;
	for(int i=0;i<3000;++i)
		mon1[i]=mon2[i]=mon3[i]=birth[i]='0';
	mon1[2999]+=1;
	int a,b,c,n,state=1;
	cin>>a>>b>>c>>n;
	for(int i=0;i<n;++i){
	    if(state){
            product(pb,p1,a);
            state=0;
	    }
        else
            product(pb,p1,a-1);
		product(pb,p2,b);
		product(pb,p3,c);
		plus1(p3,p2);
        strncpy(p2,p1,3000);
		strncpy(p1,pb,3000);
	}
	plus1(p1,p2);
	plus1(p1,p3);
    print(p1);
}




/*int main(){
	char *mon1[3000],*mon2[3000],*mon3[3000],*birth[3000];
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	for(int i=0;i<n;++i){
		birth=a*mon1+b*mon2+c*mon3;
		mon3+=mon2;
		mon2=mon1;
		mon1=birth;
	}
	cout<<(mon1+mon2+mon3);
	return 0;
}*/
