//二部图最大匹配  邻接矩阵 
//时间复杂度：O(sqrt(V)*E) 
//初始化：映射图G  clr(G,0)  
//建图：两部分顶点数 Nx Ny   (x->y : G[x][y]=1 )
//返回：最大匹配res  匹配数组 Mx[] My[] 
//改成普通图最大匹配：总顶点数 Nx = Ny = n+m ; 
int G[MAXN][MAXN],Nx,Ny;  
int dx[MAXN],dy[MAXN],Mx[MAXN],My[MAXN];  
int dis;
bool vis[MAXN];  
bool searchP()
{  
    queue<int>Q;  
    dis=INF;  
    clr(dx,-1); clr(dy,-1);
    for(int i=0;i<Nx;i++)  
        if(Mx[i]==-1) 
            Q.push(i),dx[i]=0;  
    while(!Q.empty())
	{  
        int x=Q.front(); Q.pop();  
        if(dx[x]>dis)  break;  
        for(int y=0;y<Ny;y++)  
            if(G[x][y]&&dy[y]==-1)
			{  
                dy[y]=dx[x]+1;  
                if(My[y]==-1)  dis=dy[y];  
                else  
                {  
                    dx[My[y]]=dy[y]+1;  
                    Q.push(My[y]);  
                }  
            }  
    }  
    return dis!=INF;  
}  
bool DFS(int x)
{  
    for(int y=0;y<Ny;y++)  
       if(!vis[y]&&G[x][y]&&dy[y]==dx[x]+1)  
       {  
           vis[y]=1;  
           if(My[y]!=-1&&dy[y]==dis) continue;  
           if(My[y]==-1||DFS(My[y]))  
           {  
               My[y]=x,Mx[x]=y;  
               return 1;  
           }  
       }  
    return 0;  
}  
int MaxMatch()
{  
    int res=0;  
    clr(Mx,-1);  clr(My,-1);
    while(searchP())  
    {  
        clr(vis,0);
        for(int i=0;i<Nx;i++)  
          if(Mx[i]==-1 && DFS(i)) res++;  
    }  
    return res;  
}  


