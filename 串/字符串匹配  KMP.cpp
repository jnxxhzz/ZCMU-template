//字符串匹配  KMP   
//时间复杂度：O(n+m) 
/*定理 
	字符串最小循环节长度 ： 
	cir = len - next[len] ;  */ 

int next[MAXN];
void getnext(const char *s)
{
    int i = 0, j = -1,len=strlen(s);
    next[0] = -1;
    while(i != len)
    {
        if(j == -1 || s[i] == s[j])
            next[++i] = ++j;
        else  j = next[j];
    }
}
int Find(char *T,char *P)
{
    int len1=strlen(T),len2=strlen(P);
    getnext(P); //获得next数组 
    int j = 0, ans=0 ;
	int ok=1,First=0;
    for(int i = 0; i < len1; i++)
    {
        while(j && P[j] != T[i])
            j = next[j];
        if(P[j] == T[i]) j++;
        if(j == len2) 
		{
			if(ok) { First=i;ok=0; }
			ans++;
		}
    }
    return ans;     //搜索目标串的数量 
    return First;   //第一个目标串的位置 
}
