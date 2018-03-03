//单源最短路径  dijkstra算法  邻接矩阵
//时间复杂度：O(n^2) ——小数据或稠密图 
//参数：图的顶点数n, (有向)邻接矩阵mat[][] , 起点s ，空数组dis,pre 
//返回：s到各点最短距离dis[] , 路径pre[] 
//pre[i]记录s到i路径上i的父结点,pre[s]=-1 边权非负 
void Dijkstra(int n,int mat[][MAXN],int s,int* dis,int* pre)
{
	int vis[MAXN],i,j,k;
	for(i=0;i<n;i++)
		dis[i]=INF,vis[i]=0,pre[i]=-1;
	for(dis[s]=0,j=0;j<n;j++)
	{
		for(k=-1,i=0;i<n;i++)
			if(!vis[i]&&(k==-1||dis[i]<dis[k]))
				k=i;
		for(vis[k]=1,i=0;i<n;i++)
			if(!vis[i]&&dis[k]+mat[k][i]<dis[i])
				dis[i]=dis[k]+mat[ pre[i]=k ][i];
	}
}



