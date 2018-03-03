//最大团问题的快速算法
//使用64位长整型LL进行状态压缩
//！限制！：顶点数不能超过60个
//目前还存在BUG，无法解决溢出的问题，导致runtime error

int n;
vector< vector<int> > G;
class clique{
public:
    static const LL ONE=1;
    static const LL MASK=(1<<21)-1;
    char *bits;
    int n,Size,cmax[64];
    LL mask[64],cons;
    clique()
    {
        bits=new char[1<<21];
        bits[0]=0;
        for(int i=1;i< 1<<21;++i)
            bits[i]=bits[i>>1]+(i&1);
    }
    ~clique() { delete bits; }

    bool Search(int step,int Size,LL more,LL con);
    int sizeClique(vector< vector<int> > &mat);
    vector<int> consClique(vector< vector<int> > &mat);
};

bool clique::Search(int Step,int Size,LL more,LL cons)
{
    if(Step>=n)
    {
        this->Size=Size;
        this->cons=cons;
        return true;
    }
    LL now=ONE<<Step;
    if((now&more)>0)
    {
        LL next=more&mask[Step];
        if(Size+bits[next&MASK]+bits[(next>>21)&MASK]+bits[next>>42]
           >= this->Size && Size+cmax[Step] > this->Size)
            if(Search(Step+1,Size+1,next,cons|now)) return true;
    }
    LL next = more & ~now;
    if(Size+bits[next&MASK]+bits[(next>>21)&MASK]+bits[next>>42]
           >= this->Size && Size+cmax[Step] > this->Size)
        if(Search(Step+1,Size,next,cons)) return true;
    return false;
}

int clique::sizeClique(vector< vector<int> > &mat)
{
    n=mat.size();
    for(int i=0;i<n;++i)
    {
        mask[i]=0;
        for(int j=0;j<n;++j)
            if(mat[i][j]>0) mask[i]|=ONE<<j;
            	//注意: 此处是 |=
    }
    Size=0;
    for(int i=n-1;i>=0;--i)
    {
        Search(i+1,1,mask[i],ONE<<i);
        cmax[i]=Size;
    }
    return Size;
}
// 解决函数，返回最大团数组
vector<int>clique::consClique(vector< vector<int> > &mat)
{
    sizeClique(mat);
    vector<int> ret;
    for(int i=0;i<n;++i)
        if(( cons & ONE<<i ) > 0)
            ret.push_back(i);
    return ret;
}

int main()
{
	//注意vector<vector<int> > 类型的输入方法
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;i++)
		{
			vector<int> k;
			for(int j=0;j<n;j++)
			{
				int a;
				scanf("%d",&a);
				k.push_back(a);
			}
			G.push_back(k);
		}
		clique solve;
		vector<int> ans;
		ans=solve.consClique(G);
		printf("%d\n",ans.size());
	}
	return 0;
}










