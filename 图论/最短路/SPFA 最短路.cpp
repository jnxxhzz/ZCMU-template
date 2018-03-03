/*	SPFA 最短路 
	
*/ 
const int INF=0x3f3f3f3f;  
const int maxm=511111;  
const int maxn=111111;  
struct EdgeNode{  
    int to;  
    int w;  
    int next;  
};  
EdgeNode edges[maxm];  
int N,M;  
int head[maxn],edge;  
bool vis[maxn];  
queue <int> que;  
int dis[maxn];  
void addedge(int u,int v,int c)  
{  
    edges[edge].w=c,edges[edge].to=v;
	edges[edge].next=head[u],head[u]=edge++;  
}  
void init()  
{  
    memset(head,-1,sizeof(head));  
    edge=0;  
}  
void spfa(int s,int n)//单源最短路(s为起点，n为节点总数)  
{  
    int u;  
    for (int i=0; i<=n; i++)  
        dis[i]=INF;  
    memset(vis,0,sizeof(vis));  
    while (!que.empty()) que.pop();  
    que.push(s);  
    vis[s]=true;  
    dis[s]=0;  
    while (!que.empty())  
    {  
        u=que.front();  
        que.pop();  
        vis[u]=false;  
        for (int i=head[u]; i!=-1; i=edges[i].next)  
        {  
            int v=edges[i].to;  
            int w=edges[i].w;  
            if (dis[v]>dis[u]+w)  
            {  
                dis[v]=dis[u]+w;  
                if (!vis[v])  
                {  
                    vis[v]=true;  
                    que.push(v);  
                }  
            }  
        }  
    }  
}  
