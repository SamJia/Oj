#include<iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;
long long a[100010]={0};
int man[1000001];
int woman[1000001];
class List{
private:
    struct node{
        int dat;
        node *next;
        node(int x, node *n=NULL)
        {
            dat = x;
            next = n;
        }
        node():next(NULL){}
        };
    node *head,*rear;
    int CurrentSize;
public:
    List()
    {
        head = new node;
        rear = head;
        CurrentSize = 0;
    }
    ~List()
    {
        node *pp = head;
        while(pp)
        {
            node *qq;
            qq = pp;
            pp = pp->next;
            delete qq;
        }
        CurrentSize=0;
    }
    int visit()
    {
        if(CurrentSize==0)return 0;
        return head->next->dat;
    }
    void push(int x)
    {
        node *tmp = new node(x,NULL);
        rear->next = tmp;
        rear = rear->next;
        CurrentSize++;
    }
    void pop()
    {
        if(CurrentSize==0)return;
        node *tmp = head->next;
        head->next = tmp->next;
        delete tmp;
        CurrentSize--;
    }
    bool Empty()
    {
        return CurrentSize==0;
    }
};
void qs(int h,int t)
{
    int i,j,x;
    i = h;
    j = t;
    x = man[i];
    while(i<j)
    {
        while(i<j&&man[j]>x)j--;
        if(i<j){man[i]=man[j];i++;}
        while(i<j&&man[i]<x)i++;
        if(i<j){man[j]=man[i];j--;}
    }
    man[i]=x;
    if(h<i-1)qs(h,i-1);
    if(i+1<t)qs(i+1,t);
}
void qs2(int h,int t)
{
    int i,j,x;
    i = h;
    j = t;
    x = woman[i];
    while(i<j)
    {
        while(i<j&&woman[j]>x)j--;
        if(i<j){woman[i]=woman[j];i++;}
        while(i<j&&woman[i]<x)i++;
        if(i<j){woman[j]=woman[i];j--;}
    }
    woman[i]=x;
    if(h<i-1)qs2(h,i-1);
    if(i+1<t)qs2(i+1,t);
}
int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i+1]=a[i]+x;
    }
    int mcnt = 0;
    int wcnt = 0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,h;
        scanf("%d %d",&x,&h);
        if(x==1)
        {
            mcnt++;
            man[mcnt]=h;
        }
        else
        {
            wcnt++;
            woman[wcnt]=h;
        }
    }
    if(mcnt>=2)sort(man+1,man + mcnt+1);
    if(wcnt>=2)sort(woman+1, woman + wcnt+1);
    List a1;
    List a2;
    for(int i=1;i<=mcnt;i++)
    {
        a1.push(man[i]);
    }
    for(int j=1;j<=mcnt;j++)
    {
        a2.push(woman[j]);
    }
    long long ans1,ans2;
    ans1 =0;
    ans2 =0;
    for(int i=1;i<=n;i++)
    {
        int t1 = a1.visit();
        int t2 = a2.visit();
        while(!a1.Empty()&&!a2.Empty()&&t1<=a[i]&&t2<=a[i])
        {
            ans1+=a[i]-t1;
            ans2+=a[i]-t2;
            a1.pop();
            a2.pop();
            if(!a1.Empty())t1 = a1.visit();
            if(!a2.Empty())t2 = a2.visit();
        }
    }
    if(!a1.Empty())
    {
        int t1 = a1.visit();
        while(!a1.Empty())
        {
            ans1+=a[n]-t1;
            a1.pop();
            if(!a1.Empty())t1 = a1.visit();
        }
    }
    if(!a2.Empty())
    {
        int t2 = a2.visit();
        while(!a2.Empty())
        {
            ans2+=a[n]-t2;
            a2.pop();
            if(!a2.Empty())t2 = a2.visit();
        }
    }
    double anss1 = 1.0*ans1/mcnt;
    double anss2 = 1.0*ans2/wcnt;
    printf("%.2f %.2f\n",anss1,anss2);
}