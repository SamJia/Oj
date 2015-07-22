#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n,m,state=2;
inline int dis(int pos){
	return(min(pos,n-pos));
}

int solve(int times,int pos){
    static int d=0;
    d=dis(pos);
	if(d>times)
		return(0);
	if(d==times){
        if(2*d==n)
            return(2);
		return(1);
	}
    if(!pos)
        return(2*(solve(times-2,(pos+2)%n)+solve(times-2,pos)));
	return(solve(times-2,(pos-2+n)%n)+solve(times-2,(pos+2)%n)+2*solve(times-2,pos));
}

main(){
    cin>>n>>m;
	cout<<solve(m,0);
}
