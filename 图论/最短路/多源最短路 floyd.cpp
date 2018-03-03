//多源最短路径,floyd算法
//时间复杂度：O(n^3)
//参数：传入图的大小n, 邻接矩阵mat
//返回: 各点间最短距离dis[][] 和 路径pre[][]
//pre[i][j]记录i到j最短路径上j的父结点
int dis[MAXN][MAXN],pre[MAXN][MAXN];
void floyd(int n,int mat[][MAXN])
{	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			dis[i][j]=mat[i][j];
			pre[i][j]=(i==j)?-1:i;
		}
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		if(dis[i][k]+dis[k][j]<min[i][j])
		{
			dis[i][j]=dis[i][k]+dis[k][j];
			pre[i][j]=pre[k][j];
		}
}


