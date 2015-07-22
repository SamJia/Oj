#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    long long st;
    long long ed;
};
node ls[1000001];
struct que
{
    long long tail;
    long long head;
    que(int h,int t)
    {
        head = h;
        tail = t;
    }
    que():head(0),tail(0){}
};
que q[1000001];
bool comp(node a1,node a2)
{
    if(a1.st<a2.st)return 1;
    return 0;
}
int main()
{
    int n,t;
    cin>>n>>t;
    long long x1,x2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&x1,&x2);
        ls[i].st = x1;
        ls[i].ed = x1 + t*x2;
    }
    //qs(1,n);
    // sort(ls+1,ls+1+n,comp);
    int ans = 1;
    //q[1].head = hs[1].st;
    q[1].tail = ls[1].ed;
    for(int i=2;i<=n;i++)
    {
        bool flag = 0;
        for(int j=1;j<=ans;j++)
        {
            if(q[j].tail<ls[i].ed)
            {
                q[j].tail = ls[i].ed;
                //q[j].head = ls[i].st;
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            ans++;
           // q[ans].head = ls[i].st;
            q[ans].tail = ls[i].ed;
        }
    }
    cout<<ans<<endl;
}