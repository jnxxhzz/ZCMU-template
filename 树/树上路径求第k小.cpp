/*
题意：

求树上A，B两点路径上第K小的数

分析：

同样是可持久化线段树，只是这一次我们用它来维护树上的信息。

我们之前已经知道，可持久化线段树实际上是维护的一个前缀和，而前缀和不一定要出现在一个线性表上。

比如说我们从一棵树的根节点进行DFS，得到根节点到各节点的距离dist[x]——这是一个根-x路径上点与根节点距离的前缀和。

利用这个前缀和，我们可以解决一些树上任意路径的问题，比如在线询问[a,b]点对的距离——答案自然是dist[a]+dist[b]-2*dist[lca(a,b)]。

同理，我们可以利用可持久化线段树来解决树上任意路径的问题。

DFS遍历整棵树，然后在每个节点上建立一棵线段树，某一棵线段树的“前一版本”是位于该节点父亲节点fa的线段树。

利用与之前类似的方法插入点权(排序离散)。那么对于询问[a,b]，答案就是root[a]+root[b]-root[lca(a,b)]-root[fa[lca(a,b)]]上的第k大。

*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int MAXN=1e5+100;
const int POW=18;
int num[MAXN],hash[MAXN];
int ls[MAXN*20],rs[MAXN*20];
int sum[MAXN*20];
int root[MAXN];
vector<int> G[MAXN];
int d[MAXN];
int p[MAXN][POW];
int tot;
int f[MAXN];
void build(int l,int r,int& rt)
{
    rt=++tot;
    sum[rt]=0;
    if(l>=r)return;
    int m=(l+r)>>1;
    build(l,m,ls[rt]);
    build(m+1,r,rs[rt]);
}
void update(int last,int p,int l,int r,int &rt)
{
    rt=++tot;
    ls[rt]=ls[last];
    rs[rt]=rs[last];
    sum[rt]=sum[last]+1;
    if(l>=r)return ;
    int m=(l+r)>>1;
    if(p<=m)update(ls[last],p,l,m,ls[rt]);
    else update(rs[last],p,m+1,r,rs[rt]);
}
int query(int left_rt,int right_rt,int lca_rt,int lca_frt,int l,int r,int k)
{
    if(l>=r)return l;
    int m=(l+r)>>1;
    int cnt=sum[ls[right_rt]]+sum[ls[left_rt]]-sum[ls[lca_rt]]-sum[ls[lca_frt]];
    if(k<=cnt)
        return query(ls[left_rt],ls[right_rt],ls[lca_rt],ls[lca_frt],l,m,k);
    else 
        return query(rs[left_rt],rs[right_rt],rs[lca_rt],rs[lca_frt],m+1,r,k-cnt);
}
void dfs(int u,int fa,int cnt)
{
    f[u]=fa;
    d[u]=d[fa]+1;
    p[u][0]=fa;
    for(int i=1;i<POW;i++)p[u][i]=p[p[u][i-1]][i-1];

    update(root[fa],num[u],1,cnt,root[u]);
    for(int i=0;i<(int)G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa)continue;
        dfs(v,u,cnt);
    }
}
int lca(int a,int b)
{
    if(d[a]>d[b])a^=b,b^=a,a^=b;
    if(d[a]<d[b])
    {
        int del=d[b]-d[a];
        for(int i=0;i<POW;i++)
            if(del&(1<<i))b=p[b][i];
    }
    if(a!=b)
    {
        for(int i=POW-1;i>=0;i--)
        {
            if(p[a][i]!=p[b][i])
            {
                a=p[a][i],b=p[b][i];
            }
        }
        a=p[a][0],b=p[b][0];
    }
    return a;
}
int main()
{
        int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        REP(i,0,n)
        {
            G[i].clear();
        }
        CL(d,0);
        CL(p,0);
        CL(f,0);
        REP(i,1,n)
        {
            scanf("%d",&num[i]);
            hash[i]=num[i];
        }
        tot=0;
        sort(hash+1,hash+1+n);
        int cnt=unique(hash+1,hash+n+1)-hash-1;
        REP(i,1,n)
        {
            num[i]=lower_bound(hash+1,hash+cnt+1,num[i])-hash;
        }
        int a,b,c;
        REP(i,1,n-1)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        build(1,cnt,root[0]);
        dfs(1,0,cnt);
        REP(i,1,m)
        {
            scanf("%d%d%d",&a,&b,&c);
            int t=lca(a,b);
            int id=query(root[a],root[b],root[t],root[f[t]],1,cnt,c);
            printf("%d\n",hash[id]);
        }
    }
    return 0;
}