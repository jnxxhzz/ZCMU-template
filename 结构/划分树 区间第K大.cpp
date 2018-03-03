//划分树：  查询区间第k大
using namespace std;
const int maxn=1e5+10;
int tree[20][maxn]; //表示每层每个位置的值
int sorted[maxn];  //已经排序好的数
int toleft[20][maxn];  //toleft[p][i]表示第i层从1到i有数分入左边
void build(int l,int r,int dep)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    int same=mid-l+1;  //表示等于中间值而且被分入左边的个数
    for(int i=l;i<=r;i++)
        if(tree[dep][i]<sorted[mid])
           same--;
    int lpos=l;
    int rpos=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(tree[dep][i]<sorted[mid])
            tree[dep+1][lpos++]=tree[dep][i];
        else if(tree[dep][i]==sorted[mid]&&same>0)
        {
            tree[dep+1][lpos++]=tree[dep][i];
            same--;
        }
        else
            tree[dep+1][rpos++]=tree[dep][i];
        toleft[dep][i]=toleft[dep][l-1]+lpos-l;
    }
    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}
//查询区间第k大的数,[L,R]是大区间，[l,r]是要查询的小区间
int query(int L,int R,int l,int r,int dep,int k)
{
    if(l==r) return tree[dep][l];
    int mid=(l+r)>>1;
    int cnt=toleft[dep][r]-toleft[dep][l-1];
    if(cnt>=k)
    {
        int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
        int newr=newl+cnt-1;
        return query(L,mid,newl,newr,dep+1,k);
    }
    else
    {
        int newr=r+toleft[dep][R]-toleft[dep][r];
        int newl=newr-(r-l-cnt);
        return query(mid+1,R,newl,newr,dep+1,k-cnt);
    }
}
int main()
{
    int n,m,cas=1;
    while(~scanf("%d",&n))
    {
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tree[0][i]);
            sorted[i]=tree[0][i];
        }
        sort(sorted+1,sorted+n+1);
        build(1,n,0);
        int s,t,k;
        printf("Case %d:\n",cas++);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&s,&t);
            k=(t-s)/2; //这边求的是中间数
            printf("%d\n",query(1,n,s,t,0,k));
        }
    }
    return 0;
}
