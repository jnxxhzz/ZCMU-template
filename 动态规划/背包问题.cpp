//背包问题 

//01背包 
//每种物品仅有一件，可以选择放或不放 
int n,m,wei[MAXN],val[MAXN];
int dp[MAXN];
for(int i=0;i<n;i++)
	for(int j=m;j>=wei[i];j--)
		dp[j]=max(dp[j],dp[j-wei[i]]+val[i]); 
int ans=dp[m]; 
		
		
//完全背包 
//有N物品和容量为W的背包,使价值最大 
//每种物品可以无限制的重复使用，可以选择放或不放
int n,W;
int dp[MAXN],val[MAXN],wei[MAXN];
clr(dp,0); 
for(int i =0 ; i < n ; i++)  
    for(int j = wei[i] ; j <= W ; j++)   
        dp[j] = max(dp[j],dp[j-wei[i]]+val[i]);
int ans=dp[W];
//若要求正好装满花费最小，则
clr(dp,INF);
for(int i =0 ; i < n ; i++)  
    for(int j = wei[i] ; j <= W ; j++)   
        dp[j] = min(dp[j],dp[j-wei[i]]+val[i]);
int ans=dp[W];


//多重背包(MultiplePack): 有N种物品和一个容量为V的背包。  
//第i种物品最多有n[i]件可用，每件费用是c[i]，价值是w[i]。  
//求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，  
//且价值总和最大。  
int n,V;
int dp[MAXN],num[MAXN],val[MAXN],wei[MAXN];
for(int i = 0 ; i < n ; i++)  
    for(int k = 0 ; k < num[i] ; k++)  
        for(int j = V ; j >= val[i]; j--)  
            dp[j] = max(dp[j],dp[j-val[i]]+wei[i]);  
                        
                        
                        
                        
                        

