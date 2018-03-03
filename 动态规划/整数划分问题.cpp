//整数划分问题 


// 将N划分成多个可以相同的整数
// dp(i,j)表示整数i的划分中，每个数不大于整数j的划分数
int N,dp[MAXN][MAXN];
clr(dp,0);
for(int i = 1; i <= N; i++) 
    for(int j = 1; j <= N; j++) 
	{
        if(i < j) dp[i][j] = dp[i][i];
        else if(i > j) dp[i][j] = dp[i - j][j] + dp[i][j - 1];
        else dp[i][j] = dp[i][j - 1] + 1;
    }
int ans=dp[N][N];


// N划分成K个正整数之和的划分数目
// dp(i,j)表示正整数i划分成j个正整数
int N, K;
int dp[MAXN][MAXN];
clr(dp,0); 
dp[0][0] = 1;
for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++) 
	{
        if(i<j) dp[i][j] = 0;
        else if(i>j) dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
        else dp[i][j] = 1;
	}
int ans=dp[N][K];


// N划分成若干个不同正整数之和的划分数目
// dp(i,j)表示正整数i划分为不超过j的不同整数的划分数
clr(dp,0);
dp[0][0] = 1;
for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++) 
	{
        if(i<j) dp[i][j] = dp[i][i];
        else if(i>j) dp[i][j]=dp[i-j][j-1]+dp[i][j-1];
        else dp[i][j] = dp[i][j - 1] + 1;
    }
int ans=dp[N][N];


// N划分成若干个奇正整数之和的划分数目
// f(i,j)表示正整数i划分为j个奇数之和的划分数
// g(i,j)表示正整数i划分为j个偶数之和的划分数
int g[MAXN][MAXN];
int f[MAXN][MAXN];
clr(g,0);clr(f,0);
f[0][0] = g[0][0] = 1;
for(int i = 1; i <= N; i++)
    for(int j = 1; j <= i; j++) 
	{
        g[i][j] = f[i - j][j];
        f[i][j] = f[i - 1][j - 1] + g[i - j][j];
    }
