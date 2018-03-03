//有向图强联通分量   BFS 邻接矩阵 
//时间复杂度：O(n^2) 
//强连通分量：内部每个点都相互可达的连通分量 
//返回： 强连通分量数ret  
//id[x]: 顶点x属于第id[x]个强联通分量 
//有关题目关键在于使用id[]判断顶点是否属于同一个强联通分量 
int n;
int G[MAXN][MAXN];
int id[MAXN];
int find_components()
{
	int ret=0,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
	clr(id,0);
	for(int k=0;k<n;k++)
	if(!id[k])
	{
		for(int i=0;i<n;i++)
			a[i]=b[i]=c[i]=d[i]=0;
		a[k]=b[k]=1;
		int ok=1;
		while(ok)
		{
			ok=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]&&!c[i])
				{
					c[i]=ok=1;
					for(int j=0;j<n;j++)
						if(G[i][j]&&!a[j])
							a[j]=1;
				}
				if(b[i]&&!d[i])
				{
					d[i]=ok=1;
					for(int j=0;j<n;j++)
						if(G[j][i]&&!b[j])
							b[j]=1;
				}
			}
		}
		ret++;
		for (int i=0;i<n;i++)
			if (a[i]&b[i])  id[i]=ret;
	}
	return ret;
}


