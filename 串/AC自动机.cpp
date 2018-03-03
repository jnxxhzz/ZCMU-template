/*	AC自动机 
	功能：多字符串匹配，在大量串中找模式串的子串的数量
	 原理：在建立的字典树中增加fail指针
*/ 
const int maxn=550000;  
struct AC_auto  
{  
    int chd[maxn][26],v[maxn],f[maxn],last[maxn],sz,ans;  
    void init()  
    {  
        sz=1;ans=0;  
        memset(v,0,sizeof(v));  
        memset(f,0,sizeof(f));  
        memset(chd[0],0,sizeof(chd[0]));  
    }  
    void insert(char* p)  
    {  
        int cur=0;  
        for(;*p;p++)  
        {  
            if(!chd[cur][*p-'a'])  
            {  
                memset(chd[sz],0,sizeof(chd[sz]));  
                chd[cur][*p-'a']=sz++;  
            }  
            cur=chd[cur][*p-'a'];  
        }  
        v[cur]++;  
    }  
    bool query(char* p)  
    {  
        int cur=0;  
        for(;*p;p++)  
        {  
            if(!chd[cur][*p-'a']) break;  
            cur=chd[cur][*p-'a'];  
        }  
        return v[cur]&&(!(*p));  
    }  
    int getFail()  
    {  
        queue<int> q;  
        f[0]=0;  
        for(int c=0;c<26;c++)  
        {  
            int u=chd[0][c];  
            if(u)  
            {  
                f[u]=0; q.push(u); last[u]=0;  
            }  
        }  
        while(!q.empty())  
        {  
            int r=q.front(); q.pop();  
            for(int c=0;c<26;c++)  
            {  
                int u=chd[r][c];  
                if(!u){ chd[r][c]=chd[f[r]][c];continue;}
                q.push(u);  
                int vv=f[r];  
                while(vv&&!chd[vv][c]) vv=f[vv];  
                f[u]=chd[vv][c];  
                last[u]=v[f[u]] ? f[u] : last[f[u]];  
            }  
        }  
    }  
    void solve(int j)  
    {  
        if(!j) return;  
        if(v[j])  
        {  
            ans+=v[j];  
            v[j]=0;  
        }  
        solve(last[j]);  
    }  
    void find(char* T)  
    {  
        int n=strlen(T),j=0;  
        getFail();  
        for(int i=0;i<n;i++)  
        {  
            //while(j&&!chd[j][*T-'a']) j=f[j];  
            j=chd[j][T[i]-'a'];  
            if(v[j]) solve(j);  
            else if(last[j]) solve(last[j]);  
        }  
    }  
}ac;  
int main()  
{  
    int t,n;  
    char dic[100],str[1100000];  
    scanf("%d",&t);  
    while(t--)  
    {  
        ac.init();  
        scanf("%d",&n);  
        while(n--)  
        {  
            scanf("%s",dic); //构造字典树  
            ac.insert(dic);  
        }  
        scanf("%s",str);  //str 为模式串 
        ac.find(str);     //寻找有多少个字符串是模式串的子串 
        printf("%d\n",ac.ans);  
    }  
    return 0;  
}  
