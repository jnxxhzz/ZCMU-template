//树状数组求逆序数  离散化
//时间复杂度：N*logN 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define lowbit(k) k&(-k)
typedef long long ll;
const int N=1e5+10;
int c[N],b[N];
int n,x,y;
struct node{
    ll w;
    int t;
}a[N];
bool cmp(node x,node y)
{ return x.w<y.w; }
void update(int tt,ll value)
{
    for(int i=tt;i<=n;i+=lowbit(i))
        c[i]+=value;
}
ll getsum(int tt)
{
    int sum=0;
    for (int i=tt;i>=1;i-=lowbit(i))
        sum+=c[i];
    return sum;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i].w,a[i].t=i;
        sort(a+1,a+1+n,cmp);
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].w!=a[i-1].w) sum++;
            b[a[i].t]=sum;
        }
        ll cnt=0;
        for(int i=1;i<=n;i++)
        {
            update(b[i],1);
            cnt+=(ll)(i-getsum(b[i]));
        }
        printf("%lld\n",cnt);
    }
    return 0;
}


