//LCA  ：最近公共祖先
//在静态的一棵树中(前提)
//多次查询任意两个节点的最近公共祖先和两点间距离 
//思路：DFS预处理+区间dp
//时间复杂度： 预处理：NlogN  查询：logN 
const int MAXN = 200000+100;  
const int M = 20 ;  // M > log2(MAXN) 
vector<int> G[MAXN];  
int deep[MAXN], fa[MAXN][M];  
void DFS(int cur, int pre)  
{   //cur:当前节点    pre:上一个节点 
    fa[cur][0] = pre;  //倍增祖先
    for(int i=1; i<M; ++i)  
        fa[cur][i] = fa[ fa[cur][i-1] ][i-1];  
    for(int i=0;i<G[cur].size();i++)  
    {  
  		int to=G[cur][i]; 
        if(to == pre) continue;  
        deep[to] = deep[cur] + 1;  
        DFS(to, cur);  
    }  
}  
int LCA(int x, int y)  
{  
    if(deep[x] > deep[y]) swap(x, y);  
    for(int i=0; i<M; ++i)  
        if(deep[y]-deep[x]>>i & 1)  
        	y = fa[y][i];  
    for(int i=M-1; i>=0; --i)  
        if(fa[x][i] != fa[y][i])  
            x = fa[x][i], y=fa[y][i];  
    return x == y?x:fa[x][0];  
}  
int main()  
{  
    int n, q; //总共 n 个节点， q 次询问 
    scanf("%d%d",&n,&q);  
	//节点编号为 1~N ，最多N-1条边 
    for(int i=2; i<=n; ++i)  
    {   //插入 x 与 y 的无向边 
        int x,y;  
        scanf("%d%d",&x,&y);  
        G[y].push_back(x);  
        G[x].push_back(y);  
    }  
    DFS(1, 0);  //以节点 1 为根，其深度为 0 
    while(q--)  
    {  
        int x,y;  
        scanf("%d%d",&x,&y);  
        printf("%d\n",LCA(x,y)); 
		//输出两个节点的最近公共祖先
		printf("%d\n",deep[x]+deep[y]-2*deep[LCA(x,y)]); 
    	//输出这两个节点间的距离 
	}  
    return 0;  
}  
