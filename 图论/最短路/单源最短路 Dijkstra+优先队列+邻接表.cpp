//单源最短路径  dijkstra+优先队列+邻接表 
//时间复杂度：O(ElogV)   大数据或稀疏图 
//参数：起点 s 
//返回：s到各点最短距离dis[]
//注意：不得有负权边 
struct node{  
    int to,cost;  
    node(int a,int b){ to=a;cost=b; }  
    bool operator<(const node &a) const  
    { return cost > a.cost;  } //cost从小到大排序 
};  
vector<node> G[MAXN];  
//插入边方法： (x->y : v)
//G[x].push_back(node(y,v));
int dis[MAXN];  
void dijkstra(int s)  
{  
    int i;  
    for(i=0;i<MAXN;i++) dis[i]=INF;  
    dis[s]=0;  
    priority_queue<node> pq;  
    pq.push(node(s,dis[s]));  
    while(!pq.empty())  
    {  
        node x=pq.top();  
        pq.pop();  
        for(i=0;i<G[x.to].size();i++)  
        {  
            node y=G[x.to][i];  
            if(dis[y.to]>x.cost+y.cost)  
            {  
                dis[y.to]=x.cost+y.cost;  
                pq.push(node(y.to,dis[y.to]));  
            }  
        }  
    }  
}  



