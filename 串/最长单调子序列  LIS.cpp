//最长单调子序列  LIS  简便写法 
//时间复杂度：NlogN
//包含于 <algorithm> 
//改变参数 cmp 可获得四种效果 
int a[MAXN]; 
template<class Cmp>  
int LIS (int n,Cmp cmp)  
{  
    static int m=0, end[MAXN];  //static 不可省略 
    for (int i=0;i<n;i++)  
    {  
        int pos = lower_bound(end, end+m, a[i], cmp)-end;  
        end[pos] = a[i], m += pos==m;  
    }  
    return m;  
}  

//使用方法： 
LIS(n,less<int>() );           严格上升  
LIS(n,less_equal<int>() );     非严格上升  
LIS(n,greater<int>() );        严格下降  
LIS(n,greater_equal<int>() );  非严格下降  
 
 
 
