//最长回文字子串  Manacher算法 
//时间复杂度：O(N)
//使用：传入目标串，返回最长回文字串的长度 
int p[MAXN*2+10];  //纪录回文数组
char h[MAXN*2+10]; //添加间隔符后的字符串 
int Manacher(const char * s)  //复杂度为 N 
{  
    int mx=0,id=0;
	int l=strlen(s),len=0;
    clr(p,0);
    h[len++]='&';
    for(int i=0;i<l;i++)
    {
    	h[len++]='#';
    	h[len++]=s[i];
	}
	h[len++]='#';
	h[len]='@';  
	//注意结尾字符不能与首字符相同 
    for(int i=1;i<=len;i++)  
    {  
        if(mx>i) p[i]=min(mx-i,p[2*id-i]);  
        else p[i]=1;  
        while(h[i+p[i]]==h[i-p[i]])  
            p[i]++;  //回文条件， 可附加其他条件 
        if(p[i]+i>mx)  
        {  
            mx=p[i]+i;  
            id=i;  
        }  
    }  
    int ans=0;  
    for(int i=1;i<=len;i++)  
        ans=max(ans,p[i]-1);  
    return ans;  
}
