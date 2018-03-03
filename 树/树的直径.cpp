/*  树的直径： 
	定义：树上任意两点的距离的最大值。
	复杂度：O(n)
	方法：两次BFS。任取一点找最远的点u
		  找离 u 最远的点 v ，u->v即是直径 
    注意：使用前dis，G都要初始化 
    
*/  
#define MAXN 105  
vector<int> G[MAXN];  
int n,m;  
int dis[MAXN];  
int bfs(int u)  
{  
    queue<int> que;  
    que.push(u);  
    dis[u]=0;  
    int Max=0,Maxi=1;  
    while(!que.empty())  
    {  
        int f=que.front();  
        que.pop();  
        if(dis[f]>Max) Maxi=f;  
        for(int i=0; i<G[f].size(); i++)  
        {  
            int to=G[f][i];  
            if(dis[to]==-1)  
                que.push(to),dis[to]=dis[f]+1;  
        }  
    }  
    return Maxi;  
}  
int main()  
{  
    while(~scanf("%d",&n))  
    {  
        for(int j=0; j<MAXN; j++) G[j].clear();  
        for(int j=1; j<n; j++)  
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            G[u].push_back(v);  
            G[v].push_back(u);  
        }  
        memset(dis,-1,sizeof dis);  
        int p=bfs(1);  
        memset(dis,-1,sizeof dis);  
        int q=bfs(p);  
        int ans=dis[q];  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
