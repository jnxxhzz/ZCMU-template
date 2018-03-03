//最长公共子序列   LCS  
//时间复杂度 ：O(nlogn) 
/*思路： 
	a,B为两个序列，lis记录a中元素在b中的位置，d[i]为长度i的上升子序列最后
一个元素的值，pos[i][j]记录a中值为i的元素在b中出现的第j个位置的序号
	如果lis[i]大于目前最长子序列的最后一个元素，把lia[i]附在改序列后边，构成长
度+1的最长序列，同时更新d[]的值.否则找到d[]中第一个大于lis[i]的位置k，将lis[i]
附在长度为k-1的序列后边，即变为长度为k的序列，因此更新d[k]的值为lis[i]*/

char s1[MAXN],s2[MAXN];//原始字符串 
int a[MAXN], b[MAXN];//原始数组(从1开始) 

int B, lis[MAXN*20],d[MAXN*20];
vector<int> pos[MAXN];
int LCS(int len_a,int len_b)
{
	
	int len_lis = 1;
    for (int i = 0; i <= len_a; i++)
        for (int k = pos[a[i]+5000].size() - 1; k >= 0; k--)
            lis[len_lis++] = pos[a[i]+5000][k];

    d[1] = lis[1];
    int max_len_lcs = 1;

    for (int i = 2; i <= len_lis; i++)
	{
        if (lis[i] > d[max_len_lcs])
            d[++max_len_lcs] = lis[i];
        else {
            int pos_greater_than_lis_i = lower_bound(d, d + max_len_lcs, lis[i]) - d;
            d[pos_greater_than_lis_i] = lis[i];
        }
    }
    return max_len_lcs;
}
int LCS_num(int len_a,int len_b)  //处理数组 
{
	for(int i=0;i<MAXN;i++) pos[i].clear();
    for (int i = 1; i <= len_b; i++)
	{
        B=b[i];
        pos[B+5000].push_back(i);
    }
	return LCS(len_a,len_b);
}
int LCS_char(int len_a,int len_b)  //处理字符串 
{
	for(int i=0;i<MAXN;i++) pos[i].clear();
	for(int i=1;i<=len_a;i++) a[i]=s1[i-1];
	for(int i=1;i<=len_b;i++) 
	{
		B=s2[i-1];
		pos[B+5000].push_back(i);
	}
	return  LCS(len_a,len_b);
}

