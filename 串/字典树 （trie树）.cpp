//字典树 trie树
//定义 将大量字符串存在一棵前缀树上
//		实现对字符串的快速查找 
//时间复杂度 ：插入 O(l)  查找 O(l)
//空间复杂度 ：字符串总长度 * 字符种类数 
//特点：省时，但空间开销较大  

const int Max_node = 41000;  //大于所有字符串的长度和 
const int Sigma_size = 26;   //字符的种类数 
int ch[Max_node][Sigma_size];
int val[Max_node];
int L; 
void Init() //预处理
{ L=1; memset(ch[0],0,sizeof(ch[0])); } 
inline int idx(char c) { return c-'a'; }
//字符串换成数字的函数
void Insert(char *s, int vv)
{	//vv:该插入的字符串权值或数量,可省略,但不能为 0  
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (ch[u][c]==0) //empty
        {
            memset(ch[L],0,sizeof(ch[L]));
            val[L]=0; //not a word
            ch[u][c]=L++;
        }
        u=ch[u][c];
    }
    val[u]+=vv; //vv 必须非 0,一个字符串的结束 
}

bool Search(char *s)
{	
    int u=0, n=strlen(s);
    for (int i=0; i<n; i++)
    {
        int c=idx(s[i]);
        if (ch[u][c]==0)
            return false;
        u=ch[u][c];
    }
    if (val[u]==0) return false; 
    return true; 
}



//字典树的特殊情况  
//    查询字符串中'？'可替换任意字符或删去
//	  求满足查询的字符串个数

//方法： 递归 伸展查询字符串 
//初始化和构造字典树相同
 
char s[55];   //单个查询串的长度 
int vis[Max_node];	
//标记该字符串在该查询中是否已经用过 
int l,flag;
void Search(int now,int k)
{	//now:在字典树中的位置  
	//k:查询字符串当前处理到的位置 
	if(k==l)
	{
		if(val[now]&&vis[now]!=flag) 
		{
			ans+=val[now];
			vis[now]=flag;
		}
		return ;	
	}
	if(s[k]=='?')
	{
		Search(now,k+1); //把'？'删除继续查询 
		for(int i=0;i<5;i++) //把'？'替换成所有字符查询 
			if(ch[now][i])
				Search(ch[now][i],k+1);
	}
	else
	{
		int u=idx(s[k]);
		if(ch[now][u])
			Search(ch[now][u],k+1);
	}
}

int n,m;
int main()
{
	cin>>n>>m;
	Init();
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		Insert(s,1); 
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		l=strlen(s);
		ans=0;
		flag=i;  
		Search(0,0);
		printf("%d\n",ans);
	}
	return 0;
}

 
