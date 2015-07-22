#include <stdio.h>
using namespace std;
long long a[210][210][2]={0};
bool ch[1001][1001]={0};
int main()
{
    int n,m,kmax,q;
    scanf("%d %d %d %d",&n,&m,&kmax,&q);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        a[i][j][0]=a[i][j][1]=0x7ffffffffff;
    }
    for(int i=1;i<=kmax;i++)
    {
        a[i][i][1]=0;
    }
    for(int i=kmax+1;i<=n;i++)
    {
        a[i][i][0]=0;
    }
    int x1,x2,x3;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x1,&x2,&x3);
        // if(x1<=kmax||x2<=kmax)
            // a[x1][x2][1]=x3;
        // else
            a[x1][x2][0]=x3;
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(a[i][j][0]>a[i][k][0]+a[k][j][0])
            a[i][j][0]=a[i][k][0]+a[k][j][0];
        if(a[i][j][1]>a[i][k][1]+a[k][j][0])
            a[i][j][1]=a[i][k][1]+a[k][j][0];
        if(a[i][j][1]>a[i][k][1]+a[k][j][1])
            a[i][j][1]=a[i][k][1]+a[k][j][1];
        if(a[i][j][1]>a[i][k][0]+a[k][j][1])
            a[i][j][1]=a[i][k][0]+a[k][j][1];
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(a[i][j][0]>a[i][k][0]+a[k][j][0])
            a[i][j][0]=a[i][k][0]+a[k][j][0];
        if(a[i][j][1]>a[i][k][1]+a[k][j][0])
            a[i][j][1]=a[i][k][1]+a[k][j][0];
        if(a[i][j][1]>a[i][k][1]+a[k][j][1])
            a[i][j][1]=a[i][k][1]+a[k][j][1];
        if(a[i][j][1]>a[i][k][0]+a[k][j][1])
            a[i][j][1]=a[i][k][0]+a[k][j][1];
    }
    long long ans=0,sum=0;
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d",&x1,&x2);
        if(a[x1][x2][1]<0x7ffffffffff)
        {
            ans++;
            sum+=a[x1][x2][1];
        }
    }
    printf("%lld\n%lld\n",ans,sum);
}