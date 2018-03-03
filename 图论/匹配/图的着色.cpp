//图的着色 
//时间复杂度：O(n^2) 
//相邻的点不能涂同一颜色，最少用几种颜色 
//初始化： 图G 顶点数n 
//节点p[i]:num=i;color=0;de=总度数 
int G[MAXN][MAXN];
struct Node{
   int num,de,color; //编号 度 节点颜色
}p[MAXN];
bool cmp(Node p1,Node p2) //按度从高到低排序
{ return p1.de > p2.de; }
int PaintColor(int n)
{
	sort(p,p+n,cmp);
	int k=0;
	while(1)
	{
		k++;
		int i;
		for (i = 0; i < n; i++)
			if (!p[i].color) 
			{ p[i].color=k; break; }
		if (i == n) break;
		for(int j=0; j<n; j++)
			if(!p[j].color && !G[ p[i].num ][ p[j].num ] && i!=j)
				p[j].color = k;
	}
	return k-1; 
}



