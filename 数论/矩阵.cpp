//矩阵

//定义
struct Matrix{
	int n,m;  //行 列 
	int date[MAXN][MAXN]; 
	Matrix(int n,int m):n(n),m(m){}
}; 
//矩阵初始化
//即 主对角线皆为 1
Matrix init(int x,int y)
{
	Matrix res(x,y);
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			if(i==j) res.date[i][j]=1;
			else res.date[i][j]=0;
	return res;
} 

//矩阵加法
//要求必须符合 a.n==b.n  a.m==b.m 
Matrix plu(Matrix a,Matrix b)
{
	Matrix c(a.n,a.m);
	for(int i=0;i<a.n;i++)
		for(int j=0;j<a.m;j++)
			c.date[i][j]=a.date[i][j]+b.date[i][j];
	return c;
}

//矩阵乘法  
//要求必须符合矩阵乘法规则: a.m==b.n
//复杂度：N^3 
Matrix mul(Matrix a,Matrix b)
{
	Matrix c(a.n,b.m);
	for(int i=0;i<c.n;i++)
		for(int j=0;j<c.m;j++)
		{
			c.date[i][j]=0;
			for(int k=0;k<a.m;k++)
				c.date[i][j]+=a.date[i][k]*b.date[k][j];
		}
	return c;
}

//矩阵快速幂 
//求矩阵 a 的 k次方 (矩阵 a 必须为方阵 n==m )
Matrix fastmod(Matrix a,int k)
{
	Matrix res=init(a.n,a.m);
	while(k)
	{
		if(k&1) res=mul(res,a); //乘法 
		k>>=1;
		a=mul(a,a); //乘法 
	}
	return res;
}

//求 矩阵 a 的 1~K 次之和
//即求 a^1+a^2+a^3+...+a^k
Matrix dfs(Matrix a,int k)
{
	if(k==1) return a;
	Matrix res=init(a.n,a.m);
	res=plu(res,fastmod(a,k>>1));
	res=mul(res,dfs(a,k>>1));
	if(k&1) res=plu(res,fastmod(a,k));
	return res;
}










 
