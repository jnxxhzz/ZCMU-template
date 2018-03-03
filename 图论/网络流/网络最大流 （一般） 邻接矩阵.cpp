//网络最大流  邻接矩阵 
//时间复杂度 ：n^2logm 
//参数：定点数n 图mat[][] 源点source 汇点sink 
//返回：最大流j 每条边的流量flow[][] 
//注意： 添加边：G[x][y]+=v (一般为单向) 
//定理： 任何网络中最大流的流量等于最小割的容量 
int max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN])
{
	int pre[MAXN],que[MAXN],dis[MAXN],p,q,t,i,j;
	if(source==sink) return INF;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) flow[i][j]=0;
	for(;;)
	{
		for(i=0;i<n;i++) pre[i]=0;
		pre[ t=source ]=source+1;
		dis[t]=INF;
		for (p=q=0 ; p<=q && !pre[sink] ; t=que[p++] )
			for (i=0;i<n;i++)
				if ( !pre[i] && (j=mat[t][i]-flow[t][i]) )
				{
					pre[ que[q++]=i ]=t+1;
					dis[i]= dis[t]<j ? dis[t] : j;
				}
				else if ( !pre[i] && (j=flow[i][t]) )
				{
					pre[ que[q++]=i ]=-t-1;
					dis[i]= dis[t]<j ? dis[t] : j;
				}
		if( !pre[sink] ) break;
		for( i=sink ; i!=source ; )
			if(pre[i]>0)
			{
				flow[ pre[i]-1 ][i]+=dis[sink];
				i=pre[i]-1;
			}
			else 
			{
				flow[i][ -pre[i]-1 ]-=dis[sink];
				i=-pre[i]-1;
			}
	}
	for(j=i=0;i<n;i++) j+=flow[source][i];
	return j;
 } 
 
 
