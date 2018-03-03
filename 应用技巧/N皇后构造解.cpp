//N皇后构造解
//在N*N的棋盘上放N个皇后 使他们不能两两攻击
// 输出的ai是 第i行 第ai列  皇后放置的位置 
#include<cstdio>  
int n;  
int main()
{  
    scanf("%d",&n);  
    if(n%6!=2&&n%6!=3)
	{  
	    for(int i=2;i<=n;i+=2)printf("%d\n",i);  
	    for(int i=1;i<=n;i+=2)printf("%d\n",i);  
    }  
    else
	{  
        int k=n/2;  
        if(k&1)
		{  
            for(int i=k;i<=n-1;i+=2)printf("%d\n",i);  
            for(int i=1;i<=k-2;i+=2)printf("%d\n",i);  
            for(int i=k+3;i<=n;i+=2)printf("%d\n",i);  
            for(int i=2;i<=k+1;i+=2)printf("%d\n",i);  
        }  
        else
		{  
            for(int i=k;i<=n;i+=2)printf("%d\n",i);  
            for(int i=2;i<=k-2;i+=2)printf("%d\n",i);  
            for(int i=k+3;i<=n-1;i+=2)printf("%d\n",i);  
            for(int i=1;i<=k+1;i+=2)printf("%d\n",i);  
        }  
        if(n&1)printf("%d\n",n);  
    }  
    return 0;  
}  


