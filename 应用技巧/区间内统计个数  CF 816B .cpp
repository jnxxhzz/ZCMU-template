/*	区间增加  查询数值 
	时间复杂度：O(N)  */ 
const int MAXN=200000+100;
int n,k,q;
int l[MAXN],r[MAXN],a[MAXN]; 
int sum[MAXN];
int main()
{
	cin>>n>>k>>q;
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		l[x]++;r[y]++;
	}
	int cnt=0;
	for(int i=0;i<MAXN;i++){
		cnt+=l[i];
		a[i]=cnt;
		cnt-=r[i];
	}
	for(int i=0;i<MAXN;i++)
		a[i]-=k,sum[i]=0;
	for(int i=0;i<MAXN;i++){
		if(a[i]>=0) sum[i]++;
		if(i) sum[i]+=sum[i-1];
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",sum[y]-sum[x-1]);
	}
	return 0;
}












