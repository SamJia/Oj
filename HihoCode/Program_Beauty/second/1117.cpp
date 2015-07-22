#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
struct node
{
    int fa;
    int pa;
    int left,right;
    ~node(){}
};
node a[800001];
char *p = new char[800001];
//int val[100001]={0};
int create(string s,int f,int b)
{
    int c = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            c++;
            if(c==1)s[i]=' ';
        }
        else if(s[i]==')')
        {
            c--;
            if(c==0)s[i]=' ';
        }
    }
    stringstream is(s);
    int num;
    string x;
    is>>num;
    a[num].left = -1;
    a[num].right = -1;
   // a[num].minx = -1;
    if(f>0)a[num].fa = f;
    else a[num].fa = a[b].fa;
    a[num].pa = max(f,b);
    int cnt = num;
    while(is>>x)
    {
        if(cnt==num)
        {
            a[num].left = create(x,cnt,-1);
            cnt = a[cnt].left;
        }
        else
        {
            a[cnt].right = create(x,-1,cnt);
            cnt = a[cnt].right;
        }
    }
    is.clear();
    return num;
}
int getit(int t)
{
    int mx;
    if(a[t].left==-1)mx = t;
    else mx = getit(a[t].left);
    if(a[t].right!=-1)mx = min(mx,getit(a[t].right));
    //val[t] = mx;
    return mx;
}
int init()
{
 
    gets(p);
    string ch = "";
    while(*p!='\0')
    {
        if(*p!=' ')ch+=*p;
        p++;
    }
    //string ch ="(1 (2 (3)))";
    ch = ch.substr(1,ch.length()-2);
    int root = create(ch,0,-1);
    return root;
}
int main()
{
    int root = init();
    int tmp = getit(root);
    int cnt = 0;
    while(tmp!=root)
    {
        if(a[root].left!=-1&&a[a[root].left].right==-1&&tmp>root)
        {
            cout<<a[root].left<<" ";
            a[a[root].left].pa = 0;
            a[a[root].left].fa = 0;
            root = a[root].left;
            tmp = getit(root);
            continue;
        }
        cout<<a[tmp].fa<<" ";
        if(a[a[tmp].fa].left == tmp)
        {
            a[a[tmp].fa].left = a[tmp].right;
            if(a[tmp].right!=-1)a[a[tmp].right].pa = a[tmp].fa;
        }
        else
        {
            a[a[tmp].pa].right = a[tmp].right;
            if(a[tmp].right!=-1)a[a[tmp].right].pa = a[tmp].pa;
        }
        tmp = getit(root);
    }
    //cout << "asd";
    return 0;
}