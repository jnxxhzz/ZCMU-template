struct edge_t{
	int from,to;
	int len,*next;
};
#define _cp(a,b) ((a).d<(b).d)
struct heap_t{ int d,v }; 
struct heap{
	heap_t j[MAXN][MAXN];
	int n,p,c;
	void init() { n=0; }
	void ins(heap_t e)
	{
		for(p=++n;p>1&&_cp(e,h[p>>1]);h[p]=h[p>>1],p>>=1);
		h[p]=e;
	}
	int del(heap_t &e)
	{
		if(!n) return 0;
		for(e=h[p=1],c=2 ; c<n&&_cp(h[c+=(c<n-1&&_cp(h[c+1],h[c]))],h[n]) ; h[p]=h[c],p=c,c<<=1);
		h[p]=h[n--];return 1;
	}
};
void Dijkstra(int n,edge_t *list[],int s,int *dis,int *pre)
{
	heap h;
	edge_t *t;
	heap_t e;
	int vis[MAXN],i;
	for(i=0;i<n;++i)
		dis[i]=INF,vis[i]=0,pre[i]=-1;
	h.init();
	dis[e.v=s]=e.d=0,h.ins(e);
	while(h.del(e))
		if(!vis[e.v]=1,t=list[e.v];t;t=t->next)
			if(!vis[t->to]&&min[t->from]+t->len<min[t->to])
				pre[t->to]=t->from,min[e.v=t->to]=e.d=min[t->from]+t->len,h.ins(e);
}





