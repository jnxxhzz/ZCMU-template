//二部图最大匹配  邻接表
//时间复杂度：O(sqrt(V)*E) 
//初始化：vector<>G 邻接表  G[i].clear;  
//建图：两部分顶点数 Nx Ny  
//		(x->y : G[x].push_back(y); )
//      无向图要双向插入边 
//返回：最大匹配res  匹配数组 Left[]
//改成普通图最大匹配：总顶点数 Nx = Ny = n+m ; 
vector<int> G[MAXN];
int Nx,Ny;
int Left[MAXN];
bool vis[MAXN];
bool match(int i)
{
	if(vis[i]) return false;
	vis[i]=true;
    for(int j=0;j<G[i].size();++j) 
		if(!vis[G[i][j]])
	    {
	        int v = G[i][j];
	        if(Left[v]<0||match(Left[v]))
	        {
	            Left[v] = i;
	            Left[i] = v;
	            return true;
	        }
	    }
    return false;
}
//返回最大匹配数
int hungary()
{
    int res=0;
    clr(Left,-1);
    for(int i=0;i<Ny;++i)
    	if(Left[i]<0)
	    {  //从0点开始 
	        clr(vis,0);
	        if(match(i)) res++;
	    }
    return res;
}


