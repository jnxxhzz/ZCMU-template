/*  判断 n！ 是否能被 m 整除 
n!中间包含了多少个x(x是任意的一个数，不过一般情况下我们都只讨论x为质数)，
这种问题的答案是：
n/x+n/(x^2)+n/(x^3).....[一直加到x的乘方不超过n]，这个定理的证明也非常的简单，
这里就不再赘述了
 
然后还有一个数论的基本常识就是任意一个数的质因数分解
必须知道这种分解是唯一的
即合数y=sigma[(pi)^ni]
而且pi的范围在2——sqrt(n)之间;
于是乎，我们可以先分解掉m（这个花不了多少时间，如果用质数筛选法加速的话）\
*/
#include<stdio.h>  
#include<string.h>  
struct node {  
    long p;  
    long n;  
    node()  
    {  n=0; }  
};  
long prime[50000];  
bool flag[50000];  
node stc[1000];  
long num1=0,num2;  
void init()  
{  
    unsigned long i,j;  
    memset(flag,0,sizeof(flag));  
    for(i=2;i<50000;i++)  
    {  
        if(!flag[i])  
        {  
            prime[num1++]=i;  
            for(j=i*i;j<50000;j=j+i)  
                flag[j]=true;  
        }  
    }  
}  
void devide(long m)  
{  
    long i;  
    num2=0;  
    for(i=0;prime[i]*prime[i]<=m;i++)  
    {  
        if(m%prime[i]==0)  
        {  
            stc[num2].p=prime[i];  
            stc[num2].n++;  
            m=m/prime[i];  
            while(m%prime[i]==0)  
            {  
                stc[num2].n++;  
                m=m/prime[i];  
            }  
            num2++;  
        }  
        if(m==1)  
            break;  
    }  
    if(m>1)  
    {  
        stc[num2].p=m;  
        stc[num2].n++;  
        num2++;  
    }  
}  
bool judge(long n,long m)  
{  
    long i,sum,temp;  
    for(i=num2-1;i>=0;i--)  
    {  
        sum=0;  
        temp=stc[i].p;  
        while(n>=temp)  
        {  
            sum=sum+n/temp;  
            temp=temp*stc[i].p;  
        }  
        if(sum<stc[i].n)  
            return false;  
    }  
    return true;  
}  
int main()  
{  
    long n,m,i;  
    init();  
    while(scanf("%ld%ld",&n,&m)!=EOF)  
    {  
        for(i=0;i<1000;i++)  
            stc[i].n=0;  
        if(n<=1&&m>1)  
        {  
            printf("%ld does not divide %ld!/n",m,n);  
            continue;  
        }  
        if(m==0)  
        {  
            printf("%ld does not divide %ld!/n",m,n);  
            continue;  
        }  
        if(n>=m)  
        {  
            printf("%ld divides %ld!/n",m,n);  
            continue;  
        }  
        devide(m);  
        if(judge(n,m))  
            printf("%ld divides %ld!/n",m,n);  
        else  
            printf("%ld does not divide %ld!/n",m,n);  
    }  
    return 0;  
}  
