//串的排列

//串的全排列函数
#include <algorithm>
int a[MAXN],n;
sort(a,a+n);
do{
	//处理与输出 
}while(next_permutation(a,a+n));
//获取下一个较大字典序 
//当串等于初始串时，退出循环 


//求字符串最大/最小字典序
//传入：初始字符串s
//返回：串s的最大/最小字典序的起始位置
 
char s[MAXN*2+10];
char S[MAXN*2+10];   //  辅助字符串 
int MinRepresstation(const char *s)
{//用最小表示法求字符串S的最小字典序 
 //返回字典序最小的串的首字母位置
    int i = 0, j = 1, k = 0;
    strcpy(S,s);
    strcat(S,s);  //使得S[]为s[]的两倍 
	int len = strlen(s);
    while(i < len && j < len)
    {
        k = 0;
        while(k<len&&S[i+k]==S[j+k]) k++;
        if(k >= len)  break;
        if(S[i + k] > S[j + k])
            i = max(i + k + 1, j + 1);
        else
            j = max(i + 1, j + k + 1);
    }
    return min(i ,j);
}
int MaxRepresstation(const char * s)
{//用最大表示法求字符串S的最大字典序 
 //返回字典序最小的串的首字母位置
    int len = strlen(s);
    int i = 0,j = 1, k = 0;
    while(i<len&&j<len&k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(!t)k++;
        else
        {
            if(t>0) j = j + k + 1;
            else i = i + k + 1;
            if(i==j) j++;
            k = 0;
        }
    }
    return min(i, j);
}
