//最长上升公共子序列
//时间复杂度： O(n^2)
/* 用一维存储 f[i]表示 b 数组以 j 结尾，与 a[]数组构成
的最长公共上升子序列。 对数组 d 的任意 j 位， 都枚举 
a[1 ~n1]。当a[i] == b[j] 时 ， 在1 ~ j - 1中 找出 b[k] 
小于 a[ i ] 并且 d[k] 的值最大。 当 a[ i ] > b [j ] 时，
 在0到j-1中，对于小于a[i]的，保存f值的最优解 （保存小于
 a [ i ] 并且 d[k]值最大的值所在的位置）。*/ 
 
int a[MAXN], b[MAXN], d[MAXN];
int LCIS(int n1,int n2)
{
	memset(d, 0, sizeof(d));
    for(int i = 0; i < n1; i++)
    {
        int k = 0;
        for(int j = 0; j < n2; j++)
        {
            if(a[i] == b[j])
                d[j] = max(d[j], d[k] + 1);
            else if(a[i] > b[j])
                if(d[k] < d[j]) k = j;
        }
    }
    int mx = 0;
    for(int i = 0; i < n2; i++)
        mx = max(mx, d[i]);
    return mx;
}

