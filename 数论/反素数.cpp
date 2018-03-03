/*反素数的定义：对于任何正整数n，其约数个数记为f(n)，例如f(6)=4，如果某个正整数n满足：对任意的正整
            数，都有，那么称为反素数。
 
从反素数的定义中可以看出两个性质：
（1）一个反素数的所有质因子必然是从2开始的连续若干个质数，因为反素数是保证约数个数为的这个数尽量小
（2）同样的道理，如果，那么必有
在ACM竞赛中，最常见的问题如下：
（1）给定一个数，求一个最小的正整数，使得的约数个数为
（2）求出中约数个数最多的这个数
从上面的性质中可以看出，我们要求最小的，它的约数个数为，那么可以利用搜索来解。
以前我们求一个数的所有因子也是用搜索，比如，以每一个为树的一层建立搜索树，深度为
以为例进行说明，建树如下：
可以看出从根节点到每一个叶子结点这条路径上的所有数字乘起来都是12的约数，所以12有6个约数。
搜索的思路就明显了，从根节点开始进行深搜，到叶子结点，代码如下：*/

void dfs(int dept,LL ans = 1)  
{  
    if(dept == cnt)  
    {  
        fac[ct++] = ans;  
        return;  
    }  
    for(int i=0;i<=num[dept];i++)  
    {  
        dfs(dept+1,ans);  
        ans *= pri[dept];  
    }  
}  

/*回到我们的问题，同样用搜索来求最小的。
题目：http://codeforces.com/problemset/problem/27/E
题意：	给一个数N，求一个最小的正整数，使得它的因子个数为N。
		N<=1000
分析：	与求因子的方法类似，先建立搜索树，以每一个为一层建立树型结构，
        进行搜索，取最小的。 */
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
typedef unsigned long long ULL;  
const ULL INF = ~0ULL;  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
int n;  
ULL ans;  
void dfs(int dept,ULL tmp,int num)  
{  
    if(num > n) return;  
    if(num == n && ans > tmp) ans = tmp;  
    for(int i=1;i<=63;i++)  
    {  
        if(ans / p[dept] < tmp) break;  
        dfs(dept+1,tmp *= p[dept],num*(i+1));  
    }  
}  
int main()  
{  
    while(cin>>n)  
    {  
        ans = INF;  
        dfs(0,1,1);  
        cout<<ans<<endl;  
    }  
    return 0;  
}  

/*题目：http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1562
题意：找出小于n且因子数最多的数。N<2^63
思路：一个数 A 可以分解成 p1^k1 * p2^k2 * …… * pn^kn 其中p为素数。
    这样分解之后，A的因子个数S = （k1+1） *（ k2+1） * …… *（ kn+1）
    然后用dfs枚举 + 剪枝可以得到s的值。可以在枚举所有小于n的A的s值，最后得到最大值。
代码：*/
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
typedef unsigned long long ULL;  
const ULL INF = ~0ULL;  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
ULL ans,n;  
int best;  
void dfs(int dept,ULL tmp,int num)  
{  
    //到叶子结点，返回  
    if(dept >= 16) return;  
    //num记录的因子个数，如果遇到更小的，就更新  
    if(num > best)  
    {  
        best = num;  
        ans = tmp;  
    }  
    //当因子个数相同时，取值最小的  
    if(num == best && ans > tmp) ans = tmp;  
    for(int i=1;i<=63;i++)  
    {  
        if(n / p[dept] < tmp) break;  
        dfs(dept+1,tmp *= p[dept],num*(i+1));  
    }  
}  
int main()  
{  
    while(cin>>n)  
    {  
        ans = INF;  
        best = 0;  
        dfs(0,1,1);  
        cout<<ans<<endl;  
    }  
    return 0;  
}  

/*题目：http://acm.timus.ru/problem.aspx?space=1&num=1748
 
分析：这道题主要注意数据处理。对于上面的两题，数据范围小，所以可以不用剪枝，本题就需要了。*/
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
typedef unsigned long long ULL;  
const ULL INF = ~0ULL;  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
ULL ans,n;  
int best;  
void dfs(int dept,int limit,ULL tmp,int num)  
{  
    if(tmp > n) return;  
    if(num > best)  
    {  
        best = num;  
        ans = tmp;  
    }  
    if(num == best && ans > tmp) ans = tmp;  
    for(int i=1;i<=limit;i++)  
    {  
        double cur = (double)tmp;  
        if(n < cur*p[dept]) break;  
        dfs(dept+1,i,tmp *= p[dept],num*(i+1));  
    }  
}  
int main()  
{  
    int T;  
    cin>>T;  
    while(T--)  
    {  
        cin>>n;  
        ans = INF;  
        best = 0;  
        dfs(0,60,1,1);  
        cout<<ans<<" "<<best<<endl;  
    }  
    return 0;  
}  
/*
题目：	http://acm.hdu.edu.cn/showproblem.php?pid=4542

题意：	给出一个数K和两个操作
    	如果操作是0，就求出一个最小的正整数X，满足X的约数个数为K。
    	如果操作是1，就求出一个最小的X，满足X的约数个数为X-K。
分析：	对于操作0，就是求反素数，直接搜索搞定。对于操作1，代表1至X
	中不是X的约数个数为K。
 
代码：*/
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
const int N = 50005;  
typedef long long LL;  
const LL INF = (((LL)1)<<62)+1;  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
LL ans;  
int n;  
int d[N];  
void Init()  
{  
    for(int i=1;i<N;i++) d[i] = i;  
    for(int i=1;i<N;i++)  
    {  
        for(int j=i;j<N;j+=i) d[j]--;  
        if(!d[d[i]]) d[d[i]] = i;  
        d[i] = 0;  
    }  
}  
void dfs(int dept,int limit,LL tmp,int num)  
{  
    if(num > n) return;  
    if(num == n && ans > tmp) ans = tmp;  
    for(int i=1;i<=limit;i++)  
    {  
        if(ans / p[dept] < tmp || num*(i+1) > n) break;  
        tmp *= p[dept];  
        if(n % (num*(i+1)) == 0)  
            dfs(dept+1,i,tmp,num*(i+1));  
    }  
}  
int main()  
{  
    Init();  
    int T,tt=1;  
    scanf("%d",&T);  
    while(T--)  
    {  
        int type;  
        scanf("%d%d",&type,&n);  
        if(type) ans = d[n];  
        else  
        {  
            ans = INF;  
            dfs(0,62,1,1);  
        }  
        printf("Case %d: ",tt++);  
        if(ans == 0) puts("Illegal");  
        else if(ans >= INF) puts("INF");  
        else printf("%I64d\n",ans);  
    }  
    return 0;  
}  

