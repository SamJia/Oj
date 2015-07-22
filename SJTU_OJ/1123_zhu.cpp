#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int x[50001];
int y[50001];
int yy[50001]={0};
int f[50001][2][11]={0};
int ch[100001]={0};
int n,k;
struct seg
{
    seg(int a1,int a2):l(a1),r(a2),lchild(NULL),rchild(NULL){memset(data,0,sizeof(data));}
    int l,r;
    int data[2][11];
    seg *lchild,*rchild;
};
seg *root;
void create(seg *subroot)
{
    int mid=(subroot->l+subroot->r)/2;
    subroot->lchild=new seg(subroot->l,mid);
    subroot->rchild=new seg(mid+1,subroot->r);
    if(subroot->l<mid)create(subroot->lchild);
    if(subroot->r>mid+1)create(subroot->rchild);
}
void update(seg *subroot,int num,int t,int val1,int val2)
{
    //cout<<subroot->l<<" "<<subroot->r<<endl;
    if(subroot->l==subroot->r)
    {
        subroot->data[0][t]=val1;
        subroot->data[1][t]=val2;
        return;
    }
    if(subroot->lchild->r>=num)update(subroot->lchild,num,t,val1,val2);
    else if(subroot->rchild->l<=num)update(subroot->rchild,num,t,val1,val2);
    subroot->data[1][t]=(subroot->lchild->data[1][t]+subroot->rchild->data[1][t])%100007;
    subroot->data[0][t]=(subroot->lchild->data[0][t]+subroot->rchild->data[0][t])%100007;
}
int search(seg *subroot,int a,int b,int dir,int t)
{
    if(a>b)return 0;
    if(subroot->l==a&&subroot->r==b)return subroot->data[dir][t];
    int mid=(subroot->l+subroot->r)/2;
    if(b<=mid)return search(subroot->lchild,a,b,dir,t)%100007;
    else if(mid+1<=a)return search(subroot->rchild,a,b,dir,t)%100007;
    else return (search(subroot->lchild,a,mid,dir,t)+search(subroot->rchild,mid+1,b,dir,t))%100007;
}
void init()
{
    root=new seg(1,n);
    create(root);
}
void qs(int l,int r)
{
    int i,j,tmpx,tmpy;
    i=l;j=r;tmpx=x[i];tmpy=y[i];
    while(i<j)
    {
        while(i<j&&x[j]>=tmpx)j--;
        if(i<j){int t;t=x[i];x[i]=x[j];x[j]=t;t=y[i];y[i]=y[j];y[j]=t;i++;}
        while(i<j&&x[i]<=tmpx)i++;
        if(i<j){int t;t=x[i];x[i]=x[j];x[j]=t;t=y[i];y[i]=y[j];y[j]=t;j--;}

    }
    x[i]=tmpx;
    y[i]=tmpy;
    if(l<i-1)qs(l,i-1);
    if(i+1<r)qs(i+1,r);
}
void quicks()
{
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        ch[y[i]]=i;
    }
    for(int i=1;i<=100000;i++)
        if(ch[i]>0)
        {
            yy[ch[i]]=++cnt;
        }
}
int main()
{
    
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d %d",&x[i],&y[i]);
    qs(1,n);
    quicks();
    init();
   // cout<<root->l<<root->r<<endl;
    /*for(int i=1;i<=n;i++)
    {
        f[i][0][0]=f[i][1][0]=1;
        update(root,yy[i],0,f[i][0][0],f[i][1][0]);
    }*/
    for(int i=n;i>=1;i--)
    {
        f[i][0][0]=f[i][1][0]=1;
        update(root,yy[i],0,f[i][0][0],f[i][1][0]);
    for(int t=1;t<=k;t++)
    {
        f[i][1][t]=(search(root,yy[i]+1,n,1,t)+search(root,yy[i]+1,n,0,t-1))%100007;
        f[i][0][t]=(search(root,1,yy[i]-1,0,t)+search(root,1,yy[i]-1,1,t-1))%100007;
        update(root,yy[i],t,f[i][0][t],f[i][1][t]);
    }}/*
            for(int j=i+1;j<=n;j++){
                if(y[j]>y[i])
                    f[i][1][t]=(f[i][1][t]+f[j][1][t]+f[j][0][t-1])%100007;
                else
                    f[i][0][t]=(f[i][0][t]+f[j][0][t]+f[j][1][t-1])%100007;}*/

    int ans=0;
//cout<<f[5][1][1]<<f[5][0][1]<<endl;
    for(int i=1;i<=n;i++){ans+=f[i][0][k]+f[i][1][k];ans=ans%100007;}
        cout<<ans<<endl;
}