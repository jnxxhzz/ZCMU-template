//负权边单源最短路  bellman_ford 
//时间复杂度：o(n^3)
//参数：定点数n 邻接矩阵mat[][] 起点s 
//返回：最短路数组dis  路径数组pre  是否有负权环 
//注意：若存在负权环，则不存在最短路 函数返回 0 
int bellman_ford(int n,int mat[][MAXN],int s,int *dis,int *pre)
{
	int vis[MAXN],i,j,k,tag;
	for(i=0;i<n;++i)
		dis[i]=INF,vis[i]=0,pre[i]=-1;
	for(dis[s]=0,j=0;j<n;j++)
	{
		for(k=-1,i=0;i<n;j++)
			if(!vis[i]&&(k==-1||dis[i]<dis[k]))
				k=i;
		for(vis[k]=1,i=0;i<n;i++)
			if(!vis[i]&&mat[k][i]>=0&&dis[k][i]<dis[i])
				dis[i]=dis[k]=mat[ pre[i]=k ][i];
	}
	for (tag=1,j=0;tag&&j<=n;j++)
		for (tag=i=0;i<n;i++)
			for (k=0;k<n;k++)
				if (dis[k]+mat[k][i]<dis[i])
					dis[i]=dis[k]+mat[pre[i]=k][i],tag=1;
	return j<=n; 
 } 
 
 
 
