#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <deque>
#include <queue>
#include <algorithm>
#include <assert.h>
using namespace std;
#define clr(a,b) memset(a, b, sizeof(a))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
typedef long long LL;
typedef vector<LL> VI;
typedef pair<int,int> PII;
const LL mod=1000000007;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
LL mod_inv(LL a, LL k) {return powmod(powmod(a, k), mod - 2) % mod;}
//freopen("test.in", "r", stdin);
//freopen("test.out", "w", stdout);
//std::ios::sync_with_stdio(false);
// head
char s[100010];
int main()
{
	int pp;scanf("%d",&pp);
	while (pp--){
		scanf("%s",s);
        int len = strlen(s);
        LL now = 0 ;
		for (int i = 0 ; i < len ; ++i){
        	now = (now * 10 + s[i] - 48) %(mod-1);
		}
		now = (now + mod - 2) % (mod - 1);
		printf("%lld\n",powmod(2,now));
    }
    return 0;
}



//卡特兰数 / 逆元 / 预处理 
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
 
int ans[1000010];
int inv[1000010];
 
int main()
{
    inv[1] = 1; for ( int i=2 ; i<1000010 ; i++ ) inv[i] = 1LL*inv[mod%i]*(mod-mod/i)%mod;
    ans[1] = 1; for ( int i=2 ; i<1000009 ; i++ ) ans[i] = 1LL*ans[i-1]*(4*i-2)%mod*inv[i+1]%mod;
    for ( int n ; scanf ( "%d" , &n )==1 ; )
    {
        printf ( "%d\n" , ans[n] );
    }
    return 0;
} 
