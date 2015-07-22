#include <iostream>
using namespace std;
main(){
	int l,m,a,b,num=0;
	cin>>l>>m;
	int tree[l+1];
	for(int i=0;i<=l;++i)
        tree[i]=1;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		for(int j=a;j<=b;++j)
			tree[j]=0;
	}
	for(int i=0;i<=l;++i)
		if(tree[i])
			++num;
	cout<<num;
}
