//约瑟夫环问题。 
//输入N个人，每次数到第M个退出 求最后剩下的那个的号码。 
int jose0(int n,int m)
{
	if(n==2) return (m%2) ? 2:1;
	int v=(m+jose0(n-1,m))%n;
	if(v==0)v=n;
	return v;
}
int jose(int n,int m)
{
	if(m==1) return n;
	else if(n==1) return 1;
	else if(m>=n) return jose0(n,m);
	int l=(n/m)*m;
	int j=jose(n-(n/m),m);
	if(j<=n-1) return l+j;
	j-=n-1;
	int t=(j/(m-1))*m;
	if(j%(m-1)==0) return t-1;
	return t+(j%(m-1));
}

//约瑟夫问题模拟
//传入n,m，r返回出环的序列
//时间复杂度O(nlogn)
#include<cstring>
const int MAXN = 32768;
void josephus(int n,int m,int r[])
{
	int d[MAXN*2],i,j,nbase,p,t;
	for(nbase = 1;nbase <n; nbase<<= 1);
	memset(d,0,sizeof(d));
	for(i=0;i<n;i++) d[nbase + i]=1;
	for(i=nbase - 1;i;i--)
		d[i]=d[i<<1]+d[i<<1|1];
	for(j=i=0;i<n;i++)
	{
		for(j=t=(j-1+m)%(n-i),p=1;p<nbase;)
		{
			d[p]--;
			if(t<d[p<<1]) p=p<<1;
			else{
				t-=d[p<<1];
				p=p<<1|1;
			}
		}
		r[i]=p-nbase;
		d[p]--;
	}
}
