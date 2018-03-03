//最长递增子序列
//严格递增 
// dp + 二分
//时间复杂度： O（N*logN）
int dp[100005],s[100005];
int LIS()
{
    dp[0]=s[0];
    int len=1;
    for(int i=1;i<n;i++)
    {
        int left=0,right=len-1,mid;
        if(dp[len-1]<s[i]) dp[len++]=s[i];
        else
        {
            right=len-1;
            while(left<=right)
            {
                mid=(left+right)/2;
                if(dp[mid]<s[i]) left=mid+1;
                else  right=mid-1;
            }
            dp[left]=s[i];
        }
    }
    return len;
} 

//用 lower_bound 函数优化 
//dp[i]表示递增数量i的最小值 
int dp[maxn];  
int a[maxn];  
int LIS(int n,int a[])  
{  
    int n,len=0;
    dp[len]=a[0];  
    for(int i=1;i<n;i++)      
    {  
        if(a[i]>dp[len])  
          dp[++len]=a[i];  
        else  
        {  
            int pos=lower_bound(dp,dp+len-1,a[i])-dp;      
            //在dp[]找第一个>=a[i]下标   
            dp[pos]=a[i];          
        }   
    }    
    return len=1; 
}  
