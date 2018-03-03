//快速幂
//参数： x 的 y 次 对 mod 取模 
LL Qpow(LL x,LL y,LL mod)
{
    LL res=1;
    x=x%mod;
    while(y>0)
    {
        if(y&1)
        res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}



