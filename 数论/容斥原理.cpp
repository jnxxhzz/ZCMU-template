/*	容斥原理 
	多个集合相加去除重复的公共部分 
*/

/* 
	例题一：在 [a , b] 范围内 ，求和 n 互质的数的个数 
	*队列写法 * 
	思路：1、将 n 分解质因子
		  2、用容斥原理去除重复计数的数 
*/
#include <stdio.h>
#include <stdlib.h>
long long  a[1000],num;//a存质数
void init(long long n)//求一个数的质因子（规定记住）
{
    long long i;
    num=0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a[num++]=i;
            while(n%i==0)
                n=n/i;
        }
    }
    if(n>1)
        a[num++]=n;
}
long long haha(long long m)//用队列数组实现容斥原理模板
{
    long long que[10000],i,j,k,t=0,sum=0;
    que[t++]=-1;
    //循环相乘，容斥，减去多算的，再相加，用-1加减，k=t，判断与谁乘
    for(i=0;i<num;i++)
    {
        k=t;
        for(j=0;j<k;j++)
           que[t++]=que[j]*a[i]*(-1);
    }
    for(i=1;i<t;i++) sum=sum+m/que[i];
    return sum;
}
int main()
{
    long long x,y,n,sum;
    while(scanf("%lld%lld%lld",&x,&y,&n)!=EOF)
    {
       init(n);
       sum=y-haha(y)-(x-1-haha(x-1));
	   //所有点的个数y减去1~y不与n互质的个数，         
	   //再加上1~x里不与n互质的个数，再减去1~x所有点个数
       printf("%lld\n",sum);
    }
    return 0;
}


/*	例题二：DFS写法
	问：给出m个数，问在 1 ~ n-1 里面有多少个数
		能被这m个数的任意一个数整除。 
*/
#include<stdio.h>  
#include<string.h>  
int a[20], N, M, la ;  
int hash[20];  
__int64 gcd(__int64 a, __int64 b)  
{  
    __int64 c ;  
    while(b)  
     {  
         c = a % b ;  
         a = b ;  
         b = c ;  
     }  
    return a ;  
}  

void dfs(int now, int count, __int64 lcm, __int64 &sum)  
{  //    当前点 已经加入容斥的个数，记录容斥的过程值   结果  
    lcm = a[now] / gcd(lcm, a[now]) * lcm ;  
    if(count & 1)  
         sum += (N - 1) / lcm ;  
    else sum -= (N - 1) / lcm ;  
    for(int i = now + 1; i < M; i++)  
         dfs(i, count + 1, lcm, sum);  
}  
int main()  
{  
    int b,i ;  
    while(scanf("%d%d", &N, &M) != EOF)  
     {  
        for(i = 0, la = 0; i < M; i++)  
        {  
            scanf("%d", &b);  
            if(b) a[la++] = b ;  
        }  
        M = la ;  
        __int64 sum = 0 ;  
        //memset(hash,0,sizeof(hash));  
        for(i = 0; i < M; i++) //枚举起点  
             dfs(i, 1, a[i], sum);  
         printf("%I64d\n", sum);  
     }  
    return 0 ;  
}   
