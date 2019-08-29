/*	二维树状数组 	单点更新 区间查询 
	时间复杂度: 单点修改 logN*logM  区间查询 logN*logM 
 	1、	数组下标一定要从1开始!!!!!!!!! 
 	2、	注意Sum和 c 必要的时候用long long 
	3、 做区间更新时复杂度：n*m*logn*logm 
*/
const int maxn = 3000;  
int Bit[maxn][maxn]; 
int Row, Col;  
inline int Lowbit(const int &x)
{ return x&(-x); } // x > 0 
void Init()
{
	//Row = ?  Col = ?  //区间范围
	memset(Bit,0,sizeof(Bit)); 
 } 
int Sum(int i,int j)
{   
    int tempj, sum = 0;  
    while( i > 0 )
	{  
        tempj= j;  
        while( tempj > 0 )
		{  
            sum += Bit[i][tempj];  
            tempj -= Lowbit(tempj);  
        }  
        i -= Lowbit(i);  
    }  
    return sum;  
}  
void Update(int i, int j, int num)
{   //单点更新 
    int tempj;  
    while( i <= Row )
	{  
        tempj = j;  
        while( tempj <= Col )
		{  
        	Bit[i][tempj] += num;  
        	tempj += Lowbit(tempj);  
        }  
        i += Lowbit(i);  
    }  
}  
//求区间和 
int Query(int x1,int y1,int x2,int y2)
{ return Sum(x2,y2)-Sum(x1-1,y2)-Sum(x2,y1-1)+Sum(x1-1,y1-1);  } 
