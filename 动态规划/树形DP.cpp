/*	树形DP 
	题意：	给一颗树，定义树上路径u到v的价值为路径上不同颜色的节点的数量，
		  	问所有路径的总价值为多少
	题解：	根据题意，所需要求解的价值可以转换为，假设每条路径上包含所有
			的颜色，也就是n*（n-1）/2*（总颜色个数），然后减去每个颜色
			对不存在这个颜色的的所有路径的贡献。
			<=> 等价于每种颜色有多少条路径经过 <=> 所有情况 - 每种颜色有
			多少条路径没有经过这种颜色
*/
struct node {
	int to, next;
}edge[maxn<<1];
int head[maxn], tot, sum[maxn], u, v;
void add_edge(int u, int v) 
{
	edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
	edge[tot].to = u; edge[tot].next = head[v]; head[v] = tot++;
}
int col[maxn], size[maxn];
//size[i] 以该节点为根的树的节点数
//sum[i]以颜色i为根的子树总大小
ll ans, n, num;
bool vis[maxn];
void init() 
{
	clr(sum, 0); clr(size, 0); clr(head, -1); clr(vis, false);
	tot = 0; num = 0; ans = 0;
}
void dfs(int u, int fa) 
{
	size[u] = 1;
	ll pre = sum[col[u]], c = 0;
	for (int i = head[u]; i != -1; i = edge[i].next) 
	{
		int v = edge[i].to;
		if(v != fa) {
			dfs(v, u);
			size[u] += size[v];
			ll tmp = sum[col[u]] - pre;;//子树v中以col[u]为根的子树大小
			ll cnt = size[v] - tmp;//子树v中, 除了u颜色之外的节点个数
			pre = sum[col[u]];//记录上一次的sum
			ans -= cnt * (cnt - 1) / 2;//v子树中各节点相互到达无需经过col[u]
			c += tmp;
		}
	}
	sum[col[u]] += size[u] - c;//加上以u为根的子树大小
}
int main() 
{
	int cas = 1;
	while(~scanf("%d", &n)) 
	{
		init();
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d", &col[i]);
			if(!vis[col[i]]) 
				num++,vis[col[i]] = true;
		}
		for (int i = 1; i < n; i++) 
		{
			scanf("%d %d", &u, &v);
			add_edge(u, v);
		}
		ans = num * (n - 1) * n / 2;
		dfs(1, -1);
		for (int i = 1; i <= n; i++) 
		{
			if(sum[i]) 
			{
				ll cnt = n - sum[i];
				ans -= cnt * (cnt - 1) / 2;
			}
		}
		printf("Case #%d: %lld\n", cas++, ans);
	}
	return 0;
}
