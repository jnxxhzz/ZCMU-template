//树的分治
/*
给定一棵N(1<= N <=10000)个结点的带权树，定义dist(u,v)为u,v两点间的最短路径长度，
路径的长度定义为路径上所有边的权和。再给定一个 K  ，如果对于不同的两个结点a,b，
如果满足dist(a,b) <=K，则称(a,b)为合法点对。求合法点对个数。
思路：看了论文《分治算法在树的路径问题中的应用》，里面讲解的很清楚，一条路径要
么过根节点，要么在一颗子树中，所以用分治算法。找到树的重心作为根节点，这样每次
树的节点数至少减少一半。处理经过当前根节点路径<=k的点对数，然后把根节点去掉后就
把原来的树分成几颗子树了，再处理子树。我们在求经过一个根节点的路径时，里面还包含
了点对属于同一颗子树的情况，所以要去掉这部分的点。
dis(i)+dis(j)<=k(i,j的父节点不为根节点的同一个儿子）
=dis(i)+dis(j)<=k-dis(i)+dis(j)<=k(i,j的父节点属于根节点的同一儿子).
*/ 


#include <algorithm>  
#include<stdio.h>  
#include<string.h>  
const int N=10010;  
using namespace std;  
int head[N],num,f[N],son[N],n,D,root,size,ans,dis[N],d[N],cum;  
bool vis[N];  
#define max(a,b) (a<b?b:a)  
struct edge  
{  
    int st,ed,w,next;  
}e[N*2];  
void addedge(int x,int y,int w)  
{  
    e[num].st=x;e[num].ed=y;e[num].w=w;e[num].next=head[x];head[x]=num++;  
    e[num].st=y;e[num].ed=x;e[num].w=w;e[num].next=head[y];head[y]=num++;  
}  
void getroot(int u,int father)//求树的重心  
{  
    int i,v;  
    f[u]=0;son[u]=1;  
    for(i=head[u];i!=-1;i=e[i].next)  
    {  
        v=e[i].ed;  
        if(vis[v]||v==father)continue;  
        getroot(v,u);  
        son[u]+=son[v];  
        f[u]=max(f[u],son[v]);  
    }  
    f[u]=max(f[u],size-son[u]);  
    if(f[u]<f[root])root=u;  
}  
void getdis(int u,int father)//求节点到根节点的距离  
{  
    int i,v;  
    son[u]=1;//更新子树的节点的子节点数，不更新也能ac  
    d[cum++]=dis[u];//将点到根节点的距离加入数组  
    for(i=head[u];i!=-1;i=e[i].next)  
    {  
        v=e[i].ed;  
        if(vis[v]||v==father)continue;  
        dis[v]=dis[u]+e[i].w;  
        getdis(v,u);  
        son[u]+=son[v];  
    }  
}  
int cont(int u,int mit)  
{  
    int res=0,L,R;  
    dis[u]=mit;  
    cum=0;  
    getdis(u,0);  
    sort(d,d+cum);//将点到根节点的距离排序  
    for(L=0,R=cum-1;L<R;)  
    {  
        if(d[L]+d[R]<=D) res+=(R-L++);  
		//如果d[L]+d[R]<=D,L代表的节点可以与（R-L）个节点成对  
        else R--;  
    }  
    return res;  
}  
void work(int u)  
{  
    int i,v;  
   vis[u]=true;  
   ans+=cont(u,0);//路径经过该根节点的点对数  
   for(i=head[u];i!=-1;i=e[i].next)  
   {  
      v=e[i].ed;  
      if(vis[v])continue;  
      ans-=cont(v,e[i].w);//减去属于v子树的点对数  
      root=0;f[root]=size=son[v];  
      getroot(v,0);//求v子树的根节点  
      work(root);//求v子树的点对  
   }  
}  
int main()  
{  
    int i,x,y,w;  
    while(scanf("%d%d",&n,&D),n||D)  
    {  
        memset(head,-1,sizeof(head));  
        num=0;  
        for(i=1;i<n;i++)  
        {  
            scanf("%d%d%d",&x,&y,&w);  
            addedge(x,y,w);  
        }  
        memset(vis,false,sizeof(vis));  
        root=0;f[root]=size=n;ans=0;  
        getroot(1,0);  
        work(root);  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
