#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m,p,j,c1,t1,g,d,total,ring,c[20],f[20],t[20];
bool flag,already;
string s,name,words,a[10];
char ch;

int findname(string st){
    int i;
    for (i=0;i<m;i++)
        if (a[i]==st) return i;
    return -1;
}

int findday(string st){
    if (st=="Monday.") return 1;
    if (st=="Tuesday.") return 2;
    if (st=="Wednesday.") return 3;
    if (st=="Thursday.") return 4;
    if (st=="Friday.") return 5;
    if (st=="Saturday.") return 6;
    if (st=="Sunday.") return 7;
    return 0;
}

int main(){
    int i;
    cin>>m>>n>>p;
    for (i=0;i<m;i++) cin>>a[i];
    ch=getchar();
    total=0;
    ring=-1;
    already=false;
    for (i=0;i<p;i++){
        getline(cin,s);
        t1=-1;
        name="";
        words="";
        for (j=0;j<s.length();j++)
            if (s[j]!=':') name=name+s[j];
            else break;
        words=s.substr(j+2,s.length()-j-2);
        j=findname(name);
        if (words=="I have the ring.") {
            c1=1;
            t1=j;
        }
        else if (words=="I have not the ring.") {
            c1=2;
            t1=j;
        }
        else if ((words.length()>=14)&&(words.substr(words.length()-14,14)==" has the ring.")) {
            c1=1;
            t1=findname(words.substr(0,words.length()-14));
        }
        else if ((words.length()>=18)&&(words.substr(words.length()-18,18)==" has not the ring.")) {
            c1=2;
            t1=findname(words.substr(0,words.length()-18));
        }
        else if ((words.length()>=10)&&(words.substr(0,9)=="Today is ")) {
            c1=3;
            t1=findday(words.substr(9,words.length()-9));
        }
        if (t1==-1) continue;
        f[total]=j;
        t[total]=t1;
        c[total]=c1;
        total++;
    }
	
	for (int out=0; out<total; out++)
		cout << f[out]<<" "<<t[out]<<" "<<c[out]<<endl;
	if (total==0) cout<<"Orz"<<endl;
	
	
	
}
