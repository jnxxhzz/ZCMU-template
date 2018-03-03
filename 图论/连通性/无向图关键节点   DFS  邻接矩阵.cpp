//无向图关键节点   DFS  邻接矩阵 
//关键点： 若去除此点则图的连通分量数增加 
//时间复杂度： O(n^2) 
//预处理： 顶点数n  图G (x-y:G[x][y]=G[y][x]=1)  
//返回： 关键点个数ret  关键点数组 key[] 
int n;
int G[MAXN][MAXN];
int key[MAXN];
int dfn[MAXN],low[MAXN],bb[MAXN];
void search(int now,int& ret,int& cnt,int root,int& rd)
{
	int i;
	dfn[now]=low[now]=++cnt;
	for (i=0;i<n;i++)
		if (G[now][i])
		{
			if (!dfn[i])
			{
				search(i,ret,cnt,root,rd);
				if (low[i]<low[now])
					low[now]=low[i];
				if (low[i]>=dfn[now])
				{
					if (now!=root&&!bb[now])
						key[ret++]=now,bb[now]=1;
					else if(now==root)
						rd++;
				}
			}
			else if (dfn[i]<low[now])
				low[now]=dfn[i];
		}
}
int key_vertex()
{
	int ret=0,i,cnt,rd;
	for (i=0;i<n;i++) dfn[i]=bb[i]=low[i]=0;
	cnt=0;
	for (int i=0;i<n;i++)
		if (!dfn[i])
		{
			rd=0;
			search(n,i,ret,cnt,i,rd);
			if (rd>1&&!bb[i])
				key[ret++]=i,bb[i]=1;
		}
	return ret;
}



