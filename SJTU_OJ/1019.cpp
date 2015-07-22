#include <iostream>
using namespace std;
main(){
	int n,num=0;
	char str[100];
	for(cin>>n;n > 0;num = 0, --n){
		cin>>str;
		for(char i=0;str[i]&&num>=0;--num,++i)
			if(str[i]=='(')
				num+=2;
		if(!num)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}