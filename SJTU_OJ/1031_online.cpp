#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <climits>//形如INT_MAX一类的
#define MAX 105
#define INF 0x7FFFFFFF
# define eps 1e-5
using namespace std;

int map[MAX][MAX];
int vis[MAX][MAX];
int dirx[4]= {1,0,0,-1};
int diry[4]= {0,1,-1,0};
int n,judge,small,big;

bool ok(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}

int dfs(int x,int y)
{
    if(map[x][y] < small || map[x][y] > big)
        return 0;
    if(x == n-1 && y == n-1)
        return 1;
    vis[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        if(ok(x + dirx[i],y + diry[i]) && !vis[x + dirx[i]][y + diry[i]])
        {
            if(dfs(x + dirx[i],y + diry[i]))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int t,i,j;
    int Casee=1;
    t=1;
    ifstream fin("1031.txt");
    while(t--)
    {
        fin >> n;
        int high=0,low=205,mid;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                fin>>map[i][j];
                if(high < map[i][j])
                    high = map[i][j];
                if(low > map[i][j])
                    low = map[i][j];
            }
        int ans = 0;
        high -= low;
        low = 0;
        mid = (high + low)/2;
        while(low <= high)
        {
            for(small = max(map[0][0]-mid,0),big = small + mid; small<=map[0][0]; small++,++big)
            {
                memset(vis,0,sizeof(vis));
                if(dfs(0,0))
                {
                    ans = mid;
                    break;
                }
            }
            if(small <= map[0][0])
                high = mid - 1;
            else
                low = mid + 1;
            mid = (high+ low)/2;
            cout<<low<<' '<<high<<'\n';
        }
        printf("%d\n",ans);
        cout << endl;
    }
    fin.close();
    return 0;
}
