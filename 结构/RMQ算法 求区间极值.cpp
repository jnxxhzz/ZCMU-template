//RMQ算法  求区间最大值/最小值
//思想：区间dp 
//ST(在线查询):每输入一个询问得出一个结果 
//特点：静态 不可更新值 
//预处理时间复杂度：NlogN
//询问时间复杂度：1 
int a[MAXN],n;  //数组a[] 及 长度n 
int Max[MAXN][K],Min[MAXN][K];
//k>=log2(N)+1; 
void RMQ() //预处理序列 
{
	clr(Max,0);clr(Min,0);
	for(int i=1;i<=n;i++)
		Max[i][0]=Min[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			int p=1<<(j-1);
			Max[i][j]=max(Max[i][j-1],Max[i+p][j-1]);
			Min[i][j]=min(Min[i][j-1],Min[i+p][j-1]);
		}
}
LL query(int i,int j) //询问 i~j 区间中的极值 
{
	int k=(int)log2(j-i+1.0);
	int mx=max(Max[i][k],Max[j-(1<<k)+1][k]);
	int mi=min(Min[i][k],Min[j-(1<<k)+1][k]);
	return mx; //区间最大值 
	return mi; //区间最小值 
} 


