//最小费用最大流  邻接边集 
//适用于顶点数过多的情况 
//参数：起点begin  终点end 
//返回：最大流flow_max  最小费用cost_sum 
//注意：若最小点为1，可在0~1、n~n+1 间增加无穷大边 
//可改成无费用最大流
//定理： 任何网络中最大流的流量等于最小割的容量 
int vis[MAXN],dist[MAXN],pre[MAXN];
struct Edge{
    int x,y,v,cost,next;
}edge[MAX_E];
int head[MAXN],cnt;
int cost_sum,flow_max;
void init() //存边前对head数据进行预处理 
{
    cnt=0; //边的数量 
    memset(head,-1,sizeof(head));
}
void addedge(int x,int y,int v,int cost)
{
    edge[cnt].x=x;edge[cnt].y=y;edge[cnt].cost=cost;
    edge[cnt].v=v;edge[cnt].next=head[x];head[x]=cnt++;

    edge[cnt].x=y;edge[cnt].y=x;edge[cnt].cost=-cost;
    edge[cnt].v=0;edge[cnt].next=head[y];head[y]=cnt++;
}

bool spfa(int begin,int end)
{
    int x,y;
    queue<int> q;
    for(int i=0;i<=end+2;i++)
	{
        pre[i]=-1;
        vis[i]=0;
        dist[i]=INF;
    }
    vis[begin]=1;
    dist[begin]=0;
    q.push(begin);
    while(!q.empty())
	{
        x=q.front(); q.pop();
        vis[x]=0;
        for(int i=head[x];i!=-1;i=edge[i].next)
		{
            if(edge[i].v>0)
			{
                y=edge[i].y;
                if(dist[y]>dist[x]+edge[i].cost)
				{
                    dist[y]=dist[x]+edge[i].cost;
                    pre[y]=i;
                    if(!vis[y])
					{
                        vis[y]=true;
                        q.push(y);
                    }
                }
            }
        }
    }
    return dist[end]!=INF;
}
int MCMF(int begin,int end)
{
    int flow;
    cost_sum=flow_max=0;
    while(spfa(begin,end))
	{
        flow=INF;
        for(int i=pre[end];i!=-1;i=pre[edge[i].x])
            if(edge[i].v<flow)
                flow=edge[i].v;
        for(int i=pre[end];i!=-1;i=pre[edge[i].x])
		{
            edge[i].v-=flow;
            edge[i^1].v+=flow;
        }
        cost_sum += dist[end];
        flow_max += flow;
    }
    return cost_sum;
}



