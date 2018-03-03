/*树的重心：
	性质：
	1、树中所有点到某个点的距离和中，到重心的距离和是最小的；
		如果有两个重心，那么他们的距离和一样。 
	2、把两个树通过一条边相连得到一个新的树，那么新的树的重心在连接
		原来两个树的重心的路径上。 
	3、把一个树添加或删除一个叶子，那么它的重心最多只移动一条边的距离。 

    方法：    找到一个点，其所有的子树中最大的子树节点数最少,
那么这个点就是这棵树的重心,删去重心后，生成的多棵树尽可能平衡。

树的重心可以通过简单的两次搜索求出，第一遍搜索求出每个结点的
子结点数量son[u]，第二遍搜索找出使max{son[u],n-son[u]-1}最小的结点。

实际上这两步操作可以在一次遍历中解决。对结点u的每一个儿子v，
递归的处理v，求出son[v]，然后判断是否是结点数最多的子树，处理
完所有子结点后，判断u是否为重心。 

*/
int n;  
vector <int> adj[MAXN];  
int son[MAXN];  
bool vd[MAXN];  
int ans,asize = 1<<29;  
void DFS(int s)  
{  
    vd[s] = 1;  
    son[s] = 0;  
    int blance = 0;  
    int size = adj[s].size();  
    for (int j = 0;j < size;j++)  
    {  
        int u = adj[s][j];  
        if (vd[u]) continue;  
        DFS(u);  
        son[s] += son[u]+1;  
        blance = max(blance,son[u]+1);  
    }  
    blance = max(blance,n - son[s] - 1);  
    if (blance < asize || blance == asize && s < ans)  
        ans = s,asize = blance;  
}  
  
int main()  
{  
//    freopen("test.txt","r",stdin);  
    int T;  
    cin>>T;  
    while(T--)  
    {  
        cin>>n;  
        for (int i = 1;i <= n;i++) adj[i].clear();  
        for (int i = 1;i <= n-1;i++)  
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            adj[u].push_back(v);  
            adj[v].push_back(u);  
        }  
        memset(vd,0,sizeof(vd));  
        asize = 1<<29;  
        DFS(1);  
        cout<<ans<<" "<<asize<<endl;  
    }  
    return 0;  
}  
