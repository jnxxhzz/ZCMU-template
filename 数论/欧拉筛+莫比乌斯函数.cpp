/*	欧拉筛法（线性筛） + 莫比乌斯函数 
	功能： 在进行欧拉筛素数的同时建立莫比乌斯函数 
*/ 
int mo[MAXN];  //生成的莫比乌斯函数 
int prime[MAXN],primesize,phi[MAXN];
bool isprime[MAXN];	//筛素数的结果 
void getlist(int listsize) //筛素数的范围 
{
	mo[1]=1;
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i])prime[++primesize]=i,mo[i]=-1;
         for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
         {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)
            {
            	mo[i*prime[j]]=0;
            	break;
			}
			else mo[i*prime[j]]=-1*mo[i];
        }
    }
}


