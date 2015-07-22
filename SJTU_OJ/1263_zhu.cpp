#include<iostream>
#include<cstring>
using namespace std;
int data[51][51]={0};
int f[101][51][51];
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
        cin>>data[i][j];
    // memset(f,192,sizeof(f));
    f[2][1][1]=data[1][1];
    for(int l=3;l<=m+n-1;l++)
    for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++)
    {
        if(i==j||i>l-1||j>l-1)continue;
        if(i>1&&l-j>1)f[l][i][j]=max(f[l][i][j],f[l-1][i-1][j]);
        if(i>1&&j>1)f[l][i][j]=max(f[l][i][j],f[l-1][i-1][j-1]);
        if(l-i>1&&j>1)f[l][i][j]=max(f[l][i][j],f[l-1][i][j-1]);
        if(l-i>1&&l-j>1)f[l][i][j]=max(f[l][i][j],f[l-1][i][j]);
        f[l][i][j]+=data[i][l-i]+data[j][l-j];
    }
    cout<<max(f[m+n-1][m][m-1],f[m+n-1][m-1][m])+data[m][n]<<endl;
}