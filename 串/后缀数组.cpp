/*   后缀数组 

4个比较基础的应用

Q1：一个串中两个串的最大公共前缀是多少？ 
A1：这不就是Height吗？用rmq预处理，再O(1)查询。 
 
Q2：一个串中可重叠的重复最长子串是多长？ 
A2：就是求任意两个后缀的最长公共前缀，而任意两个后缀的最长公共前缀都是Height 
	数组里某一段的最小值，那最长的就是Height中的最大值。 
 
Q3：一个串种不可重叠的重复最长子串是多长？ 
A3：先二分答案，转化成判别式的问题比较好处理。假设当前需要判别长度为k是否符
	合要求，只需把排序后的后缀分成若干组，其中每组的后缀之间的Height 值都不
	小于k，再判断其中有没有不重复的后缀，具体就是看最大的SA值和最小的SA值相
	差超不超过k，有一组超过的话k就是合法答案。 
 
A4：一个字符串不相等的子串的个数是多少？ 
Q4：每个子串一定是某个后缀的前缀，那么原问题等价于求所有后缀之间的不相同的
	前缀的个数。而且可以发现每一个后缀Suffix[SA[i]]的贡献是Len - SA[i] + 1,
	但是有子串算重复，重复的就是Heigh[i]个与前面相同的前缀，那么减去就可以
	了。最后，一个后缀Suffix[SA[i]]的贡献就是Len - SA[k] + 1 - Height[k]。 
*/ 

const int MAXN = 100005;

char ch[MAXN], All[MAXN];
int SA[MAXN], rank[MAXN], Height[MAXN];
int tax[MAXN], tp[MAXN], a[MAXN], n, m; 
char str[MAXN];
//rank[i] 第i个后缀的排名; 
//SA[i] 排名为i的后缀位置; 
//Height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP
//tax[i] 计数排序辅助数组; 
//tp[i] rank的辅助数组(计数排序中的第二关键字),与SA意义一样。
//a为原串
void RSort() 
{	//rank第一关键字,tp第二关键字。
    for (int i = 0; i <= m; i ++) tax[i] = 0;
    for (int i = 1; i <= n; i ++) tax[rank[tp[i]]] ++;
    for (int i = 1; i <= m; i ++) tax[i] += tax[i-1];
    for (int i = n; i >= 1; i --) SA[tax[rank[tp[i]]] --] = tp[i]; 
	//确保满足第一关键字的同时，再满足第二关键字的要求
} //计数排序,把新的二元组排序。

int cmp(int *f, int x, int y, int w) 
{ return f[x] == f[y] && f[x + w] == f[y + w]; } 
//通过二元组两个下标的比较，确定两个子串是否相同

void Suffix() //SA
{
    for (int i = 1; i <= n; i ++) rank[i] = a[i], tp[i] = i;
    m = 127 ,RSort(); //一开始是以单个字符为单位，所以(m = 127)

    for (int w = 1, p = 1, i; p < n; w += w, m = p) 
	{ //把子串长度翻倍,更新rank
        //w 当前一个子串的长度; m 当前离散后的排名种类数
        //当前的tp(第二关键字)可直接由上一次的SA的得到
        for (p = 0, i = n - w + 1; i <= n; i ++) tp[++ p] = i; 
		//长度越界,第二关键字为0
        for (i = 1; i <= n; i ++) if (SA[i] > w) tp[++ p] = SA[i] - w;
        //更新SA值,并用tp暂时存下上一轮的rank(用于cmp比较)
        RSort(), swap(rank, tp), rank[SA[1]] = p = 1;
        //用已经完成的SA来更新与它互逆的rank,并离散rank
        for (i = 2; i <= n; i ++) 
			rank[SA[i]] = cmp(tp, SA[i], SA[i - 1], w) ? p : ++ p;
    }
    //离散：把相等的字符串的rank设为相同。
    //LCP
    int j, k = 0;
    for(int i = 1; i <= n; Height[rank[i ++]] = k) 
        for( k=k?k-1:k,j=SA[rank[i]-1];a[i+k]==a[j+k];++k);
    //这个知道原理后就比较好理解程序
}
void Init() 
{
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i ++) a[i + 1] = str[i];
}
int main() 
{
    Init(); //输入原串 
    Suffix(); //处理后缀数组 ,获得SA、Height、Rank 
    //for(int i=0;i<=n;i++) printf("%d ",SA[i]); printf("\n"); 
    //for(int i=0;i<=n;i++) printf("%d ",rank[i]); printf("\n"); 
    //for(int i=0;i<=n;i++) printf("%d ",Height[i]); printf("\n"); 
}
