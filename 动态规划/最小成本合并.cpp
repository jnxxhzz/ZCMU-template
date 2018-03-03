//最小成本合并 
//例： 矩阵链乘法DP 
int n,a[MAXN];
int dp[MAXN][MAXN]; 
int main()  
{  
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i-1],&a[i]);
		clr(dp,0);
		for(int l=2;l<=n;l++)
		{
			for(int i=1;i<=n-l+1;i++)
			{
				int j=i+l-1;
				dp[i][j]=INF;
				for(int k=i+1;k<=j;k++)
					dp[i][j]=min(dp[i][j],
					dp[i][k-1]+dp[k][j]+
					a[k-1]*a[i-1]*a[j]);
			}
		}
		printf("%d\n",dp[1][n]);
	}
    return 0;  
}  




