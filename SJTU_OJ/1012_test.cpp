#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=200007;
int d[maxn];
ll cnt[maxn],time[maxn];

int main()
{
	int s,t;
	scanf("%d%d",&s,&t);
	{
		memset(cnt,0,sizeof(cnt));
		int i,j,tmp,ans=1;
		cnt[1]=t-s+1;

		for(i=s;i<=t;i++)
		{
			d[i]=time[i]=1;
		}

		for(i=s;i<=t;i++)
		{
			for(j=1;j<=200;j++)
			{
				if( (i*j)%100 == 0)
				{
					tmp=i + i*j/100;
					if(tmp<=t)
					{
						if(d[i]+1>d[tmp])
						{
							d[tmp]=d[i]+1;
							time[tmp] = time[i];
						}
						else if(d[i]+1==d[tmp])
						{
							time[tmp] += time[i];
						}
						ans = max(ans,d[tmp]);
						cnt[d[i]+1] += time[i];
					}
				}
			}
		}
		printf("%d\n%lld\n",ans,cnt[ans]);
	}
	return 0;
}