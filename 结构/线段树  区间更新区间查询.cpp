/*	线段树  区间更新 区间查询 
	改为单点更新：区间左右边界为同一值即可 
*/ 
#define lson l , m , rt << 1  
#define rson m + 1 , r , rt << 1 | 1  
const int maxn = 100100;  
const int INF=0x7fffffff;  
int lazy[maxn<<2];  
int SUM[maxn<<2],MAX[maxn<<2],MIN[maxn<<2];  
void putup(int rt) 
{  
    SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];  
    MAX[rt] =max(MAX[rt<<1],MAX[rt<<1|1]) ;  
    MIN[rt] =min(MIN[rt<<1],MIN[rt<<1|1]);  
}  
void putdown(int rt,int m) 
{  
    if (lazy[rt]) 
	{  
        lazy[rt<<1] += lazy[rt];  
        lazy[rt<<1|1] += lazy[rt];  
        SUM[rt<<1] += lazy[rt] * (m - (m >> 1));  
        SUM[rt<<1|1] += lazy[rt] * (m >> 1);  
        MAX[rt<<1]+=lazy[rt];  
        MAX[rt<<1|1] +=lazy[rt];  
        MIN[rt<<1]+=lazy[rt];  
        MIN[rt<<1|1]+=lazy[rt];  
        lazy[rt] = 0;  
    }  
}  
//以下的 l,r,rt 都带入 1,n,1  
void build(int l,int r,int rt) 
{  //初始化建树  
    lazy[rt] = 0;  
    if (l == r) 
	{  
        //初始化树为0的写法  
        SUM[rt]=MAX[rt]=MIN[rt]=0;  
        /*  //边读入边建树的写法 
        scanf("%d",&SUM[rt]); 
        MAX[rt]=MIN[rt]=SUM[rt]; 
        */  
        return ;  
    }  
    int m = (l + r) >> 1;  
    build(lson);  
    build(rson);  
    putup(rt);  
}  
void update(int L,int R,int v,int l,int r,int rt) 
{  //将区间L~R的值增加v  
    if (L <= l && r <= R) 
	{  
        lazy[rt] += v;  
        SUM[rt] += v * (r - l + 1);  
        MAX[rt]+=v;  
        MIN[rt]+=v;  
        return ;  
    }  
    putdown(rt , r - l + 1);  
    int m = (l + r) >> 1;  
    if (L <= m) update(L , R , v , lson);  
    if (m < R) update(L , R , v , rson);  
    putup(rt);  
}  
int querySUM(int L,int R,int l,int r,int rt) 
{  //求区间L~R的和  
    if (L <= l && r <= R) return SUM[rt];  
    putdown(rt , r - l + 1);  
    int m = (l + r) >> 1;  
    int ret = 0;  
    if (L <= m) ret += querySUM(L , R , lson);  
    if (m < R) ret += querySUM(L , R , rson);  
    return ret;  
}  
int queryMAX(int L,int R,int l,int r,int rt) 
{  //求区间L~R的最大值  
    if (L <= l && r <= R) return MAX[rt];  
    putdown(rt , r - l + 1);  
    int m = (l + r) >> 1;  
    int ret = -INF;  
    if (L <= m) ret =max(ret,queryMAX(L , R , lson)) ;  
    if (m < R) ret =max(ret,queryMAX(L , R , rson)) ;  
    return ret;  
}  
int queryMIN(int L,int R,int l,int r,int rt) 
{  //求区间L~R的最小值  
    if (L <= l && r <= R) return MIN[rt];  
    putdown(rt , r - l + 1);  
    int m = (l + r) >> 1;  
    int ret = INF;  
    if (L <= m) ret = min(ret,queryMIN(L , R , lson));  
    if (m < R) ret = min(ret,queryMIN(L , R , rson));  
    return ret;  
}  
int main() 
{  
    int n , m;  
    int a , b , c;  
    char str[5];  
    scanf("%d%d",&n,&m);  
    build(1 , n , 1);  
    while (m--) 
	{  
        scanf("%s",str);  
        if (str[0] == 'S') 
		{  
            scanf("%d%d",&a,&b);  
            printf("%d\n",querySUM(a , b , 1 , n , 1));  
        } 
		else if(str[0]=='C') 
		{  
            scanf("%d%d%d",&a,&b,&c);  
            update(a , b , c , 1 , n , 1);  
        } 
		else if(str[0]=='A') 
		{  
            scanf("%d%d",&a,&b);  
            printf("%d\n",queryMAX(a , b , 1 , n , 1));  
        } 
		else if(str[0]=='I') 
		{  
            scanf("%d%d",&a,&b);  
            printf("%d\n",queryMIN(a , b , 1 , n , 1));  
        }  
    }  
    return 0;  
}  
