//有向图强联通分量   BFS 邻接边集 
//预处理： 点数N 边数M  清空G[]  end=N+10
/*  插入边集如下
	for (i = 0; i < M; i++) 
     {  scanf("%d %d", &s, &e);
        E[i].s = s;  E[i].e = e;
        Insert(s, e);   } */ 
//返回： 强连通分量数scnt  归属数组id[]
//注意： 插入边前 end=N+10 !!! 
int N, M;
typedef struct Node{
    int id;
    int next;
}Node; 
typedef struct Edge{
    int s, e;
}Edge;
Edge E[MAXN * 6];
Node G[MAXN * 7];
int pre[MAXN], id[MAXN];
typedef stack<int> Stack;
Stack S, path;
int end, cnt, scnt;

void Insert(int s, int e)
{
    int p = s;
    while (G[p].next)
    {
        p = G[p].next;
        if (G[p].id == e) return;
    }
    G[p].next = end;
	G[end].id = e;
    end++;
}
void scR(int w)
{
    int v,p,t;
    pre[w] = cnt++;
    S.push(w);
    path.push(w);
    p = G[w].next;
    while (p)
    {
        t = G[p].id;
        p = G[p].next;
        if (pre[t] == -1) scR(t);
        else if (id[t] == -1)
            while (pre[path.top()] > pre[t])
                path.pop();
    }
    if (path.top() == w) path.pop();
    else return;
    do{
        id[v = S.top()] = scnt;
        S.pop();
    }while (v != w);
    scnt++;
}
void Gabow()
{
    clr(pre,-1);
    clr(id,-1);
    cnt = scnt = 0;
    while (!S.empty()) S.pop();
    while (!path.empty()) path.pop();
    for (int i = 0; i < N; i++)  //点序号从0开始 
        if (pre[i] == -1) scR(i);
}


