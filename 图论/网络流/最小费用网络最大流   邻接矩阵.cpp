//最小费用最大流  邻接矩阵 
//参数：网络节点数n 流量图mat[][] 费用图cost[][] 源点source,汇点sink
//返回: 最大流量j  每条边的流量flow[][]  总费用netcost
int flow[MAXN][MAXN];
int netcost;
int Min_cost_max_flow(int n,int mat[][MAXN],int cost[][MAXN],int source,int sink)
{
	int pre[MAXN],Min[MAXN],d[MAXN],i,j,t,tag;
	if (source==sink) return INF;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++) flow[i][j]=0; 
	netcost=0;
	for (;;)
	{
		for (i=0;i<n;i++)
			pre[i]=0,Min[i]=INF;
		pre[source]=source+1;
		Min[source]=0;
		d[source]=INF; 
		for(tag=1;tag;)
		{
			tag=0;
			for (t=0;t<n;t++)
				if (d[t])
					for (i=0;i<n;i++)
						if ( j=mat[t][i]-flow[t][i] &&
							 Min[t]+cost[t][i]<Min[i] )
						{
							tag=1;
							Min[i]=Min[t]+cost[t][i];
							pre[i]=t+1;
							d[i]=d[t]<j?d[t]:j;
						}	
						else if ( j=flow[i][t] && Min[t]<INF &&
							 Min[t]-cost[i][t]<Min[i] )
						{
							tag=1;
							Min[i]=Min[t]-cost[i][t];
							pre[i]=-t-1;
							d[i]=d[t]<j?d[t]:j;
						}
		}
		if (!pre[sink])	break;
		for (netcost+=Min[sink]*d[i=sink];i!=source;)
			if (pre[i]>0)
			{
				flow[pre[i]-1][i]+=d[sink];
				i= pre[i]-1;
			}
			else
			{
				flow[i][-pre[i]-1]-=d[sink];
				i= -pre[i]-1;
			}		
	}
	for (j=i=0;i<n;i++) j+=flow[source][i];
	return j;
}



