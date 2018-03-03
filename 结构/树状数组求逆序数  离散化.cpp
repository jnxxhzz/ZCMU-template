//树状数组求逆序数  离散化
//时间复杂度：N*logN 
struct Node{
	int val;
	int pos;
};
Node node[N];
int c[N], reflect[N], n;
bool cmp(const Node& a, const Node& b)
{ return a.val < b.val; }

int lowbit(int x)
{ return x & (-x); }
void update(int x)
{
	while (x <= n)
	{
		c[x] += 1;
		x += lowbit(x);
	}
}
int getsum(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
int main()
{
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 1; i <= n; ++i) 
		{
			scanf("%d", &node[i].val);
			node[i].pos = i;
		}
		sort(node + 1, node + n + 1, cmp);
		for (int i=1;i<=n;++i) 
			reflect[node[i].pos]=i;
		for (int i=1;i<=n;++i) c[i]=0; 
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			update(reflect[i]);
			ans += i - getsum(reflect[i]);
		}
		printf("%lld\n", ans);
	} 
	return 0;
}



