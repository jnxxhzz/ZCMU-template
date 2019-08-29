/*| 	二维树状数组 	区间更新 单点查询 
		时间复杂度: 单点修改 logN*logM  区间查询 logN*logM 
 	1、	初始化：Bit[][]置为0; n,m 要赋初值 
 		数组下标一定要从1开始!!!!!!!!! 
*/
typedef long long LL;
const int maxn = 2048;
LL Bit[maxn][maxn];
int n,m;
int lowbit(int x)
{ return x&(-x); }
void add(int x,int y,LL v)
{
	for(int i=x;i<n+10;i+=lowbit(i))
		for(int j=y;j<m+10;j+=lowbit(j))
			Bit[i][j]+=v;
}
LL sum(int x,int y)
{	//单点查询 
	LL res=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			res+=Bit[i][j];
	return res;
}
void update(int r1,int c1,int r2,int c2,LL v)
{	//	二维区间更新 
	add(r1,c1,v);
	add(r1,c2+1,-v);
	add(r2+1,c1,-v);
	add(r2+1,c2+1,v);
}

