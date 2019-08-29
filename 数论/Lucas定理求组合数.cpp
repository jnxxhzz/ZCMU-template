#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;
const LL MOD=1000000007;
LL n,m;

LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= MOD;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % MOD;
            b--;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % MOD;
        LL b = i % MOD;
        ans = ans * (a * quick_mod(b, MOD-2) % MOD) % MOD;
    }
    return ans;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;
}

int main()
{
	LL ans = Lucas(4 , 2);
    return 0;
}
