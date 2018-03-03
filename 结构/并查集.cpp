//并查集 
//时间复杂度 :O(logN) 
int root[MAXN];
int Init()
{
	for(int i=0;i<n;i++) 
		root[i]=i;
}
int find(x) 
{
	if(root[x]!=x)
		root[x]=find(root[x]);
	return root[x];
}
int merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) root[fx]=fy;
}




