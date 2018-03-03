//素数 

//素数定理 
//1到X中的素数个数  ：π(x)/(x/ln(x))=1
//即: 
//n=int((double)n-log10((double)n)-log10(log(10.0))+1.0);

//一般法判定素数 
bool is_prim(int x)
{
	if(x==1) return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
} 

//艾氏筛法统计素数
//is_prime[] 记录了 [a,b] 是否为素数 
//注意：该算法会将 1 处理为素数 
bool is_prime[maxn];
bool is_prime_small[maxn];
void segment_seive(LL a,LL b)
{
	for(int i=0;(LL)i*i<=b;i++) 
		is_prime_small[i]=true;
	for(int i=0;i<=b-a;i++) 
		is_prime[i]=true;
	for(int i=2;(LL)i*i<=b;i++)
		if(is_prime_small[i])
		{
			for(int j=2*i;(LL)j*j<=b;j+=i) 
				is_prime_small[j]=false;
			for(LL j= max(2LL,(a+i-1)/i) * i;j<=b;j+=i) 
				is_prime[j-a]=false;
		}
} 

// 艾氏筛法做素数表  简化版
// 将 1 到 MAXN 中的素数保存到数组prime中

int prime[MAXN/10],tot; //当MAXN过小时，10要去掉 
bool num[MAXN]; 
void solve()
{
	tot=0;
	clr(num,0); num[1]=1;
	for(int i=2;i<MAXN;i++)
	{
		if(!num[i]) prime[tot++]=i;
		for(int j=0;j<tot&&i*prime[j]<MAXN;j++)
		{
			num[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}


