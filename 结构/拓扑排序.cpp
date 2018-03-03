//拓扑排序
int in[MAXN],a[MAXN];
int n,m;
bool map[MAXN][MAXN];
int topu()
{
    queue<int> q;
    int cnt = 1,u;
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n ; i++)
        if(in[i] == 0)
            q.push(i);
		//将有依赖顶点的节点入队
    while(!q.empty())  //
    {
        u = q.front();q.pop();
        a[cnt++] = u;
		//将没有依赖顶点的节点加入到排序结果中
        for(int i = 1; i <= n ; i++)
        {
            if(map[u][i])
            {
                in[i] --;//删去以u为顶点的边
                if(in[i] == 0) q.push(i);
            }
        }
        if(cnt == n)//如果排序完成输出结果
    }
}



