//最小生成树 Kruskal 边集 
//时间复杂度：o(mlogn) 
//传入： 边数m  边集es[] 
//返回： 生成树权值（图可能不连通） 
//备注：自行补充并查集内容 
struct edge{ int x,y,cost }; 
bool cmp(const edge &e1,edge &e2)
{ return e1.cost<e1.cost; }
edge es[MAX_E]; //存所有的边
int n,m;
int Kruskal()
{
	sort(es,es+m,cmp);
	Init_find();  //初始化并查集 
	int res=0;
	for(int i=0;i<m;i++)
	{
		edge e=es[i];
		if(find(e.x)!=find(e.y)) 
		{  //并查集
			merge(e.x,e.y);
			res+=e.cost;
		 } 
	}
	return ans;
 } 
 
 
