//最大子矩阵和
//时间复杂度：O(n^3)
//返回： 最大子矩阵和res 
int a[MAXN][MAXN],dp[MAXN];
int sumsub(int n,int G[][]) 
{
	clr(dp,0);
	clr(a,0);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			a[i][j]=G[i-1][j-1];
			a[i][j]+=a[i-1][j];
		}
	int max_sum=0;
	for(int i=1; i<=n; i++)
		for(int j=0; j<i; j++)
			for(int k=1; k<=n; k++)
			{
				dp[k]=a[i][k]-a[j][k];
				dp[k]+=dp[k-1];
				if(dp[k]<0)
					dp[k]=0;
				if(dp[k]>max_sum)
					max_sum=dp[k];
			}
	return max_sum;
}



