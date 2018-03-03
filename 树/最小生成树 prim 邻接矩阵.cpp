//无向图最小生成树 prim 邻接矩阵 
//时间复杂度： o(n^2) 
//注意：必须保证图的连通 
int G[MAXN][MAXN];
void prim()
{   //默认起点为 0 
    int dis[MAXN],vis[MAXN];  
    int i,v,j,mi;  
    for(i=0;i<n;i++) 
        vis[i]=0,dis[i]=G[0][i];  
    for(i=0;i<n;i++)
	{  
        mi=INF;  
        for(j=0;j<n;j++)  
            if(!vis[j] && dis[j]<mi)  
                mi=dis[j],v=j;  
        vis[v]=j;  
        for(j=0;j<n;j++) 
            if(!vis[j] && G[v][j]<dis[j])  
                dis[j]=G[v][j];  
    }  
    for(dis[0]=0,i=0;i<n;i++) dis[0]+=dis[i];  
    return dis[0];   
}  


