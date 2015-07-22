#include <iostream>
using namespace std;
int main(){
	char a[30],result[15];
	int i,j,k,state=0,sol;
	while(1){
		cin.getline(a,30);
		if(a[0]=='\0')
			return 0;
		for(i=0;a[i]!=' ';++i);
		for(j=i;a[j]!='\0';++j);
		for(k=14,--i,--j;i>=0||a[j]!=' ';){
			if(i<0)
				sol=a[j--]+state-'0';
			else if(a[j]==' ')
				sol=a[i--]+state-'0';
			else{
				sol=(a[i--]+a[j--]-'0'-'0'+state);}
            result[k--]=sol%10+'0';
			state=sol/10;
		}

		if(state==1){
            result[k--]='1';
            state=0;
		}
		for(++k;k<15;++k)
			cout<<result[k];
		cout<<'\n';
	}
}
