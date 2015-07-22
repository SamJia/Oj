#include <iostream>
using namespace std;
main(){
	int l,w,a,b,sum,produce=0,p1=0;
	cin>>l>>w;
	int area[l][w];
	for(int i=0;i<l;++i)
        for (int j=0;j<w;++j)
            cin>>area[i][j];
    cin>>a>>b;
    int area1[l][w-b+1];
    for (int i=0;i<l;++i){
        for(int j=0;j<b;++j)
            p1+=area[i][j];
        area1[i][0]=p1;
        p1=0;
        for(int j=1;j<=w-b;++j)area1[i][j]=area1[i][j-1]+area[i][j+b-1]-area[i][j-1];
    }
    int area2[l-a+1][w-b+1];
    for (int i=0;i<=(w-b);++i){
        for(int j=0;j<a;++j)
            p1+=area1[j][i];
        area2[0][i]=p1;
        p1=0;
        for(int j=1;j<=l-a;++j)area2[j][i]=area2[j-1][i]+area1[j+a-1][i]-area1[j-1][i];
    }
	for(int i=0;i<=l-a;++i)
		for(int j=0;j<=w-b;++j)
			produce=produce>area2[i][j]?produce:area2[i][j];
	cout<<produce;
}
